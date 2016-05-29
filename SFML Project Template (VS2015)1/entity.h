#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "entity.h"


class entity
{
    public:
        entity();

        sf::RectangleShape mainSquare;

        int id;
        bool mouseOver;
        bool highLighted;
        std::vector<entity>::iterator storedItr;

        sf::Vector2f gravityPosition;


        void loadEntity();

        void drawEntity(sf::RenderWindow&);

        virtual ~entity();
    protected:
    private:

};

#endif // ENTITY_H
