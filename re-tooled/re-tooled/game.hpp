#ifndef RETOOLED_GAME_HPP
#define RETOOLED_GAME_HPP


namespace ReTooled {
    class Game {
    public:
        Game();

        virtual ~Game();

        void run();
    };

    Game *createGame();
}


#endif //RETOOLED_GAME_HPP
