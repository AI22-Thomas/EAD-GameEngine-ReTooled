#ifndef RETOOLED_GAME_HPP
#define RETOOLED_GAME_HPP

#include "event.hpp"

namespace ReTooled {
    class Game {
    public:
        Game();

        virtual ~Game();

        void run();

        void registerEventListener(EventType type, ListenerType listener);
    private:
        QueueType *eventQueue;
    };

    Game *createGame();

}


#endif //RETOOLED_GAME_HPP
