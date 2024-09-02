#include <chk_common.h>

#include <cwalk.h>

#include <stdio.h>

static char g_chk_log_buf[1024];

void chk_log_impl(const char* sender, const char* msg, const char* file,
                  u32 line, const char* func) {
    const char* short_file = file;

    struct cwk_segment seg;
    if (cwk_path_get_last_segment(file, &seg)) { short_file = seg.begin; }

    fprintf(stderr, "[%s][%s:%s:%d]: %s\n", sender, short_file, func, line,
            msg);
}

void chk_log_f_impl(const char* sender, const char* msg, const char* file,
                    u32 line, const char* func, ...) {
    va_list args;
    va_start(args, func);
    vsnprintf(g_chk_log_buf, sizeof(g_chk_log_buf), msg, args);
    va_end(args);

    chk_log_impl(sender, g_chk_log_buf, file, line, func);
}
