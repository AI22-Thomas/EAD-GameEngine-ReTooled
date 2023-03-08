#include "re-tooled.hpp"

class ExampleGame : public ReTooled::Game {
public:
    ExampleGame() : ReTooled::Game() {
        RT_LOG_INFO("ExampleGame created");
        registerEventListener(ReTooled::EventType::Keyboard, [](const ReTooled::EventPointer & event) {
            const auto *keyboardEvent = static_cast<const ReTooled::KeyboardEvent *>(event.get());
            RT_LOG_INFO("KeyboardEvent: {}", keyboardEvent->getKey());
        });
    }
};

ReTooled::Game *ReTooled::createGame() {
    return new ExampleGame();
}