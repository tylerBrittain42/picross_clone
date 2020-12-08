#include "TitleScreen.h"
#include<iostream>


TitleScreen::TitleScreen(){

    float r = 1;
    float g = 0;
    float b = 1;

    velX = 0.02;
    velY = -0.025;

    start = new Button(0,0,0.25,0.25, "TITLE", true);

    startGame = false;




}

void TitleScreen::draw() const{

    start->draw();

}

void TitleScreen::leftMouseDown(float mx, float my){
    if(start->isClicked(mx,my)){
        std::cout<<"is clicked"<<std::endl;
        startGame = true;
    }
    //std::cout << "naah" << std::endl;
}

bool TitleScreen::getStartGame(){
    return(startGame);
}


bool TitleScreen::hasHitBounds(Button* checkee){

    if(checkee->getX() < -1 || (checkee->getX() + checkee->getW()) > 1 || checkee->getY() > 1 || (checkee->getY() - checkee->getH()) < -1){
        return(true);
    }
    return(false);


}




void TitleScreen::idle(){
    
    if(hasHitBounds(start)){
        velX *= -1;
        velY *= -1;
    }

    start->incX(velX);
    start->incY(velX);

    std::cout << start->getX() << std::endl;

}

TitleScreen::~TitleScreen(){

    delete start;

}

