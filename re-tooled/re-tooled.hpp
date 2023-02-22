#ifndef RETOOLED_HPP
#define RETOOLED_HPP

#include "re-tooled/game.hpp"
#include "re-tooled/log.hpp"

#define RT_LOG_INFO(...) ::ReTooled::Log::getClientLogger()->info(__VA_ARGS__)

#include "re-tooled/entrypoint.hpp"

#endif //RETOOLED_HPP