#ifndef RETOOLED_LOG_HPP
#define RETOOLED_LOG_HPP

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace ReTooled {

    class Log {
    public:
        static void init();

        inline static std::shared_ptr<spdlog::logger> &getCoreLogger() { return s_coreLogger; }
        inline static std::shared_ptr<spdlog::logger> &getClientLogger() { return s_clientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_coreLogger;
        static std::shared_ptr<spdlog::logger> s_clientLogger;
    };

} // ReTooled

#endif //RETOOLED_LOG_HPP
