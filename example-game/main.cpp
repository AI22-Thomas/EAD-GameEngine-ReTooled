#include "re-tooled.hpp"

class ExampleGame : public ReTooled::Game {
public:
    ExampleGame() {

    }

    ~ExampleGame() {

    }
};

ReTooled::Game *ReTooled::createGame() {
    return new ExampleGame();
}