cmake_minimum_required(VERSION 3.27)
project(chk_common C)

# External dependencies
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/LinkCWalk.cmake)

# Build the launcher
set(chk_common_src "chk_common.c")
set(chk_common_hdr "chk_common.h")

list(TRANSFORM chk_common_src PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/src/")
list(TRANSFORM chk_common_hdr PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/include/")

add_library(chk_common ${chk_common_src} ${chk_common_hdr})
target_compile_features(chk_common PUBLIC c_std_11)
target_include_directories(chk_common PUBLIC "include")

link_cwalk(chk_common PRIVATE origin/master)
