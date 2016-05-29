#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "entity.h"
#include "gui.h"
#include "editor.h"
#include "visual.h"


class Game
{
    public:
        Game();

        std::vector<entity>entityVector;

        int start();
        void stop();


        //Setters
        void set_Running(bool);
        //Getters
        bool get_Running();

        virtual ~Game();
    protected:
    private:

        bool running;


};

#endif // GAME_H
