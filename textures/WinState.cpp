#include "WinState.h"
#include <iostream>



WinState::WinState(){

    x = -0.916666667;
    y = 0.25;

    s = 0.4;

    //play again
    buttons.push_back(new Button(x,y,s,s,1,1,1,"Play Again?",true));

    //exit
    buttons.push_back(new Button(x,y - s - 0.04,s,s,1,1,1,"Exit",true));

    winText = new TexRect("victoryText.png",-1,1.25,2,2);
    

    
}

void WinState::draw() const{
    
    winText->draw();

    for(auto i = buttons.begin(); i != buttons.end(); i++){
        (*i)->draw();
    }
}

void WinState::leftMouseDown(float mx, float my){

    if(buttons.at(0)->isClicked(mx,my)){
        std::cout << "play again clicked" << std::endl;
    }
    
    else if(buttons.at(1)->isClicked(mx,my)){
        exit(0);
    }

}

WinState::~WinState(){
    delete winText;

    for(auto i = buttons.begin(); i != buttons.end(); i++){
        delete *i;
    }

}

