#include <chk_io.h>

#include <cwalk.h>

#include <stdio.h>

static char g_chk_file_buf[1024];

bool chk_file_read(chk_file* f, const char* path) {
    assert(f != NULL);
    assert(f->data = NULL);
    assert(f->size = 0);

    FILE* fptr = fopen(path, "rb");
    if (fptr) {
        fseek(fptr, 0, SEEK_END);
        f->size = ftell(fptr);
        fseek(fptr, 0, SEEK_SET);

        f->data = malloc(f->size);
        if (f->data) {
            if (fread(f->data, f->size, 1, fptr) != 1) {
                free(f->data);
                f->data = NULL;
                f->size = 0;
            }
        }

        fclose(fptr);
    }

    return f->data != NULL && f->size > 0;
}

bool chk_file_destroy(chk_file* f) {
    assert(f != NULL);
    assert(f->data != NULL);
    assert(f->size > 0);

    free(f->data);
    f->data = NULL;
    f->size = 0;

    return true;
}
