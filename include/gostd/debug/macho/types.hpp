#pragma once

namespace gostd::debug::macho {

struct cpu {};
using Cpu = Uint32::Type<cpu>;

struct type {};
using Type = Uint32::Type<type>;

constexpr auto Magic32  = UntypedConstant(0xfeedface);
constexpr auto Magic64  = UntypedConstant(0xfeedfacf);
constexpr auto MagicFat = UntypedConstant(0xcafebabe);

struct FileHeader {
    Uint32 Magic;
    Cpu Cpu;
    Uint32 SubCpu;
    Type Type;
    Uint32 Ncmd;
    Uint32 Cmdsz;
    Uint32 Flags;
};

constexpr auto fileHeaderSize32 = UntypedConstant(7 * 4);
constexpr auto fileHeaderSize64 = UntypedConstant(8 * 4);

struct loadCmd {};
using LoadCmd = Uint32::Type<loadCmd>;

constexpr LoadCmd LoadCmdSegment    = LoadCmd(1);
constexpr LoadCmd LoadCmdSymtab     = LoadCmd(2);
constexpr LoadCmd LoadCmdThread     = LoadCmd(4);
constexpr LoadCmd LoadCmdUnixThread = LoadCmd(5);
constexpr LoadCmd LoadCmdDysymtab   = LoadCmd(11);
constexpr LoadCmd LoadCmdDylib      = LoadCmd(12);
constexpr LoadCmd LoadCmdDylinker   = LoadCmd(15);
constexpr LoadCmd LoadCmdSegment64  = LoadCmd(25);

struct Nlist32 {
    Uint32 Name;
    Uint8 Type;
    Uint8 Sect;
    Uint16 Desc;
    Uint32 Value;
};

struct Nlist64 {
    Uint32 Name;
    Uint8 Type;
    Uint8 Sect;
    Uint16 Desc;
    Uint64 Value;
};

struct Symbol {
    String Name;
    Uint8 Type;
    Uint8 Sect;
    Uint16 Desc;
    Uint64 Value;
};

struct Symtab {
    Slice<Symbol> Syms;
};

struct SymtabCmd {
    LoadCmd Cmd;
    Uint32 Len;
    Uint32 Symoff;
    Uint32 Nsyms;
    Uint32 Stroff;
    Uint32 Strsize;
};

} // namespace gostd::debug::macho
