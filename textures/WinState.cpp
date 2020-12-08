#include "WinState.h"



WinState::WinState(){

    x = -0.916666667;
    y = 0.25;
    s = 0.4;

    r = 0.51;
    g = 0.44;
    b = 0.43;

    tR = 1;
    tG = 1;
    tB = 1;

    createComponents(x,y,s,r,g,b,tR,tG,tB);

        
}

WinState::WinState(float x, float y, float s, float r, float g, float b){
    
    this->x = x;
    this->y = y;
    this->s = s;

    this->r = r;
    this->g = g;
    this->b = b;

    createComponents(x,y,s,r,g,b,tR,tG,tB);
    
}



void WinState::createComponents(float x, float y, float s, float r, float g, float b,float tR, float tG, float tB){

    //play again
    buttons.push_back(new Button(x,y,s,s,r,g,b,tR,tG,tB,"Play Again?"));

    //exit
    buttons.push_back(new Button(x,y - s - 0.04,s,s,r,g,b,tR,tG,tB,"Exit"));

    winText = new TexRect("victoryText.png",-1,1.25,2,2);

}



void WinState::draw() const{
    
    winText->draw();

    for(auto i = buttons.begin(); i != buttons.end(); i++){
        (*i)->draw();
    }
}



bool WinState::exitClicked(float mx, float my){

    if(buttons.at(1)->isClicked(mx,my))
        return(true);
    return(false);

}



bool WinState::restartClicked(float mx, float my){

    if(buttons.at(0)->isClicked(mx,my))
        return(true);
    return(false);

}



WinState::~WinState(){
    delete winText;

    for(auto i = buttons.begin(); i != buttons.end(); i++){
        delete *i;
    }

}

