#include "Display.h"




Button* controls;
Button* instructions;
Button* gameName;
Button* subName;
Button* subTitle;

Display::Display(){

    titleX = -0.25;
    titleY = 0.925;
    titleW = 0.5;
    titleH = 0.15;

    helpBoxX = -0.916666667;
    helpBoxY = 0.75;
    helpBoxW = 0.5;
    helpBoxH = 0.5; 


    gameName = new Button(titleX,titleY,titleW,titleH,"Picross",true);
    subName = new Button(titleX,(titleY-0.15),titleW,titleH/2,1,1,0,"subName",true);

    helpBox = new Rect(helpBoxX,helpBoxY, helpBoxW,helpBoxH,1,0,0);
    controls = new Button(helpBoxX,helpBoxY,helpBoxW,helpBoxH*0.25,0,0,1,"Controls",true);
    instructions = new Button(helpBoxX,helpBoxY*0.75, helpBoxW,helpBoxH*0.75,0,0,1,"instructions",true);
}

void Display::draw() const{
    gameName->draw();
    subName->draw();
    helpBox->draw();
    controls->draw();
    instructions->draw();

}

Display::~Display(){
    delete controls;
    delete instructions;
    delete gameName;
    delete subName;
    delete helpBox;

}

