#pragma once

#include "memory.hpp"
#include "types.hpp"

#include <spdlog/spdlog.h>

#ifdef __cpp_lib_source_location
#include <source_location>
using source_location = std::source_location;
#else
#include <experimental/source_location>
using source_location = std::experimental::source_location;
#endif

namespace chk {
    namespace impl {
        class Logger {
        public:
            static Logger& get() {
                static Logger instance;
                return instance;
            }

            Logger(Logger const&) = delete;
            void operator=(Logger const&) = delete;

            static SharedPtr<spdlog::logger> core() { return get()._core_logger; }
            static SharedPtr<spdlog::logger> user() { return get()._user_logger; }

        private:
            Logger();

            SharedPtr<spdlog::logger> _core_logger = nullptr;
            SharedPtr<spdlog::logger> _user_logger = nullptr;
        };
    }

    [[nodiscard]] constexpr auto get_log_source_location(const source_location& loc) { 
        return ::spdlog::source_loc{loc.file_name(), static_cast<chk::s32>(loc.line()), loc.function_name()}; 
    }

    struct StringFmt {
        StringView val;
        ::spdlog::source_loc loc;
        
        template<typename S> 
        StringFmt(const S& s, const source_location& loc = source_location::current()) 
            : val{s}, loc{get_log_source_location(loc)} {}
    };

    namespace core {
        template<typename... T> 
        void log(StringFmt str, T&&... args) {
            auto logger = impl::Logger::core();
            logger->log(str.loc, spdlog::level::trace, fmt::runtime(str.val), std::forward<T>(args)...);
        }

        template<typename... T> 
        void warn(StringFmt str, T&&... args) {
            auto logger = impl::Logger::core();
            logger->log(str.loc, spdlog::level::warn, fmt::runtime(str.val), std::forward<T>(args)...);
        }

        template<typename... T> 
        void error(StringFmt str, T&&... args) {
            auto logger = impl::Logger::core();
            logger->log(str.loc, spdlog::level::err, fmt::runtime(str.val), std::forward<T>(args)...);
        }
    }

    namespace user {
        template<typename... T> 
        void log(StringFmt fmt, T&&... args) {
            auto logger = impl::Logger::user();
            logger->log(fmt.loc, spdlog::level::trace, fmt::runtime(fmt.val), std::forward<T>(args)...);
        }

        template<typename... T> 
        void warn(StringFmt str, T&&... args) {
            auto logger = impl::Logger::user();
            logger->log(str.loc, spdlog::level::warn, fmt::runtime(str.val), std::forward<T>(args)...);
        }

        template<typename... T> 
        void error(StringFmt str, T&&... args) {
            auto logger = impl::Logger::user();
            logger->log(str.loc, spdlog::level::err, fmt::runtime(str.val), std::forward<T>(args)...);
        }
    }

}
