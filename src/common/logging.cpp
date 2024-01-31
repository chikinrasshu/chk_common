#include "logging.hpp"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace chk {
    namespace impl {
        Logger::Logger() {
            spdlog::set_pattern("%^[%T] [%n][%s:%#]: %v%$");

            _core_logger = spdlog::stderr_color_mt("core");
            _core_logger->set_level(spdlog::level::trace);

            _user_logger = spdlog::stderr_color_mt("user");
            _user_logger->set_level(spdlog::level::trace);
        }
    }

}