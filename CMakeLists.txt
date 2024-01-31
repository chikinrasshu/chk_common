cmake_minimum_required(VERSION 3.23)
project(chk_common)

if (NOT TARGET fmt::fmt)
    add_subdirectory(external/fmt)
endif()

if (NOT TARGET spdlog::spdlog)
    SET(SPDLOG_FMT_EXTERNAL ON CACHE BOOL "Use our own fmt, as it's newer and fixes some known bugs" FORCE)
    add_subdirectory(external/spdlog)
endif()

if (NOT TARGET magic_enum::magic_enum)
    add_subdirectory(external/magic_enum)
endif()

if (NOT TARGET argparse)
    add_subdirectory(external/argparse)
endif()


add_library(chk_common
    "src/common/args.hpp"
    "src/common/common.cpp"
    "src/common/common.hpp"
    "src/common/detect_os.hpp"
    "src/common/file.cpp"
    "src/common/file.hpp"
    "src/common/function.hpp"
    "src/common/interop.cpp"
    "src/common/interop.hpp"
    "src/common/list.hpp"
    "src/common/logging.cpp"
    "src/common/logging.hpp"
    "src/common/platform.hpp"
    "src/common/types.hpp"
    "src/common/utils.hpp"
)

target_link_libraries(chk_common PUBLIC fmt::fmt)
target_link_libraries(chk_common PUBLIC spdlog::spdlog)
target_link_libraries(chk_common PUBLIC magic_enum::magic_enum)
target_link_libraries(chk_common PUBLIC argparse)

target_compile_features(chk_common PRIVATE cxx_std_20)
target_include_directories(chk_common INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/src")
