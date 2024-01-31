#pragma once

#include <argparse/argparse.hpp>

namespace chk {

    using Args = argparse::Args;

    template<class T> T parse_args(chk::s32 argc, const char* const *argv, const bool &raise_on_error=false) {
        T args = T();
        args.parse(argc, argv, raise_on_error);
        return args;
    }

}