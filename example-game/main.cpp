#include "re-tooled.hpp"

class ExampleGame : public ReTooled::Game {
public:
    ExampleGame() {

    }

    ~ExampleGame() {

    }
};

ReTooled::Game *ReTooled::createGame() {
    RT_LOG_INFO("ExampleGame created");
    return new ExampleGame();
}