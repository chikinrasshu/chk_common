#pragma once

#include <functional>

namespace chk {

    template<typename T> using Fn = std::function<T>;
    
    template<typename T = void()> using CallbackT = Fn<T>;
    using Callback = CallbackT<void()>;

}
