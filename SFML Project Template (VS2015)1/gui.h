
#ifndef GUI_H
#define GUI_H
#include <SFML/Graphics.hpp>
#include "mouse.h"
#include "Game.h"
#include "editor.h"
#include "entity.h"
#include <vector>
#include <string>

class gui
{
    public:

    sf::Font font;

    //Title
    sf::Text text;
    //end


    //Slider
    sf::Text sliderText;

    sf::RectangleShape sliderMoveableBox;
    sf::RectangleShape sliderVerticalBox; //Hmm might try later to use all of theese gui things inside a vector, and use bools to make them do what i want.
    //end

    //Entity
    sf::Text entityCountTextCounter;
    sf::Text entityCountText;
    //end

    //Mouse
    sf::Text mousePosText;
    sf::Text mousePosTextValueX;
    sf::Text mousePosTextValueY;
    //end

    //RightClick Menu
    sf::RectangleShape rightClickMenuBox;
    sf::RectangleShape rightClickMenuInternalBox;
    sf::RectangleShape rightClickMenuInternalBox2;
    sf::RectangleShape rightClickMenuInternalBox3;
    sf::RectangleShape rightClickMenuInternalBox4;
    sf::RectangleShape rightClickMenuInternalBox5;
    sf::RectangleShape rightClickMenuInternalBox6;

    sf::Text boxTextSize;
    sf::Text boxTextMove;
    sf::Text boxTextAdd;
    sf::Text boxTextSubtract;
    sf::Text boxTextAutoSpawn;
    sf::Text boxTextAutoMove;
    //end

    sf::Vector2f storedMenuPosition;
    sf::Vector2f menuHidePos;

        gui();

        void loadGui();
        void drawGui(sf::RenderWindow& rw, mouse& editMouse);
        void setMenuPosition(mouse& editMouse);
        void update(mouse& editMouse, std::vector<entity>& editEntityVector);

        virtual ~gui();
    protected:
    private:


    int tmpInt;
    int convertedMousePosX;
    int convertedMousePosY;

    bool rightClick;
    bool leftClick;
    bool clicked;
    bool setMenuStaticPosition;
    bool hideMenu;

    entity setEntity;


};

#endif // GUI_H
