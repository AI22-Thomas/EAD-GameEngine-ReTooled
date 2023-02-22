#ifndef RETOOLED_ENTRYPOINT_HPP
#define RETOOLED_ENTRYPOINT_HPP

#include "game.hpp"

extern ReTooled::Game *ReTooled::createGame();

int main(int argc, char **argv) {
    ReTooled::Game *game = ReTooled::createGame();
    game->run();
    delete game;
}

#endif //RETOOLED_ENTRYPOINT_HPP
