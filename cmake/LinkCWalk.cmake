include(FetchContent)

macro(link_cwalk TARGET ACCESS TAG)
    FetchContent_Declare(
        cwalk
        GIT_REPOSITORY https://github.com/likle/cwalk
        GIT_TAG ${TAG}
        GIT_SHALLOW TRUE
    )

    FetchContent_MakeAvailable(cwalk)

    target_include_directories(${TARGET} ${ACCESS} ${chk_common_SOURCE_DIR}/include)
    target_link_libraries(${TARGET} ${ACCESS} cwalk)

    add_dependencies(${TARGET} cwalk)
endmacro()