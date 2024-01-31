#pragma once

#include "common.hpp"
#include "list.hpp"

#include <filesystem>

namespace chk {

    using Path = std::filesystem::path;

    class File {
    public:
        File(const chk::Path& path);
        File(void* memory, umm size);
        File(List<u8> memory);
        ~File() = default;

        bool save(const chk::Path& where);

        static bool exists(const chk::Path& path);

        u8* memory() { return _memory.data(); }
        const u8* memory() const { return memory(); }

        umm size() { return _memory.size(); }

        bool operator!() const { return _memory.empty(); }

    private:
        chk::Path _path;
        chk::List<u8> _memory;
    };

}