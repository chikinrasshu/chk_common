#pragma once

#include <cstdint>
#include <cstddef>

#include <string>
#include <vector>

namespace chk {

    using u8 = ::std::uint8_t;
    using u16 = ::std::uint16_t;
    using u32 = ::std::uint32_t;
    using u64 = ::std::uint64_t;

    using s8 = ::std::int8_t;
    using s16 = ::std::int16_t;
    using s32 = ::std::int32_t;
    using s64 = ::std::int64_t;

    using r32 = float;
    using r64 = double;

    using umm = ::std::size_t;

    using String = ::std::string;
    using StringW = ::std::wstring;
    using StringView = ::std::string_view;

}
