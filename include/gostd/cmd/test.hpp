#pragma once

#include <gostd/errors.hpp>
#include <gostd/fmt.hpp>
#include <gostd/io/ioutil.hpp>
#include <gostd/os.hpp>
#include <gostd/os/exec.hpp>
#include <gostd/strconv.hpp>
#include <gostd/strings.hpp>
#include <gostd/archive/ar.hpp>
#include <gostd/debug/macho.hpp>

namespace gostd::cmd::test {

static void showUsage() {
    fmt::Fprintln(os::Stderr, "Usage: test [options] file...");
}

struct Test {
    String Symbol;
    String Name;
    bool UsesRawPointer;
};

static auto numericPrefix(String s) {
    struct { Int n = -1; String suffix; } ret;
    Int i = 0;
    while (s[i] >= '0' && s[i] <= '9') {
        i++;
    }
    if (i > 0) {
        if (auto [n, err] = strconv::ParseInt(s.Head(i), 10, 32); !err) {
            ret.n = Int(n);
            ret.suffix = s.Tail(i);
        }
    }
    return ret;
}

static Tuple<String, String> parseMangledName(String s, String s_ = "") {
    if (!strings::HasPrefix(s, "N")) {
        return {};
    }
    s = s.Tail(1);

    String name = "";

    while (true) {
        if (strings::HasPrefix(s, "I")) {
            if (auto [tParam, tSuffix] = parseMangledName(s.Tail(1), s_); tParam != "") {
                name = name + "<" + tParam + ">";
                if (!strings::HasPrefix(tSuffix, "E")) {
                    return {};
                }
                s = tSuffix.Tail(1);
                continue;
            }
            return {};
        } else if (strings::HasPrefix(s, "E")) {
            return {name, s.Tail(1)};
        } else if (strings::HasPrefix(s, "S_") && s_ != "") {
            name = s_;
            s = s.Tail(2);
        } else {
            auto [n, suffix] = numericPrefix(s);
            if (n <= 0 || n > Len(suffix)) {
                return {};
            }
            s = suffix;
            if (Len(name) > 0) {
                name = name + "::";
            }
            name = name + s.Head(n);
            s = s.Tail(n);
        }
    }
}

static auto parseSymbol(String s) {
    struct { Test test; bool ok = false; } ret;
    ret.test.Symbol = s;

    if (!strings::HasPrefix(s, "__Z")) {
        return ret;
    }
    s = s.Tail(3);

    auto [name, suffix] = parseMangledName(s);
    if (name == "" || suffix == "") {
        return ret;
    }
    s = suffix;

    if (auto colon = strings::LastIndexByte(name, ':'); !strings::HasPrefix(colon > 0 ? name.Tail(colon + 1) : name, "Test")) {
        return ret;
    }

    String s_;
    if (auto colon = strings::IndexRune(name, ':'); colon >= 0) {
        s_ = name.Head(colon);
    }

    auto isRawPointer = strings::HasPrefix(s, "P");
    if (isRawPointer) {
        s = s.Tail(1);
    }

    auto [arg, remaining] = parseMangledName(s, s_);
    if (remaining != "" || !((isRawPointer && arg == "gostd::testing::T") || (!isRawPointer && arg == "gostd::Ptr<gostd::testing::T>"))) {
        return ret;
    }

    ret.test.Name = name;
    ret.test.UsesRawPointer = isRawPointer;
    ret.ok = true;
    return ret;
}

static auto findTestsInObject(io::Reader r) {
    struct { Slice<Test> tests; Error err; } ret;

    auto [buf, err] = io::ioutil::ReadAll(r);
    if (err) {
        ret.err = err;
        return ret;
    }

    auto [macho, err2] = debug::macho::NewFile(New<bytes::Reader>(buf));
    if (err2) {
        ret.err = err2;
        return ret;
    }
    if (macho->Symtab) {
        for (Int i = 0; i < Len(macho->Symtab->Syms); i++) {
            if (auto [test, ok] = parseSymbol(macho->Symtab->Syms[i].Name); ok) {
                ret.tests = Append(ret.tests, test);
            }
        }
    }

    return ret;
}

static auto findTestsInArchive(String path) {
    struct { Slice<Test> tests; Error err; } ret;

    auto [f, err] = os::Open(path);
    if (err) {
        ret.err = err;
        return ret;
    }

    archive::ar::Reader archive(f);
    while (true) {
        auto [hdr, err] = archive.Next();
        if (err) {
            if (err != io::EOF) {
                ret.err = err;
            }
            return ret;
        }
        auto [tests, _] = findTestsInObject(&archive);
        ret.tests = Append(ret.tests, tests);
    }
}

static Error writeMainCPP(io::Writer w, Slice<Test> tests) {
    if (auto [_, err] = w.Write(Slice<Byte>(R"cpp(
        namespace gostd {
            template <typename T> struct Ptr;
            namespace testing {
                class T;
                struct testDef {
                    const char* name;
                    void(*rawPtrFunction)(T*);
                    void(*ptrFunction)(Ptr<T>);
                };
            }
        }
    )cpp")); err) {
        return err;
    }
    for (Int i = 0; i < Len(tests); i++) {
        auto ns = strings::TrimRightFunc(tests[i].Name, [](Rune r) { return r != ':'; });
        if (ns != "") {
            ns = ns.Head(Len(ns) - 2);
        }
        auto name = ns == "" ? tests[i].Name : tests[i].Name.Tail(Len(ns) + 2);
        if (auto [_, err] = w.Write(Slice<Byte>("namespace " + ns + " { void " + name + "(" + (tests[i].UsesRawPointer ? "::gostd::testing::T*" : "::gostd::Ptr<::gostd::testing::T>")+ "); }\n")); err) {
            return err;
        }
    }
    if (auto [_, err] = w.Write(Slice<Byte>(R"cpp(
        namespace gostd {
            namespace testing {
                int testMain(int, const char*[]);
                testDef tests[] = {
    )cpp")); err) {
        return err;
    }
    for (Int i = 0; i < Len(tests); i++) {
        String s = "{\"" + tests[i].Name + "\", &" + tests[i].Name + ", nullptr},\n";
        if (!tests[i].UsesRawPointer) {
            s = "{\"" + tests[i].Name + "\", nullptr, &" + tests[i].Name + "},\n";
        }
        if (auto [_, err] = w.Write(Slice<Byte>(s)); err) {
            return err;
        }
    }
    if (auto [_, err] = w.Write(Slice<Byte>("{0}};\n}}\n\nint main(int argc, const char* argv[]) { return ::gostd::testing::testMain(argc, argv); }\n")); err) {
        return err;
    }
    return {};
}

static Error compileExecutable(String output, String archive) {
    auto [tests, err] = findTestsInArchive(archive);
    if (err) {
        return err;
    }
    if (Len(tests) == 0) {
        return errors::New("no tests found");
    }

    auto [tmp, err2] = io::ioutil::TempDir();
    if (err2) {
        return err2;
    }

    auto mainCPP = path::filepath::Join(tmp, "main.cpp");

    Defer x([mainCPP=mainCPP, tmp=tmp] {
        os::Remove(mainCPP);
        os::Remove(tmp);
    });

    auto [f, err3] = os::Create(mainCPP);
    if (err3) {
        return err3;
    }
    if (auto err = writeMainCPP(f, tests); err) {
        f->Close();
        return err;
    }
    f->Close();

    if (auto err = os::exec::Command("/usr/bin/c++", "-std=c++1z", f->Name(), archive, "-o", output)->Run(); err) {
        return err;
    }

    return {};
}

static Error test(String path) {
    auto [tmp, err] = io::ioutil::TempDir();
    if (err) {
        return err;
    }

    auto testEXE = path::filepath::Join(tmp, "test");

    Defer x([testEXE=testEXE, tmp=tmp] {
        os::Remove(testEXE);
        os::Remove(tmp);
    });

    if (auto err = compileExecutable(testEXE, path); err) {
        return err;
    }

    if (auto err = os::exec::Command(testEXE)->Run(); err) {
        return err;
    }

    return {};
}

static int Run(Slice<String> args) {
    if (Len(args) >= 1) {
        if (Len(args) == 2 && args[0] == "-c") {
            if (auto err = compileExecutable("libgostd.test", args[1]); err) {
                fmt::Fprintln(os::Stderr, err);
                return 1;
            }
        } else {
            for (Int i = 0; i < Len(args); i++) {
                if (auto err = test(args[i]); err) {
                    fmt::Fprintln(os::Stderr, err);
                    return 1;
                }
            }
        }
        return 0;
    }
    showUsage();
    return 1;
}

} // namespace gostd::cmd::test
