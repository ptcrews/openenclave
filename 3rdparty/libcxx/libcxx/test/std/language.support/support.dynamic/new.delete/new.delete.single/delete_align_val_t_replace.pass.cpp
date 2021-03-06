//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// test aligned operator delete replacement.

// UNSUPPORTED: sanitizer-new-delete, c++98, c++03, c++11, c++14
// Older Clang versions do not support this
// UNSUPPORTED: clang-3, apple-clang-7, apple-clang-8

// None of the current GCC compilers support this.
// UNSUPPORTED: gcc-5, gcc-6

// dylibs shipped before macosx10.13 do not provide aligned allocation, so that's a link error
// UNSUPPORTED: with_system_cxx_lib=macosx10.12
// UNSUPPORTED: with_system_cxx_lib=macosx10.11
// UNSUPPORTED: with_system_cxx_lib=macosx10.10
// UNSUPPORTED: with_system_cxx_lib=macosx10.9
// UNSUPPORTED: with_system_cxx_lib=macosx10.8
// UNSUPPORTED: with_system_cxx_lib=macosx10.7

// Using aligned allocation functions is a compiler error when deploying to
// platforms older than macosx10.13
// UNSUPPORTED: macosx10.12
// UNSUPPORTED: macosx10.11
// UNSUPPORTED: macosx10.10
// UNSUPPORTED: macosx10.9
// UNSUPPORTED: macosx10.8
// UNSUPPORTED: macosx10.7

// On Windows libc++ doesn't provide its own definitions for new/delete
// but instead depends on the ones in VCRuntime. However VCRuntime does not
// yet provide aligned new/delete definitions so this test fails to compile/link.
// XFAIL: LIBCXX-WINDOWS-FIXME

#include <new>
#include <cstddef>
#include <cstdlib>
#include <cassert>

#include "test_macros.h"

constexpr auto OverAligned = __STDCPP_DEFAULT_NEW_ALIGNMENT__ * 2;

int unsized_delete_called = 0;
int unsized_delete_nothrow_called = 0;
int aligned_delete_called = 0;

void reset() {
    unsized_delete_called = 0;
    unsized_delete_nothrow_called = 0;
    aligned_delete_called = 0;
}

void operator delete(void* p) TEST_NOEXCEPT
{
    ++unsized_delete_called;
    std::free(p);
}

void operator delete(void* p, const std::nothrow_t&) TEST_NOEXCEPT
{
    ++unsized_delete_nothrow_called;
    std::free(p);
}

void operator delete(void* p, std::align_val_t) TEST_NOEXCEPT
{
    ++aligned_delete_called;
    std::free(p);
}

struct alignas(OverAligned) A {};
struct alignas(std::max_align_t) B {};

int main()
{
    reset();
    {
        B *bp = new B;
        DoNotOptimize(bp);
        assert(0 == unsized_delete_called);
        assert(0 == unsized_delete_nothrow_called);
        assert(0 == aligned_delete_called);

        delete bp;
        DoNotOptimize(bp);
        assert(1 == unsized_delete_called);
        assert(0 == unsized_delete_nothrow_called);
        assert(0 == aligned_delete_called);
    }
    reset();
    {
        A *ap = new A;
        DoNotOptimize(ap);
        assert(0 == unsized_delete_called);
        assert(0 == unsized_delete_nothrow_called);
        assert(0 == aligned_delete_called);

        delete ap;
        DoNotOptimize(ap);
        assert(0 == unsized_delete_called);
        assert(0 == unsized_delete_nothrow_called);
        assert(1 == aligned_delete_called);
    }
}
