#ifndef RETOOLED_GAME_HPP
#define RETOOLED_GAME_HPP

#include "event.hpp"
#include "window.hpp"

namespace ReTooled {
    class Game {
    public:
        Game();

        virtual ~Game();

        void run();

        void registerEventListener(EventType type, const std::function<ListenerType>& listener);
    private:
        bool m_running = true;

        std::unique_ptr<QueueType> m_eventQueue;
        std::unique_ptr<Window> m_window;
    };

    Game *createGame();

}


#endif //RETOOLED_GAME_HPP
