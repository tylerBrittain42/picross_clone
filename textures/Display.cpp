#include "Display.h"

Display::Display(){

    titleX = -0.25;
    titleY = 0.975;
    titleW = 0.5;
    titleH = 0.14269535673839184;


    titleCard = new TexRect("titleCard.png",-0.5,titleY,1,titleH);
    subName = new TexRect("byTyler.png",-0.5,titleY-titleH,1,titleH);
    leftBar = new SideBar();


   
}

//We always want the sidebar to spawn in the same position
//But we can adjust the position of the title and subtitle
Display::Display(float titleX, float titleY, float titleW, float titleH){
    
    this->titleX = titleX;
    this->titleY = titleY;
    this->titleW = titleW;
    this->titleH = titleH;

    titleCard = new TexRect("titleCard.png",-0.5,titleY,1,titleH);
    subName = new TexRect("byTyler.png",-0.25,titleY-titleH-0.01,0.5,titleH*0.5);
    leftBar = new SideBar(-0.916666667,0.65);



}


void Display::draw() const{
    
    titleCard->draw();
    subName->draw();
    leftBar->draw();
    

}

Display::~Display(){
    delete leftBar;
    delete subName;
    delete titleCard;


}

