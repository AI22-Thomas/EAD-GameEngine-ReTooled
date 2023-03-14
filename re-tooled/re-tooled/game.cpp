#include "game.hpp"

namespace ReTooled {
    Game::Game() {
        m_eventQueue = new QueueType();
        m_window = new Window("ReTooled", 800, 600);
        m_window->setEventCallback(std::bind(&Game::onEvent, this, std::placeholders::_1));
    }

    Game::~Game() {
        delete m_eventQueue;
        delete m_window;
    }

    void Game::run() {
        while (!m_window->closed()) {
            m_window->update();
            // Process events
            m_eventQueue->process();
        }
    }

    void Game::registerEventListener(EventType type, ListenerType listener) {
        m_eventQueue->appendListener(type, listener);
    }

    void Game::onEvent(const EventPointer &event) {
        m_eventQueue->dispatch(event);
    }
}