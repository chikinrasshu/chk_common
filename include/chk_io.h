#pragma once

#include <chk_common.h>

typedef struct chk_file {
    u64   size;
    void* data;
} chk_file;

bool chk_file_read(chk_file* f, const char* path);
bool chk_file_destroy(chk_file* f);
