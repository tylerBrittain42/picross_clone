#include "TitleScreen.h"



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

    levels.push_back(new Button(bX,bY,bW,bH,r,g,b,tR,tB,tG,"One"));
    levels.push_back(new Button(bX + (bW*2),bY,bW,bH,r,g,b,tR,tB,tG,"Two"));
    
    levels.push_back(new Button(bX,bY-(bH*1.5),bW,bH,r,g,b,tR,tB,tG,"Three"));
    levels.push_back(new Button(bX + (bW*2),bY-(bH*1.5),bW,bH,r,g,b,tR,tB,tG,"Four"));

    titleCard = new TexRect("titleCard.png",-0.5,0.25,1,0.14269535673839184);

    startGame = false;

}

//We are only passing in colors because the titleScreen should always remain in the same position,
//but we may want to alter the color scheme
TitleScreen::TitleScreen(float r, float g, float b, float tR, float tG, float tB){

    curX = false;

    this->r = r;
    this->g = g;
    this->b = b;


    this->tR = tR;
    this->tG = tG;
    this->tB = tB;

    velX = 0.02;
    velY = -0.065;

    bX = -0.35;
    bY = 0;
    bW = 0.25;
    bH = 0.25;

    levels.push_back(new Button(bX,bY,bW,bH,r,g,b,tR,tB,tG,"One"));
    levels.push_back(new Button(bX + (bW*2),bY,bW,bH,r,g,b,tR,tB,tG,"Two"));
    
    levels.push_back(new Button(bX,bY-(bH*1.5),bW,bH,r,g,b,tR,tB,tG,"Three"));
    levels.push_back(new Button(bX + (bW*2),bY-(bH*1.5),bW,bH,r,g,b,tR,tB,tG,"Four"));

    titleCard = new TexRect("titleCard.png",-0.5,0.25,1,0.14269535673839184);

    startGame = false;

}



void TitleScreen::draw() const{

    titleCard->draw();

    for(auto i = levels.begin(); i != levels.end(); i++){
        (*i)->draw();
    }

}

//Once a level is clicked we set curLvl equal to that level 
//as well as trigger the start of the level
//NOTE: we use i + 1 rather than i because our levels are labeled
//from 1 through 4 rather than 0 through 3
void TitleScreen::leftMouseDown(float mx, float my){

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

void TitleScreen::setStartGame(bool startGame){
    this->startGame = startGame;
}

int TitleScreen::getLevel(){
    return(curLvl);
}



bool TitleScreen::hasHitBounds(Button* checkee){

    if(checkee->getX() < -1 || (checkee->getX() + checkee->getW()) > 1 || checkee->getY() > 1 || (checkee->getY() - checkee->getH()) < -1){
        return(true);
    }
    return(false);


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



TitleScreen::~TitleScreen(){

    for(auto i = levels.begin(); i != levels.end(); i++){
        delete *i;
    }
    delete titleCard;

}

