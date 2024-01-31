#pragma once

namespace chk {
    template<typename T> constexpr T kilobytes(T n) { return static_cast<T>(1024) * (n); }
    template<typename T> constexpr T megabytes(T n) { return static_cast<T>(1024) * chk::megabytes(n); }
    template<typename T> constexpr T gigabytes(T n) { return static_cast<T>(1024) * chk::megabytes(n); }
    template<typename T> constexpr T terabytes(T n) { return static_cast<T>(1024) * chk::gigabytes(n); }
}
