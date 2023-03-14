#ifndef RETOOLED_GAME_HPP
#define RETOOLED_GAME_HPP

#include "event.hpp"
#include "log.hpp"
#include "window.hpp"

namespace ReTooled {
    class Game {
    public:
        Game();

        virtual ~Game();

        void run();

        void registerEventListener(EventType type, ListenerType listener);
    private:
        void onEvent(const EventPointer &event);
        QueueType *m_eventQueue;
        Window *m_window;
    };

    Game *createGame();

}


#endif //RETOOLED_GAME_HPP
