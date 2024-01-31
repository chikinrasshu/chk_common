#pragma once

#include "common.hpp"
#include "detect_os.hpp"

#if CHK_OS == CHK_WINDOWS

#define WIN32_LEAN_AND_MEAN 1
#define VC_EXTRALEAN 1
#define NOMINMAX 1
#include <Windows.h>
#undef near
#undef far

#elif CHK_OS == CHK_MACOS

#error "Unimplemented!";

#elif CHK_OS == CHK_LINUX

#error "Unimplemented!";

#else
#error "Unsupported platform!"
#endif