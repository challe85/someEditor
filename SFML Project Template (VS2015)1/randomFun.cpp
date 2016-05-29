#include "randomFun.h"
#include <vector>
#include "entity.h"
#include <random> //not sure if this one is needed!?
#include <iostream>
#include "editor.h"
#include "mouse.h"
#include <math.h>

randomFun::randomFun()
{
    //ctor
}

void randomFun::loadRandomFun(){
        autoSpawnActive = false;
        autoMoveActive = false;

        gravityPos.x = 100;
        gravityPos.y = 100;

        //gravityPos=floatVectorRandomizer();
}


void randomFun::update(editor& editEditor, mouse& editMouse, std::vector<entity>& editEntityVector, randomFun& editRandomFun){

//Call
    if(autoSpawnActive){
    autoSpawn(editEditor,editMouse,editEntityVector, editRandomFun);
    //std::cout << "Getting called? " << std::endl; 
    }

        if(autoMoveActive){
        randomMovement(editEntityVector);
       // std::cout << "Getting called? " << std::endl; 
        }

   // anotherAutoMove(editEntityVector);

}

int randomFun::directionRandomizer(){

int randDirection=0;
randDirection=rand() % 5 + 1 ; //not sure but lets try

return randDirection;
}

sf::Vector2f randomFun::floatVectorRandomizer(){

    sf::Vector2f result;


    result.x=(float)(rand() % 800);  //ATM every object rand in side screen boarders. 800      1600 / 1200
    result.y=(float)(rand() % 600);  //this way will be harder to write because it would req some algorithms. 600
    //dont know if ima be lazy and not finish this one because i think it would take to much time to learn the math for me.
//std::generate()

//printf("DBG values: x=%f, y=%f\n", result.x, result.y);

return result;
}



float randomFun::floatRandomizer(){

//float result;


return rand() % 360;   //cant i do it just like this  ?

}




void randomFun::anotherAutoMove(std::vector<entity>& editEntityVector){


    for(std::vector<entity>::iterator iTr = editEntityVector.begin(); iTr!=editEntityVector.end(); iTr++){


         if(iTr->mainSquare.getPosition().x >= iTr->gravityPosition.x ){  //gravityPos.x iTr->    //>=
         iTr->mainSquare.move(-1,0);
         }
         else{
         iTr->mainSquare.move(1,0);
         }


            if(iTr->mainSquare.getPosition().y >= iTr->gravityPosition.y ){
            iTr->mainSquare.move(0,-1);
            }else{
            iTr->mainSquare.move(0,1);
            }

        }


}




void randomFun::autoSpawn(editor& editEditor, mouse& editMouse, std::vector<entity>& editEntityVector, randomFun& editRandomFun){


    if(respawnTimer.getElapsedTime().asMilliseconds() >= 50){   //>=
    //std::cout << "Entity autoSpawned: " << std::endl;

      
		//Could we have any problems here? 
		editEditor.addObject(editEntityVector,editMouse, editRandomFun);

       
     
       

        respawnTimer.restart();
    }

}



void randomFun::randomMovement(std::vector<entity>& editEntityVector){

	//Or could the iTr problem affect this aswell?

    for(std::vector<entity>::iterator iTr = editEntityVector.begin(); iTr!=editEntityVector.end(); iTr++){

                direction=directionRandomizer();

            switch (direction){

                case 1:
                    iTr->mainSquare.move(1,0);
					//std::cout << "1,0" << std::endl;
                case 2:
                    iTr->mainSquare.move(-1,0);
					//std::cout << "-1,0" << std::endl;
                case 3:
                    iTr->mainSquare.move(0,1); //try another way here 
					//std::cout << "0,1" << std::endl;
                case 4:
                    iTr->mainSquare.move(0,-1);
					//std::cout << "0,-1" << std::endl;
                case 5:
                    iTr->mainSquare.move(0,0);
					//std::cout << "0,0" << std::endl;
                default:

                    break;

            }
    }

}



void randomFun::anotherRandomMovement(){



}




randomFun::~randomFun()
{
    //dtor
}




//printf("DBG values: x=%f, y=%f", result.x, result.y);



///SUMMIT EGO

/*
sf::Vector2f randomFun::floatVectorRandomizer(){

    sf::Vector2f result;
    LPRECT pRect = NULL;
    //This might need reference to window handle
    GetClientRect(hWnd, &pRect);
    int width = pRect.right;
    int height = pRect.bottom;

    srand(time(NULL));

    result.x=(float)(0 +((rand() % width)));
    result.y=(float)(0 +((rand() % height)));

    printf("DBG values: x=%f, y=%f\n", result.x, result.y);

    return result;
}
*/
