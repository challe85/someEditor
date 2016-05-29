#include "editor.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "gui.h"
#include "randomFun.h"

editor::editor()
{

    //ctor
}


void editor::loadEditor(){

    moveActive=false;

}

void editor::update(){

}


void editor::runEditor(mouse & editMouse, sf::RenderWindow& rw){


}

void editor::startEditor(){

    std::cout << "Starting Editor: " << std::endl;




}

void editor::editObject(mouse & editMouse){


}


void editor::getObject(entity& getEntity, std::vector<entity>& entityVector) {

    setEntity=getEntity;

}



void editor::resizeObject(entity& setEntity, mouse& editMouse, sf::Vector2f& setSize){


                setEntity.mainSquare.setSize(setSize);
                //std::cout << "Resize: " << std::endl;
}

void editor::deleteObject(entity& setTmpEntity, std::vector<entity>& setTmpEntityVector){



}




void regretCreationOfLastObject(){

}





void editor::checkObject(mouse & editMouse, entity & setEntity, std::vector<entity>& entityVector){


       if(setEntity.mainSquare.getGlobalBounds().intersects(editMouse.mouseRect)){

                setEntity.mainSquare.setFillColor(sf::Color::Red);
                tmpId=setEntity.id;
                setEntity.mouseOver=true;

                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){

                setEntity.mainSquare.setPosition(editMouse.mouseRect.left-setEntity.mainSquare.getSize().x*0.5,editMouse.mouseRect.top-setEntity.mainSquare.getSize().y*0.5);


                }


           }else{
           setEntity.mainSquare.setFillColor(sf::Color::Green);
           setEntity.mouseOver=false;
           }


}

void editor::addObject(std::vector<entity>& editVector, mouse& editMouse, randomFun& editRandomFun){

entity newEntity;
newEntity.loadEntity();
newEntity.mainSquare.setPosition(editMouse.mouseRect.left,editMouse.mouseRect.top);

newEntity.mainSquare.setRotation(editRandomFun.floatRandomizer());
newEntity.gravityPosition = editRandomFun.floatVectorRandomizer();

editVector.push_back(newEntity);
//std::cout << "Box added: " << std::endl;


}


editor::~editor()
{
    //dtor
}
