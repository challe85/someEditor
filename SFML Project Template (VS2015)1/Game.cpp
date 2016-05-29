#include "Game.h"
#include <SFML/Graphics.hpp>
#include "entity.h"
#include "gui.h"
#include "editor.h"
#include "mouse.h"
#include <iostream>
#include <vector>
#include "visual.h"
#include "hitDetection.h"
#include "gameLogic.h"
#include "randomFun.h"


Game::Game()
{
this->running=true;
    //ctor
}

Game::~Game()
{
    //dtor
}



int Game::start(){

    sf::RenderWindow window(sf::VideoMode(800, 600), "Game");
    window.setFramerateLimit(60);

    //Load some class objects
    gui Gui;
    Gui.loadGui();

    editor Editor;
    Editor.loadEditor();

    mouse Mouse;

    visual Visual;
    Visual.loadVisual(window);

    hitDetection hD;

    gameLogic GameLogic;
    GameLogic.loadGameLogic();

    randomFun RandomFun;
    RandomFun.loadRandomFun();
    //End


    while (window.isOpen())
    {
        sf::Event event;

        //Run and update stuff
        Editor.runEditor(Mouse,window);
        Editor.update();
        hD.update(Gui, Mouse, window, entityVector, Editor, RandomFun);
        Mouse.mousePosition(window);
        Gui.update(Mouse, entityVector);
        GameLogic.update(entityVector);
        RandomFun.update(Editor,Mouse,entityVector, RandomFun);
        //End

        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();


        Visual.drawVisual(window);

        for(std::vector<entity>::iterator iTr = entityVector.begin(); iTr!=entityVector.end(); iTr++){
        iTr->drawEntity(window);
        }

        Gui.drawGui(window,Mouse);

        window.display();
    }

    return 0;


}


void Game::stop(){
this->running=false;
}

void Game::set_Running(bool set_Running){
this->running=set_Running;
}

bool Game::get_Running(){
return this->running;
}
