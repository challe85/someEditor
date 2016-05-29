#include "gameLogic.h"
#include <vector>
#include "entity.h"
//#include <iostream>



gameLogic::gameLogic()
{
    //ctor
}

void gameLogic::loadGameLogic(){

}

void gameLogic::update(std::vector<entity>& editEntityVector){
	gravity(editEntityVector);
}

void gameLogic::velocity() {


}

void gameLogic::gravity(std::vector<entity>& editEntityVector) {
	
	//Lets try with a temporary clock. or should i put a clock inside each entity!?!?!
	
	//
	for (std::vector<entity>::iterator iTr = editEntityVector.begin(); iTr != editEntityVector.end(); iTr++) {
		
				 //block on block.. do eet.
		
		//	if (!iTr->onGround) {  //hmm how did i think this would work :P dont know what to check for.. probably if onGorund boolol = true;
			//	if (iTr->mainSquare.getGlobalBounds().intersects(iTr->mainSquare.getGlobalBounds()) ) { //Hmm need to store somethin somewhere so i have something to ocmpare too :P

			//	}
		//	}
		
		
		if (iTr->mainSquare.getPosition().y >= 500) { //should make this value an object later, that way we could make some tests with shapes like a slope .
			iTr->onGround = true;
			iTr->mainSquare.move(0, 0);
			iTr->gravityAccelerationClock.restart();
		}
			else {
			//iTr->gravityAccelerationClock.getElapsedTime().asMilliseconds(); //Mught be best to store this?
			iTr->onGround = false;
			iTr->mainSquare.move(0, 0.1 + iTr->gravityAccelerationClock.getElapsedTime().asMilliseconds()*0.1 );   //Make it accelerate?  Create some timer that starts when object is NOT stuck on bottom and resets when bot.
			//move 0.1 or 1   i dont know .. 
																												   //value will be super big atm.
			//Starts to look pretty intresting so my idea aint that faar off i guess.
			//hmm maybe we should also do a hitDetection for every single block so they can stack on each other. might be problematice with the autospawn doe :P
			//Add some acceleration sideways would also be cool. 
			//Add some bounce effect on ground!?
			//lets do a test on the random move func. i wanna see what the movement loks like with gravity thingy. must move wierd hehe

			}
		
		

	}


	//<--

}

void gameLogic::pathing() {


}

gameLogic::~gameLogic()
{
    //dtor
}
