#pragma once

// Unsigned int types.
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

// Signed int types.
typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

// Floating point types
typedef float f32;
typedef double f64;

// Platform detection.
#ifdef SOD_PLATFORM_WINDOWS
    #ifdef SOD_BUILD_DLL
        #define SOD_API __declspec(dllexport)
    #else
        #define SOD_API __declspec(dllimport)
    #endif
#else
    #error Sodium only supports Windows!
#endif

// Debug assertion macros.
#ifdef SOD_ENABLE_ASSERTS
    #define SOD_ASSERT(x, ...)                           \
        {                                                \
            if (!(x)) {                                  \
                SOD_ERROR(                               \
                    "Assertion Failed: {0}", __VA_ARGS__ \
                );                                       \
                __debugbreak();                          \
            }                                            \
        }
    #define SOD_CORE_ASSERT(x, ...)                      \
        {                                                \
            if (!(x)) {                                  \
                SOD_CORE_ERROR(                          \
                    "Assertion Failed: {0}", __VA_ARGS__ \
                );                                       \
                __debugbreak();                          \
            }                                            \
        }
#else
    #define SOD_ASSERT(x, ...)
    #define SOD_CORE_ASSERT(x, ...)
#endif

// Static assertion macro.
#if defined(__clang__) || defined(__gcc__)
    #define SOD_STATIC_ASSERT _Static_assert
#else
    #define SOD_STATIC_ASSERT static_assert
#endif

// Ensure that all types are of the correct size.
SOD_STATIC_ASSERT(sizeof(u8) == 1, "Expected u8 to be 1 byte.");
SOD_STATIC_ASSERT(sizeof(u16) == 2, "Expected u16 to be 2 bytes.");
SOD_STATIC_ASSERT(sizeof(u32) == 4, "Expected u32 to be 4 bytes.");
SOD_STATIC_ASSERT(sizeof(u64) == 8, "Expected u64 to be 8 bytes.");

SOD_STATIC_ASSERT(sizeof(i8) == 1, "Expected i8 to be 1 byte.");
SOD_STATIC_ASSERT(sizeof(i16) == 2, "Expected i16 to be 2 bytes.");
SOD_STATIC_ASSERT(sizeof(i32) == 4, "Expected i32 to be 4 bytes.");
SOD_STATIC_ASSERT(sizeof(i64) == 8, "Expected i64 to be 8 bytes.");

SOD_STATIC_ASSERT(sizeof(f32) == 4, "Expected f32 to be 4 bytes.");
SOD_STATIC_ASSERT(sizeof(f64) == 8, "Expected f64 to be 8 bytes.");

// Bit manipulation macros.
#define BIT(x) (1 << x)
