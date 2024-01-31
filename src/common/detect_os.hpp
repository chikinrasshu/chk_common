#pragma once

#define CHK_WINDOWS 1
#define CHK_LINUX 2
#define CHK_UNIX 3
#define CHK_POSIX 4
#define CHK_MACOS 5
#define CHK_IOS 6
#define CHK_ANDROID 7

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    #define CHK_OS CHK_WINDOWS

   #ifdef _WIN64
      //define something for Windows (64-bit only)
   #else
      //define something for Windows (32-bit only)
   #endif
#elif __APPLE__
    #include <TargetConditionals.h>
    #if TARGET_IPHONE_SIMULATOR
    #define CHK_OS CHK_IOS
    #elif TARGET_OS_MACCATALYST
         // Mac's Catalyst (ports iOS API into Mac, like UIKit).
         #define CHK_OS CHK_MACOS
    #elif TARGET_OS_IPHONE
        // iOS, tvOS, or watchOS device
        #define CHK_OS CHK_IOS
    #elif TARGET_OS_MAC
        // Other kinds of Apple platforms
        #define CHK_OS CHK_MACOS
    #else
    #   error "Unknown Apple platform"
    #endif
#elif __ANDROID__
#define CHK_OS CHK_ANDROID
    // Below __linux__ check should be enough to handle Android,
    // but something may be unique to Android.
#elif __linux__
#define CHK_OS CHK_LINUX
    // linux
#elif __unix__ // all unices not caught above
#define CHK_OS CHK_UNIX
    // Unix
#elif defined(_POSIX_VERSION)
#define CHK_OS CHK_POSIX
    // POSIX
#else
#   error "Unknown platform"
#endif
