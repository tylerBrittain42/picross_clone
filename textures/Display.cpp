#include "Display.h"

Display::Display(){

    titleX = -0.25;
    titleY = 0.925;
    titleW = 0.5;
    titleH = 0.1;

    gameName = new Button(titleX,titleY,titleW,titleH,1,1,1,"Picross",true);
    subName = new Button(titleX,titleY - titleH,titleW,titleH,1,1,0,"subName",true);
    leftBar = new SideBar(0.916666667,0.75);
   
}

//We always want the sidebar to spawn in the same position
//But we can adjust the position of the title and subtitle
Display::Display(float titleX, float titleY, float titleW, float titleH){
    
    this->titleX = titleX;
    this->titleY = titleY;
    this->titleW = titleW;
    this->titleH = titleH;

    gameName = new Button(titleX,titleY,titleW,titleH,1,1,1,"Picross",true);
    subName = new Button(titleX,titleY - titleH,titleW,titleH,1,1,0,"subName",true);
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
    delete subName;


}

