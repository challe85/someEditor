#include "hitDetection.h"
#include <SFML/Graphics.hpp>
#include "mouse.h"
#include "gui.h"
#include <iostream>
#include "editor.h"
#include "entity.h"
#include "randomFun.h"


hitDetection::hitDetection()
{
    //ctor
}

void hitDetection::update(gui& editGui,mouse& editMouse,sf::RenderWindow& rw, std::vector<entity>& editEntityVector, editor& editEditor, randomFun& editRandomFun){

    //Set renderWindowRect values
    renderWindowRect.top=0;
    renderWindowRect.left=0;
    renderWindowRect.width = rw.getSize().x;
    renderWindowRect.height = rw.getSize().y;
    //end


    for(std::vector<entity>::iterator iTr = editEntityVector.begin(); iTr!=editEntityVector.end(); iTr++){


        if(iTr->mainSquare.getGlobalBounds().intersects(editMouse.mouseRect)){
        iTr->mouseOver=true;
        //test
        iTr->highLighted=true;
        //end
        tmpItr=iTr;

        }else{
        iTr->mouseOver=false;
        }

        if(iTr->mouseOver){
        iTr->mainSquare.setFillColor(sf::Color::Red);

                if(editMouse.leftClick()){

                    iTr->highLighted=false;

                    if(editEditor.moveActive){
                    iTr->mainSquare.setPosition(editMouse.mouseRect.left-iTr->mainSquare.getSize().x*0.5, editMouse.mouseRect.top-iTr->mainSquare.getSize().y*0.5); //I think this pretty much is what moves entities atm.

                    }
                }
        }else{


            if(!iTr->highLighted){
            iTr->mainSquare.setFillColor(sf::Color::Green);
            }
        }


           if(!editEntityVector.empty()){ //editEntityVector.size()!=0
                if(!iTr->mainSquare.getGlobalBounds().intersects(renderWindowRect)){
               // std::cout << "Box deleted: " << std::endl;

                    
                //ALL CODE BELOVE AND UNDER IS INSIDE A FORLOOP ITERATED WITH ITR.
				//	deleteiterator editEntityVector.erase();
				//	while(deleteiterator)
					
					editEntityVector.erase(iTr);   // vector.empty  to protect against deletion when 0 elements.

					//editVe
                    
                
                    

                }

           }


                if(editGui.sliderMoveableBox.getGlobalBounds().intersects(editMouse.mouseRect)){
                    if(editMouse.leftClick()){
                    editGui.sliderMoveableBox.setPosition(editGui.sliderMoveableBox.getPosition().x ,editMouse.mouseRect.top-editGui.sliderMoveableBox.getSize().y*0.5);
                        if(editGui.sliderMoveableBox.getPosition().y >= editGui.sliderVerticalBox.getPosition().y+5){


                            if(iTr->highLighted){

                            iTr->mainSquare.setSize(sf::Vector2f(editGui.sliderMoveableBox.getPosition().y*0.1,editGui.sliderMoveableBox.getPosition().y*0.1)); //Doesnt seem to delete objetcs anymore neether hhaa. // Ah this only targets whats highligted .. atleast i think so lol-.

                            }else{

                                }
                        }

                    }else{

                    }
                }

    }



            //ALL THIS SHOULD PROBABLY BE A SWITCH CASE....
        //Menu//size//move//add//sub

        if(editGui.rightClickMenuInternalBox.getGlobalBounds().intersects(editMouse.mouseRect)){
            if(editMouse.leftClick()){

                //THIS IS THE MOVE BOX
                //std::cout << "Move: " << std::endl; //should probable me like move active.

                if(editEditor.moveActive){
                editEditor.moveActive=false;
                }else{
                editEditor.moveActive=true;
                }


            }
        }

            if(editGui.rightClickMenuInternalBox2.getGlobalBounds().intersects(editMouse.mouseRect)){
                if(editMouse.leftClick()){

                sf::Vector2f tS;

                tS.x=20;
                tS.y=20;

                //THIS IS THE RESIZE BOX
                //std::cout << "Resize: " << std::endl;

                            for(std::vector<entity>::iterator iTr = editEntityVector.begin(); iTr!=editEntityVector.end(); iTr++){


                                if(iTr->mouseOver){
                                iTr->mainSquare.setSize(tS);

                                }

                            }

                }
            }

                if(editGui.rightClickMenuInternalBox3.getGlobalBounds().intersects(editMouse.mouseRect)){

                    if(editMouse.leftClick()){
                    //THIS IS THE ADD BOX
                    editEditor.addObject(editEntityVector, editMouse, editRandomFun);

                    }
                }



                                if(editGui.rightClickMenuInternalBox4.getGlobalBounds().intersects(editMouse.mouseRect)){

                                    if(editMouse.leftClick()){
                                //std::cout << "Subtract: " << std::endl;


                                    if(tmpItr->mouseOver){
                                    editEntityVector.erase(tmpItr);

                                        }else{
                                        std::cout << "Delete failed: no object highlighted " << std::endl;
                                        }

                                    }
                                }


                                    if(editGui.rightClickMenuInternalBox5.getGlobalBounds().intersects(editMouse.mouseRect)){

                                        if(editMouse.leftClick()){
                                        //std::cout << "AutoSpawn on/off: " << std::endl;

                                            if(editRandomFun.autoSpawnActive){
                                            editRandomFun.autoSpawnActive=false;
                                            }else{
                                            editRandomFun.autoSpawnActive=true;
                                            }


                                        }
                                    }


                                        if(editGui.rightClickMenuInternalBox6.getGlobalBounds().intersects(editMouse.mouseRect)){


                                            if(editMouse.leftClick()){
                                            // std::cout << "AutoMove on/off: " << std::endl;

                                                if(editRandomFun.autoMoveActive){
                                                editRandomFun.autoMoveActive=false;
                                                }else{
                                                editRandomFun.autoMoveActive=true;
                                                }



                                            }
                                        }

}

bool hitDetection::mouseHitDetection(entity& editEntity, mouse& editMouse){



return true;
}

hitDetection::~hitDetection()
{
    //dtor
}

