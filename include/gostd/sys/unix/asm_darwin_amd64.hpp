#pragma once

#include <gostd.hpp>
#include <gostd/cpp.hpp>

namespace gostd::sys::unix {

static auto syscall6(cpp::uintptr_t trap, cpp::uintptr_t a1, cpp::uintptr_t a2, cpp::uintptr_t a3, cpp::uintptr_t a4, cpp::uintptr_t a5, cpp::uintptr_t a6) {
    struct {
        cpp::uintptr_t r1, r2, errno;
    } ret;
    asm(
        "movq %3, %%rax;"
        "movq %4, %%rdi;"
        "movq %5, %%rsi;"
        "movq %6, %%rdx;"
        "movq %7, %%r10;"
        "movq %8, %%r8;"
        "movq %9, %%r9;"
        "syscall;"
        "jc err%=;"
        "movq %%rax, %0;"
        "movq %%rdx, %1;"
        "movq $0, %2;"
        "jmp done%=;"
        "err%=:"
        "movq $-1, %0;"
        "movq $0, %1;"
        "movq %%rax, %2;"
        "done%=:"
        : "=m" (ret.r1), "=m" (ret.r2), "=m" (ret.errno)
        : "r" (0x2000000|trap), "m" (a1), "m" (a2), "m" (a3), "m" (a4), "m" (a5), "m" (a6)
        : "rax", "rdi", "rsi", "rdx", "r8", "r9", "r10", "rcx", "r11", "cc"
    );
    return ret;
}

} // namespace gostd::sys::unix
