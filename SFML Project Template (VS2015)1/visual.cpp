#include "visual.h"
#include <iostream>
#include <SFML/Graphics.hpp>

visual::visual()
{
    //ctor
}

void visual::loadVisual(sf::RenderWindow& rw){


    if(!texture.loadFromFile("background2.jpg")){
    std::cout << "Couldnt load image: " << std::endl;
    }

sprite.setTexture(texture);
sprite.setPosition(0,0);
sprite.setTextureRect(sf::IntRect(10, 10, 1920, 1080));
sprite.setScale(sf::Vector2f(0.55,0.60));


}

void visual::drawVisual(sf::RenderWindow& rw){

    rw.draw(sprite);

}



visual::~visual()
{
    //dtor
}
