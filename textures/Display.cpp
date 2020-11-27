#include "Display.h"




Button* controls;
Button* instructions;
Button* gameName;
Button* subName;
Button* subTitle;

Display::Display(){
    gameName = new Button(-0.25,(1-0.075),0.5,0.15,"Picross");
    subName = new Button(-0.25,(1-0.075-0.15),0.5,0.15/2,1,1,0,"subName");
    helpBox = new Rect(-1 + (0.15 + 0.05/3)*0.5,1 - (0.15 + 0.05/3)*1.5, (0.15 + 0.05/3)*3,(0.15 + 0.05/3)*3,1,0,0);
    controls = new Button(-1 + (0.15 + 0.05/3)*0.5,1 - (0.15 + 0.05/3)*1.5, (0.15 + 0.05/3)*3,((0.15 + 0.05/3)*3)*0.25,0,0,1,"Controls");
    instructions = new Button(-1 + (0.15 + 0.05/3)*0.5,(1 - (0.15 + 0.05/3)*1.5)*0.75, (0.15 + 0.05/3)*3,((0.15 + 0.05/3)*3)*0.75,0,0,1,"instructions");
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
    delete subTitle;
    delete helpBox;

}

