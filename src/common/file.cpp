#include "file.hpp"

#include <fstream>

namespace chk {

    File::File(const Path& path) : _path(path) {
        std::ifstream ifs(path, std::ios::binary | std::ios::ate);
        if (!ifs) { chk::core::error("Failed to open '{}'", path.string()); return; }

        auto end = ifs.tellg();
        ifs.seekg(0, std::ios::beg);
        auto size = std::size_t(end - ifs.tellg());

        if (size == 0) { chk::core::error("Invalid file, the size was zero"); return; }

        _memory.reserve(size);
        if(!ifs.read(reinterpret_cast<char*>(_memory.data()), _memory.size())) {
            chk::core::error("Failed to read file '{}'", path.string());
            return;
        }
    }

    File::File(void* memory, umm size): _path(""), _memory{(u8*)memory, (u8*)memory + size} {}

    File::File(List<u8> memory) : _memory{std::move(memory)} {}

    bool File::save(const Path& where) {
        if (where.empty()) { chk::core::error("No path was provided!"); return false; }

        return true;
    }

    bool File::exists(const Path& path) {
        return std::filesystem::exists(path);
    }

}
