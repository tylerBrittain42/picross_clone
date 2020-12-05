#include "Display.h"






Display::Display(){

    titleX = -0.25;
    titleY = 0.925;
    titleW = 0.5;
    titleH = 0.1;



    gameName = new Button(titleX,titleY,titleW,titleH,"Picross",true);
    subName = new Button(titleX,titleY - gameName->h,titleW,titleH,1,1,0,"subName",true);
    leftBar = new SideBar();
   
}

void Display::draw() const{
    
    gameName->draw();
    subName->draw();
    
    leftBar->draw();
    

}

Display::~Display(){
    delete gameName;
    delete leftBar;


}

