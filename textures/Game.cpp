#include "Game.h"

#pragma once







#include <iostream>




Game::Game(){

    currKey = 1;

    key = new Keys(); 

    genKey();

    playerBoard = new FbFboard(answerKey,-0,0,0.15);
    hintBoard = new Help(answerKey,0,0,0.15,0.26,0.22,0.21);
    display = new Display(-0.25,0.975,0.5,0.14269535673839184);
    hasWon = new WinState();

    wantsReset = false;

}

void Game::draw() const{

    playerBoard->draw();
    hintBoard->draw();
    
    //if(false){
    if(playerBoard->isWin() != true){
        display->draw();
    }
    else{
        hasWon->draw();   
    }
}




void Game::leftMouseDown(float mx, float my){
    
    //if(playerBoard->isClicked(mx,my) && playerBoard->isWin() != true){
    if(!playerBoard->isWin()){  
        playerBoard->leftMouseDown(mx,my);
    }

    else if(hasWon->exitClicked(mx,my))
        exit(0);
    
    else if(hasWon->restartClicked(mx,my)){
        playerBoard->reset();
        wantsReset = true;    
    }

    

}

void Game::rightMouseDown(float mx, float my){

    playerBoard->rightMouseDown(mx,my);

}

void Game::idle(){

}


void Game::genKey(){


    switch (currKey) {

        case 1:
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++){
                    answerKey[i][j] = key->keyOne[i][j];
                }
            }
            break;
        case 2:
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++){
                    answerKey[i][j] = key->keyTwo[i][j];
                }
            }
            break;

        case 3:
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++){
                    answerKey[i][j] = key->keyThree[i][j];
                }
            }
            break;

        case 4:
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++){
                    answerKey[i][j] = key->keyFour[i][j];
                }
            }
            break;
    }

}

void Game::UpdateKey(int currKey){
    this->currKey = currKey;


    delete playerBoard;
    delete hintBoard;

    genKey();

    playerBoard = new FbFboard(answerKey,-0,0,0.15);
    hintBoard = new Help(answerKey,0,0,0.15,0.26,0.22,0.21);
    
}

bool Game::getWantsReset(){
    return(wantsReset);
}

void Game::setWantsReset(bool wantsReset){
    
    this->wantsReset = wantsReset;

}



Game::~Game(){
    
    
    
    delete playerBoard;
    delete hintBoard;
    delete display;
    delete key;

}



