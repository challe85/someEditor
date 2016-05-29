#ifndef RANDOMFUN_H
#define RANDOMFUN_H
#include <vector>
#include "entity.h"
#include <SFML/Graphics.hpp>
#include "editor.h"
#include "mouse.h"

class editor;

class randomFun
{
    public:
        randomFun();

        sf::Vector2f gravityPos;

        bool autoSpawnActive;
        bool autoMoveActive;

        void loadRandomFun();
        void update(editor& editEditor, mouse& editMouse, std::vector<entity>& editEntityVector, randomFun& editRandomFun);
        void randomMovement(std::vector<entity>& editEntityVector);
        void autoSpawn(editor& editEditor, mouse& editMouse, std::vector<entity>& editEntityVector, randomFun& editRandomFun);

        void anotherRandomMovement();


        void anotherAutoMove(std::vector<entity>& editEntityVector);


        sf::Vector2f floatVectorRandomizer();

        float floatRandomizer();



        int directionRandomizer();

        virtual ~randomFun();
    protected:
    private:

                 int direction;


                  //just tmp to try things out.

                 sf::Clock respawnTimer;

};

#endif // RANDOMFUN_H
