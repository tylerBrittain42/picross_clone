#include "TitleScreen.h"
#include <iostream>


TitleScreen::TitleScreen(){

    curX = false;

    r = 0.26;
    g = 0.22;
    b = 0.21;


    tR = 0.51;
    tG = 0.44;
    tB = 0.43;

    velX = 0.02;
    velY = -0.065;

    bX = -0.35;
    bY = 0;
    bW = 0.25;
    bH = 0.25;

    //start = new Button(0,0,0.25,0.25,r,g,b,tR,tB,tG,"Start", true);
    levels.push_back(new Button(bX,bY,bW,bH,r,g,b,tR,tB,tG,"One", true));
    levels.push_back(new Button(bX + (bW*2),bY,bW,bH,r,g,b,tR,tB,tG,"Two", true));
    
    levels.push_back(new Button(bX,bY-(bH*1.5),bW,bH,r,g,b,tR,tB,tG,"Three", true));
    levels.push_back(new Button(bX + (bW*2),bY-(bH*1.5),bW,bH,r,g,b,tR,tB,tG,"Four", true));

    titleCard = new TexRect("titleCard.png",-0.5,0.25,1,0.14269535673839184);

    startGame = false;




}

void TitleScreen::draw() const{

    titleCard->draw();
    for(auto i = levels.begin(); i != levels.end(); i++){
        (*i)->draw();
    }

}

void TitleScreen::leftMouseDown(float mx, float my){
    // if(start->isClicked(mx,my)){
    //     startGame = true;
    // }

    for(int i = 0; i < levels.size(); i++){
        if ((levels.at(i))->isClicked(mx,my)){
            startGame = true;
            curLvl = i+1;    
        }
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

int TitleScreen::getLevel(){
    return(curLvl);
}


//ADD IN IF I NEED ANIMATIONS
//REMOVE IF I DO NOT 

// void TitleScreen::idle(){
    
//     // if(hasHitBounds(start)){

//     //    // if(curX){
//     //         velX *= -1;
//     //    // else
//     //         velY *= -1;
//     //     curX = !curX;

//     // }

//     // start->incX(velX);
//     // start->incY(velX);


// }

void TitleScreen::setStartGame(bool startGame){
    this->startGame = startGame;
}


TitleScreen::~TitleScreen(){

    for(auto i = levels.begin(); i != levels.end(); i++){
        delete *i;
    }
    delete titleCard;

}

