#ifndef RETOOLED_ENTRYPOINT_HPP
#define RETOOLED_ENTRYPOINT_HPP

#include "game.hpp"
#include "log.hpp"

extern ReTooled::Game *ReTooled::createGame();

int main(int argc, char **argv) {
    ReTooled::Log::init();

    ReTooled::Game *game = ReTooled::createGame();
    game->run();
    delete game;
}

#endif //RETOOLED_ENTRYPOINT_HPP
