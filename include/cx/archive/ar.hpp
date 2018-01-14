#pragma once

#include <cx/io.hpp>
#include <cx/io/ioutil.hpp>
#include <cx/errors.hpp>
#include <cx/time.hpp>
#include <cx/strconv.hpp>
#include <cx/strings.hpp>

namespace cx::archive::ar {

struct Header {
    String Name;
    time::Time ModTime;
    Int Uid;
    Int Gid;
    Int64 Mode;
    Int64 Size;
};

class Reader {
public:
    Reader(io::Reader r) : _r{r} {}

    struct NextResult {
        Ptr<Header> header;
        Error err;
    };

    NextResult Next() {
        if (_err) {
            return {{}, _err};
        }
        auto [header, err] = _next();
        if (err) {
            _err = err;
        }
        return {header, err};
    }

private:
    io::Reader _r;
    bool _didReadArchiveHeader = false;
    Int64 _unread = 0;
    Error _err;

    Error _readArchiveHeader() {
        const char expected[] = "!<arch>\n";
        Slice<Byte> buf(sizeof(expected) - 1);
        if (auto [n, err] = io::ReadFull(_r, buf); err) {
            return err;
        }
        if (String(buf) != expected) {
            return errors::New("not an archive: bad header");
        }
        _didReadArchiveHeader = true;
        return {};
    }

    Error _skipUnread() {
        if (!_unread) { return {}; }

        // TODO: optimize for io.Seeker

        auto [skipped, err] = io::CopyN(io::ioutil::Discard, _r, _unread);
        _unread -= skipped;
        if (skipped < _unread) {
            return err;
        }
        return {};
    }

    NextResult _next() {
        if (!_didReadArchiveHeader) {
            if (auto err = _readArchiveHeader(); err) {
                return {{}, err};
            }
        } else if (_unread > 0) {
            if (auto err = _skipUnread(); err) {
                return {{}, err};
            }
        }

        Slice<Byte> buf(16 + 12 + 6 + 6 + 8 + 10 + 1 + 1);

        if (auto [n, err] = io::ReadFull(_r, buf); err) {
            return {{}, err};
        }

        if (buf[buf.Len()-2] != '`' || buf[buf.Len()-1] != '\n') {
            return {{}, errors::New("bad entry")};
        }

        auto str = String(buf);

        auto header = New<Header>();

        header->Name = strings::TrimRight(str.Head(16), " ");
        str = str.Tail(16);

        if (auto [n, err] = strconv::ParseInt(strings::TrimRight(str.Head(12), " "), 10, 64); err) {
            return {{}, errors::New("unable to parse mod time")};
        } else {
            header->ModTime = time::Unix(n, 0);
            str = str.Tail(12);
        }

        if (auto [n, err] = strconv::ParseInt(strings::TrimRight(str.Head(6), " "), 10, 32); err) {
            return {{}, errors::New("unable to parse uid")};
        } else {
            header->Uid = n;
            str = str.Tail(6);
        }

        if (auto [n, err] = strconv::ParseInt(strings::TrimRight(str.Head(6), " "), 10, 32); err) {
            return {{}, errors::New("unable to parse gid")};
        } else {
            header->Gid = n;
            str = str.Tail(6);
        }

        if (auto [n, err] = strconv::ParseUint(strings::TrimRight(str.Head(8), " "), 8, 32); err) {
            return {{}, errors::New("unable to parse mode")};
        } else {
            header->Mode = n;
            str = str.Tail(8);
        }

        if (auto [n, err] = strconv::ParseInt(strings::TrimRight(str.Head(10), " "), 10, 64); err) {
            return {{}, errors::New("unable to parse size")};
        } else {
            header->Size = n;
            str = str.Tail(10);
        }

        _unread = header->Size;
        return {header, {}};
    }
};

} // namespace cx::archive::ar