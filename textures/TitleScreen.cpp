#include "TitleScreen.h"
#include<iostream>


TitleScreen::TitleScreen(){

    curX = false;

    float r = 1;
    float g = 0;
    float b = 1;

    velX = 0.02;
    velY = -0.065;

    start = new Button(0,0,0.25,0.25, "Start", true);

    titleCard = new TexRect("titleCard.png",-0.5,0.25,1,0.14269535673839184);

    startGame = false;




}

void TitleScreen::draw() const{

    titleCard->draw();
    start->draw();

}

void TitleScreen::leftMouseDown(float mx, float my){
    if(start->isClicked(mx,my)){
        startGame = true;
    }
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
    
    // if(hasHitBounds(start)){

    //    // if(curX){
    //         velX *= -1;
    //    // else
    //         velY *= -1;
    //     curX = !curX;

    // }

    // start->incX(velX);
    // start->incY(velX);


}

TitleScreen::~TitleScreen(){

    delete start;
    delete titleCard;

}

