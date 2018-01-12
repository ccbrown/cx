#pragma once

#include <cx.hpp>
#include <cx/os.hpp>

namespace cx::fmt {

template <typename T>
static String uitoa(T v) {
    char buf[32];
    auto i = sizeof(buf) - 1;
    while (v >= 10) {
        buf[i] = v%10 + '0';
        --i;
        v /= 10;
    }
    buf[i] = v + '0';
    return buf + i;
}

template <typename T>
static String itoa(T v) {
    if (v < 0) {
        return "-" + uitoa(-v);
    }
    return uitoa(v);
}

template <typename T>
String sprintArg(T arg) {
    return String(arg);
}

String sprintArg(Int arg) { return itoa(arg); }

String Sprint() {
    return "";
}

template <typename Arg, typename... Args>
String Sprint(Arg arg, Args... args) {
    auto ret = sprintArg(arg);
    if (sizeof...(args) > 0) {
        ret = ret + " ";
    }
    return ret + Sprint(args...);
}

template <typename Writer, typename... Args>
auto Fprint(Writer w, Args... args) {
    return w.Write(Slice<Byte>(Sprint(args...)));
}

template <typename... Args>
auto Print(Args... args) {
    return Fprint(os::Stdout, args...);
}

template <typename Writer, typename... Args>
auto Fprintln(Writer w, Args... args) {
    struct { int n; Error err; } ret;
    auto [n, err] = Print(args...);
    ret.n = n;
    ret.err = err;
    if (!err) {
        auto [n, err] = Print("\n");
        ret.n += n;
        ret.err = err;
    }
    return ret;
}

template <typename... Args>
auto Println(Args... args) {
    return Fprintln(os::Stdout, args...);
}

} // namespace cx::fmt
