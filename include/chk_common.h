#pragma once

#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t  s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef float  f32;
typedef double f64;

#define chk_log(sender, msg)                                                   \
    chk_log_impl((sender), (msg), __FILE__, __LINE__, __func__);
#define chk_log_f(sender, msg, ...)                                            \
    chk_log_f_impl((sender), (msg), __FILE__, __LINE__, __func__, __VA_ARGS__);

void chk_log_impl(const char* sender, const char* msg, const char* file,
                  u32 line, const char* func);
void chk_log_f_impl(const char* sender, const char* msg, const char* file,
                    u32 line, const char* func, ...);
