#include "re-tooled.hpp"

class ExampleGame : public ReTooled::Game {
public:
    ExampleGame() : ReTooled::Game() {
        RT_LOG_INFO("ExampleGame created");
        // register key press event listener and log the key pressed
        registerEventListener(ReTooled::EventType::KeyPressed, [](const ReTooled::EventPointer &event) {
            RT_LOG_INFO("Key pressed: {0}", static_cast<ReTooled::KeyPressedEvent *>(event.get())->getKey());
        });
    }
};

ReTooled::Game *ReTooled::createGame() {
    return new ExampleGame();
}