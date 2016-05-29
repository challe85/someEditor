#include "gameLogic.h"
#include <vector>
#include "entity.h"
#include <iostream>



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
	//if onGround = true  store in groundVEctor thingy.. but hmm do that as a thing on its own or do like the other shit in the for that sets shit up..  might be confuising in the long run!?
	//shit this will need to go through the whole chain so i need to store it in game. atleast thats my guess atm.
	//might work to create one that gets redone every update.



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
			//onGroundVector.push_back(iTr); entityNew entity etc.. hmm that be annoying. what if id just creaTE this at the same locaiton as the add function..
			//makes me think i wanna fill vector here instead!
			//entity //pulled between to ways to do this.. ,, 
			//onGroundVector.push_back(iTr); // hmm didnt that shit fail before thats why i did the other route!?


		}
			else {
			//iTr->gravityAccelerationClock.getElapsedTime().asMilliseconds(); //Mught be best to store this?
			iTr->onGround = false;
			
			
			iTr->mainSquare.move(0, 0.1 + iTr->gravityAccelerationClock.getElapsedTime().asMilliseconds()*0.1 );   //Make it accelerate?  Create some timer that starts when object is NOT stuck on bottom and resets when bot.
			//iTr->mainSquare.move(0, 1);
																												   //move 0.1 or 1   i dont know .. 
																												   //value will be super big atm.
			//Starts to look pretty intresting so my idea aint that faar off i guess.
			//hmm maybe we should also do a hitDetection for every single block so they can stack on each other. might be problematice with the autospawn doe :P
			//Add some acceleration sideways would also be cool. 
			//Add some bounce effect on ground!?
			//lets do a test on the random move func. i wanna see what the movement loks like with gravity thingy. must move wierd hehe

			}
		
		

	}


		for (std::vector<entity>::iterator iTr = editEntityVector.begin(); iTr != editEntityVector.end(); iTr++) {
			//if (iTr->onGround) { // <---

				//editGameLogic // hmm waht about creating another add function in editor?!?!?!? or hmm as i thought before.  haha now i might get it. i hope.
				//std::cout << "Wda" << std::endl;
				//std::cout << onGroundVector.size() << std::endl;  filled with same as regular vec.


			//aint working atm because the other vector aint updating any positions ... do i really wanna rewrite EVERYTHING to work with this!? not even sure it will work in the end.
				//hmm cant we just update pos of object on ground and set taht to other onGroundVector	

			//	for (std::vector<entity>::iterator onGroundItr = onGroundVector.begin(); onGroundItr != onGroundVector.end(); onGroundItr++) {
					
			//		onGroundItr->mainSquare.setPosition(iTr->mainSquare.getPosition().x, iTr->mainSquare.getPosition().y);  //= iTr->mainSquare.getPosition().x
						//onGroundItr->mainSquare.setPosition().y = iTr->mainSquare.getPosition().y
						//onGroundVector[onGroundItr]
					
			//		if (iTr->mainSquare.getGlobalBounds().intersects(    onGroundItr->mainSquare.getGlobalBounds()    )) { //hmm since this shti is sharing scope. how do i know what iTr i just used :P might need to rename it to be sure :P
			//			std::cout << "MAMMA MIA" << std::endl;  //for some reason the onGround aint getting filled os look that up
			//		}
				
			//	}
			
			
			
			
			
			
			
			
		//	} // <---
		
		
		
		}


	//<--

}

void gameLogic::pathing() {


}

gameLogic::~gameLogic()
{
    //dtor
}
