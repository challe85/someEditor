#include "entity.h"
#include <SFML/Graphics.hpp>

entity::entity()
{
    mouseOver=false;
	onGround = false; //care

    gravityPosition.x=0;
    gravityPosition.y=0;
    //ctor
}

entity::~entity()
{
    mouseOver=false;
    //dtor
}

void entity::loadEntity(){

//LOAD SQUARE
mainSquare.setPosition(300,200);
mainSquare.setSize(sf::Vector2f(20,20));
mainSquare.setFillColor(sf::Color::Green);

//
mainSquare.setRotation(0);

}


void entity::drawEntity(sf::RenderWindow& rw){

rw.draw(mainSquare);

}
