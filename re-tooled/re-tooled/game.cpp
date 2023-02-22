#include <iostream>
#include "game.hpp"

namespace ReTooled {
    Game::Game() {
        eventQueue = new QueueType();
    }

    Game::~Game() {
        delete eventQueue;
    }

    void Game::run() {

        // Create test event
        eventQueue->enqueue(KeyboardEvent{10});

        while (true) {
            // Process events
            eventQueue->process();

            // Stop the game for now
            break;
        }
    }

    void Game::registerEventListener(EventType type, ListenerType listener) {
        eventQueue->appendListener(type, listener);
    }
}