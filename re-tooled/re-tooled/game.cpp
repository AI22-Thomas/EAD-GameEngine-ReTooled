#include "game.hpp"
#include "rendering/glfw-window.hpp"

namespace ReTooled {
    Game::Game() {
        m_eventQueue = std::make_unique<QueueType>();

        // For now instantiate a GLFW window, can be abstracted away to other rendering APIs
        m_window = std::make_unique<GFLWWindow>();

        m_window->setEventCallback([this](const EventPointer &event) {
            m_eventQueue->dispatch(event);
        });

        registerEventListener(ReTooled::EventType::WindowClose, [this](const EventPointer &event) {
            m_running = false;
        });
    }

    Game::~Game() {
    }

    void Game::run() {
        while (m_running) {
            m_window->update();
            // Process events
            m_eventQueue->process();
        }
    }

    void Game::registerEventListener(EventType type, const std::function<ListenerType>& listener) {
        m_eventQueue->appendListener(type, listener);
    }
}