#ifndef RETOOLED_LOG_HPP
#define RETOOLED_LOG_HPP

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

#define RT_LOG_INFO(...) ::ReTooled::Log::getClientLogger()->info(__VA_ARGS__)
#define RT_CORE_LOG_INFO(...) ::ReTooled::Log::getCoreLogger()->info(__VA_ARGS__)

#endif //RETOOLED_LOG_HPP
