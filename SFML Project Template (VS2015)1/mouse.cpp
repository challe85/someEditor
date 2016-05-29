#include "mouse.h"
#include <iostream>

mouse::mouse()
{
    //ctor
}

bool mouse::mouseIntersect(){


return true;
}

bool mouse::rightClick(){

    if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
    return true;
    }

return false;
}

bool mouse::leftClick(){

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
    return true;
    }

return false;
}

void mouse::mousePosition(sf::RenderWindow& rw){

    sf::Mouse::getPosition(rw);
    worldPos=rw.mapPixelToCoords(pixelPos);


    pixelPos.x=sf::Mouse::getPosition(rw).x;
    pixelPos.y=sf::Mouse::getPosition(rw).y;

    mouseRect.height=4;
    mouseRect.width=4;
    mouseRect.left=pixelPos.x;
    mouseRect.top=pixelPos.y;

    if(pixelPos.x!=mouseXyBuffer.x || pixelPos.y!=mouseXyBuffer.y ){
//    std::cout << "X " << pixelPos.x << " " << "Y: " << pixelPos.y << std::endl;
    }

    if(mouseXy!=mouseXyBuffer){

    }

    mouseXyBuffer.x=pixelPos.x;
    mouseXyBuffer.y=pixelPos.y;
}


mouse::~mouse()
{
    //dtor
}
