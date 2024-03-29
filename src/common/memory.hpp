#pragma once

#include <memory>

namespace chk {

    template<typename T> using SharedPtr = std::shared_ptr<T>; 
    template<typename T> using UniquePtr = std::unique_ptr<T>; 
    template<typename T> using WeakPtr = std::weak_ptr<T>;

}
