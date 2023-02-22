#include "re-tooled.hpp"

class ExampleGame : public ReTooled::Game {
public:
    ExampleGame() : ReTooled::Game() {
        RT_LOG_INFO("ExampleGame created");
        registerEventListener(ReTooled::EventType::Keyboard, [](const ReTooled::Event & event) {
            const ReTooled::KeyboardEvent keyboardEvent = (ReTooled::KeyboardEvent &&) event;
            ReTooled::Log::getClientLogger()->info("KeyboardEvent: %d", keyboardEvent.getKey());
        });
    }
};

ReTooled::Game *ReTooled::createGame() {
    return new ExampleGame();
}