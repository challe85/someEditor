#include "gui.h"
#include <iostream>
#include "editor.h"
#include <string>
#include <sstream>


gui::gui()
{


    //ctor
}

std::string toString(int32_t integer){

    char numstr[10];
    sprintf_s(numstr, "%i", integer);
    return numstr;

}


void gui::loadGui(){

    if(!font.loadFromFile("OpenSans-bold.ttf")){
    std::cout << "Cant load font" << std::endl;
    }


    rightClick=false;
    leftClick=false;
    clicked=false;
    setMenuStaticPosition=false;
    hideMenu=false;

    menuHidePos.x=1000.f;
    menuHidePos.y=1000.f;


    text.setFont(font);
    text.setCharacterSize(30);
    text.setStyle(sf::Text::Regular);
    text.setString("Some game editor");
    text.setPosition(250,0);

    //Entity counter text
    entityCountText.setFont(font);
    entityCountText.setCharacterSize(15);
    entityCountText.setStyle(sf::Text::Regular);
    entityCountText.setString("Entities: ");
    entityCountText.setPosition(590,15);
    //End

    //Entity counter Value
    entityCountTextCounter.setFont(font);
    entityCountTextCounter.setCharacterSize(35);
    entityCountTextCounter.setStyle(sf::Text::Regular);
    entityCountTextCounter.setString(" ");
    entityCountTextCounter.setPosition(655,0);
    //end


    //Mouse pos text
    mousePosText.setFont(font);
    mousePosText.setCharacterSize(15);
    mousePosText.setStyle(sf::Text::Regular);
    mousePosText.setString("Mouse pos XY: ");
    mousePosText.setPosition(30,550);
    //end

    //Mouse pos Value X
    mousePosTextValueX.setFont(font);
    mousePosTextValueX.setCharacterSize(15);
    mousePosTextValueX.setStyle(sf::Text::Regular);
    mousePosTextValueX.setString(" ");
    mousePosTextValueX.setPosition(150,550);
    //end

    //Mouse pos Value Y
    mousePosTextValueY.setFont(font);
    mousePosTextValueY.setCharacterSize(15);
    mousePosTextValueY.setStyle(sf::Text::Regular);
    mousePosTextValueY.setString(" ");
    mousePosTextValueY.setPosition(190,550);
    //end




//Menu box
rightClickMenuBox.setFillColor(sf::Color::White);
rightClickMenuBox.setSize(sf::Vector2f(100,200));
rightClickMenuBox.setPosition(storedMenuPosition.x,storedMenuPosition.y);

//Size box
rightClickMenuInternalBox.setFillColor(sf::Color::Blue);
rightClickMenuInternalBox.setSize(sf::Vector2f(100,20));
rightClickMenuInternalBox.setPosition(rightClickMenuBox.getPosition().x,rightClickMenuBox.getPosition().y+20); //pos of background.
//Size Text
boxTextSize.setFont(font);
boxTextSize.setColor(sf::Color::Black);
boxTextSize.setPosition(rightClickMenuInternalBox.getPosition().x,rightClickMenuInternalBox.getPosition().y);
boxTextSize.setCharacterSize(15);
boxTextSize.setStyle(sf::Text::Regular);
boxTextSize.setString("Size");

//Move box
rightClickMenuInternalBox2.setFillColor(sf::Color::Magenta);
rightClickMenuInternalBox2.setSize(sf::Vector2f(100,20));
rightClickMenuInternalBox2.setPosition(rightClickMenuInternalBox.getPosition().x,rightClickMenuInternalBox.getPosition().y+20);
//Move text
boxTextMove.setFont(font);
boxTextMove.setColor(sf::Color::Black);
boxTextMove.setPosition(rightClickMenuInternalBox2.getPosition().x,rightClickMenuInternalBox2.getPosition().y);
boxTextMove.setCharacterSize(15);
boxTextMove.setStyle(sf::Text::Regular);
boxTextMove.setString("Move");

//Add box
rightClickMenuInternalBox3.setFillColor(sf::Color::Red);
rightClickMenuInternalBox3.setSize(sf::Vector2f(100,20));
rightClickMenuInternalBox3.setPosition(rightClickMenuInternalBox2.getPosition().x,rightClickMenuInternalBox2.getPosition().y+20);
//Add text
boxTextAdd.setFont(font);
boxTextAdd.setColor(sf::Color::Black);
boxTextAdd.setPosition(rightClickMenuInternalBox3.getPosition().x,rightClickMenuInternalBox3.getPosition().y);
boxTextAdd.setCharacterSize(15);
boxTextAdd.setStyle(sf::Text::Regular);
boxTextAdd.setString("Add");

//Subtract box
rightClickMenuInternalBox4.setFillColor(sf::Color::Yellow);
rightClickMenuInternalBox4.setSize(sf::Vector2f(100,20));
rightClickMenuInternalBox4.setPosition(rightClickMenuInternalBox3.getPosition().x,rightClickMenuInternalBox3.getPosition().y+20);
//Subtract text
boxTextSubtract.setFont(font);
boxTextSubtract.setColor(sf::Color::Black);
boxTextSubtract.setPosition(rightClickMenuInternalBox4.getPosition().x,rightClickMenuInternalBox4.getPosition().y);
boxTextSubtract.setCharacterSize(15);
boxTextSubtract.setStyle(sf::Text::Regular);
boxTextSubtract.setString("Subtract");

//AutoSpawn box
rightClickMenuInternalBox5.setFillColor(sf::Color::Green);
rightClickMenuInternalBox5.setSize(sf::Vector2f(100,20));
rightClickMenuInternalBox5.setPosition(rightClickMenuInternalBox4.getPosition().x,rightClickMenuInternalBox4.getPosition().y+20);
//AutoSpawn text
boxTextAutoSpawn.setFont(font);
boxTextAutoSpawn.setColor(sf::Color::Black);
boxTextAutoSpawn.setPosition(rightClickMenuInternalBox5.getPosition().x, rightClickMenuInternalBox5.getPosition().y);
boxTextAutoSpawn.setCharacterSize(15);
boxTextAutoSpawn.setStyle(sf::Text::Regular);
boxTextAutoSpawn.setString("AutoSpawn");

//AutoMove box
rightClickMenuInternalBox6.setFillColor(sf::Color::Cyan);
rightClickMenuInternalBox6.setSize(sf::Vector2f(100,20));
rightClickMenuInternalBox6.setPosition(rightClickMenuInternalBox5.getPosition().x,rightClickMenuInternalBox5.getPosition().y+20);

//AutoMove text
boxTextAutoMove.setFont(font);
boxTextAutoMove.setColor(sf::Color::Black);
boxTextAutoMove.setPosition(rightClickMenuInternalBox6.getPosition().x,rightClickMenuInternalBox6.getPosition().y);
boxTextAutoMove.setCharacterSize(15);
boxTextAutoMove.setStyle(sf::Text::Regular);
boxTextAutoMove.setString("AutoMove");



//sizeSliderBox
sliderMoveableBox.setFillColor(sf::Color::Blue);
sliderMoveableBox.setSize(sf::Vector2f(40,20));
sliderMoveableBox.setPosition(700,200);

//sizeSliderVeticalBox
sliderVerticalBox.setFillColor(sf::Color::White);
sliderVerticalBox.setSize(sf::Vector2f(5,300));
sliderVerticalBox.setPosition(717,80);

//sizeSlider Text
sliderText.setFont(font);
sliderText.setColor(sf::Color::White);
sliderText.setPosition(675, 50); //sliderText.setPosition(sliderMoveableBox.getPosition().x,sliderMoveableBox.getPosition().y);
sliderText.setCharacterSize(20);
sliderText.setStyle(sf::Text::Regular);
sliderText.setString("Size slider");  //hmm


}

void gui::drawGui(sf::RenderWindow &rw, mouse& editMouse){

rw.draw(text);
rw.draw(entityCountTextCounter);
rw.draw(entityCountText);
rw.draw(mousePosText);
rw.draw(mousePosTextValueX);
rw.draw(mousePosTextValueY);
rw.draw(sliderText);
rw.draw(sliderVerticalBox);
rw.draw(sliderMoveableBox);

        if(setMenuStaticPosition){
    rw.draw(rightClickMenuBox);
    rw.draw(rightClickMenuInternalBox);
    rw.draw(rightClickMenuInternalBox2);
    rw.draw(rightClickMenuInternalBox3);
    rw.draw(rightClickMenuInternalBox4);
    rw.draw(rightClickMenuInternalBox5);
    rw.draw(rightClickMenuInternalBox6);
    rw.draw(boxTextMove);
    rw.draw(boxTextSize);
    rw.draw(boxTextAdd);
    rw.draw(boxTextSubtract);
    rw.draw(boxTextAutoSpawn);
    rw.draw(boxTextAutoMove);
        }
}

void gui::update(mouse& editMouse, std::vector<entity>& editEntityVector){

    if(editMouse.rightClick()){

        setMenuStaticPosition=true;
        hideMenu=false;

        setMenuPosition(editMouse);

        rightClickMenuBox.setPosition(storedMenuPosition.x,storedMenuPosition.y);
        rightClickMenuInternalBox.setPosition(storedMenuPosition.x,storedMenuPosition.y+20);
        rightClickMenuInternalBox2.setPosition(rightClickMenuInternalBox.getPosition().x,rightClickMenuInternalBox.getPosition().y+rightClickMenuInternalBox.getSize().y); //Make them follow eachother as before or set values based on size hmm..
        rightClickMenuInternalBox3.setPosition(rightClickMenuInternalBox2.getPosition().x,rightClickMenuInternalBox2.getPosition().y+rightClickMenuInternalBox2.getSize().y);
        rightClickMenuInternalBox4.setPosition(rightClickMenuInternalBox3.getPosition().x,rightClickMenuInternalBox3.getPosition().y+rightClickMenuInternalBox3.getSize().y);
        rightClickMenuInternalBox5.setPosition(rightClickMenuInternalBox4.getPosition().x,rightClickMenuInternalBox4.getPosition().y+rightClickMenuInternalBox4.getSize().y);
        rightClickMenuInternalBox6.setPosition(rightClickMenuInternalBox5.getPosition().x,rightClickMenuInternalBox5.getPosition().y+rightClickMenuInternalBox5.getSize().y);

        boxTextMove.setPosition(rightClickMenuInternalBox.getPosition().x, rightClickMenuInternalBox.getPosition().y);
        boxTextSize.setPosition(rightClickMenuInternalBox2.getPosition().x, rightClickMenuInternalBox2.getPosition().y);
        boxTextAdd.setPosition(rightClickMenuInternalBox3.getPosition().x, rightClickMenuInternalBox3.getPosition().y);
        boxTextSubtract.setPosition(rightClickMenuInternalBox4.getPosition().x, rightClickMenuInternalBox4.getPosition().y);
        boxTextAutoSpawn.setPosition(rightClickMenuInternalBox5.getPosition().x, rightClickMenuInternalBox5.getPosition().y);
        boxTextAutoMove.setPosition(rightClickMenuInternalBox6.getPosition().x, rightClickMenuInternalBox6.getPosition().y);

    }

            //Entity counter convert
            tmpInt=editEntityVector.size();
            entityCountTextCounter.setString(toString(tmpInt));
            //End

            //MousePosValueConverter
            convertedMousePosX = editMouse.mouseRect.left;
            convertedMousePosY = editMouse.mouseRect.top;
            mousePosTextValueX.setString(toString(convertedMousePosX));
            mousePosTextValueY.setString(toString(convertedMousePosY));
            //End



            if(editMouse.leftClick()){
            setMenuStaticPosition=false;
            hideMenu=true;
            }

                if(hideMenu){
                rightClickMenuBox.setPosition(menuHidePos.x,menuHidePos.y);
                rightClickMenuInternalBox.setPosition(menuHidePos.x,menuHidePos.y+20);
                rightClickMenuInternalBox2.setPosition(menuHidePos.x,menuHidePos.y+rightClickMenuInternalBox.getSize().y);
                rightClickMenuInternalBox3.setPosition(menuHidePos.x,menuHidePos.y+rightClickMenuInternalBox2.getSize().y);
                rightClickMenuInternalBox4.setPosition(menuHidePos.x,menuHidePos.y+rightClickMenuInternalBox3.getSize().y);
                rightClickMenuInternalBox5.setPosition(menuHidePos.x,menuHidePos.y+rightClickMenuInternalBox4.getSize().y);
                rightClickMenuInternalBox6.setPosition(menuHidePos.x,menuHidePos.y+rightClickMenuInternalBox4.getSize().y);

                boxTextMove.setPosition(menuHidePos.x,menuHidePos.y);
                boxTextSize.setPosition(menuHidePos.x,menuHidePos.y+rightClickMenuInternalBox2.getPosition().y);
                boxTextAdd.setPosition(menuHidePos.x,menuHidePos.y+rightClickMenuInternalBox3.getPosition().y);
                boxTextSubtract.setPosition(menuHidePos.x,menuHidePos.y+rightClickMenuInternalBox4.getPosition().y);
                boxTextAutoSpawn.setPosition(menuHidePos.x,menuHidePos.y+rightClickMenuInternalBox4.getPosition().y);
                boxTextAutoMove.setPosition(menuHidePos.x,menuHidePos.y+rightClickMenuInternalBox4.getPosition().y);

                }


}


void gui::setMenuPosition(mouse& editMouse){

    storedMenuPosition.x=editMouse.mouseRect.left;
    storedMenuPosition.y=editMouse.mouseRect.top;

}


gui::~gui()
{
    //dtor
}
