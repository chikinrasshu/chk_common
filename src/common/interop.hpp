#pragma once

#include "types.hpp"

#define CHK_PASTER2(a, b) a ## b
#define CHK_PASTER(a, b) CHK_PASTER2(a, b)

namespace chk {
    #define CHK_INTEROP_FN(Name) void Name(chk::s32 thread_id, void* user_ptr)
    typedef CHK_INTEROP_FN(InteropFn);

    #define CHK_INTEROP_UPDATE_FN_NAME interop_update
    #define CHK_INTEROP_UPDATE_FN CHK_INTEROP_FN(CHK_INTEROP_UPDATE_FN_NAME)
    #define CHK_INTEROP_UPDATE_FN_STUB CHK_INTEROP_FN(CHK_PASTER(CHK_INTEROP_UPDATE_FN_NAME, _stub))
    CHK_INTEROP_UPDATE_FN_STUB;
    
    #define CHK_INTEROP_AUDIO_FN_NAME interop_audio
    #define CHK_INTEROP_AUDIO_FN CHK_INTEROP_FN(CHK_INTEROP_AUDIO_FN_NAME)
    #define CHK_INTEROP_AUDIO_FN_STUB CHK_INTEROP_FN(CHK_PASTER(CHK_INTEROP_AUDIO_FN_NAME, _stub))
    CHK_INTEROP_AUDIO_FN_STUB;
}
