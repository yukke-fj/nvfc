// RUN: %clang_cc1 -emit-llvm -o - %s | FileCheck %s

struct Global { Global(); };
template<typename T> struct X { X(); };


namespace {
  struct Anon { Anon(); };

  // CHECK: @_ZN12_GLOBAL__N_15anon0E = internal global
  Global anon0;
}

// CHECK: @anon1 = internal global
Anon anon1;

// CHECK: @anon2 = internal global
X<Anon> anon2;

// rdar: // 8071804
char const * const xyzzy = "Hello, world!";
extern char const * const xyzzy;

char const * const *test1()
{
   // CHECK: @_ZL5xyzzy = internal constant
    return &xyzzy;
}

static char const * const static_xyzzy = "Hello, world!";
extern char const * const static_xyzzy;

char const * const *test2()
{
    // CHECK: @_ZL12static_xyzzy = internal constant
    return &static_xyzzy;
}

static char const * static_nonconst_xyzzy = "Hello, world!";
extern char const * static_nonconst_xyzzy;

char const * *test3()
{
    // CHECK: @_ZL21static_nonconst_xyzzy = internal global
    return &static_nonconst_xyzzy;
}


char const * extern_nonconst_xyzzy = "Hello, world!";
extern char const * extern_nonconst_xyzzy;

char const * *test4()
{
    // CHECK: @extern_nonconst_xyzzy = global
    return &extern_nonconst_xyzzy;
}
