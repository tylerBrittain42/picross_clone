#pragma once

#include "Game.h"
#include <iostream>



//We only use the default constructor because we only ever want
//a game object constructed in this manner
Game::Game(){

    //Uses a default value for the initial keys to be passed to each
    currKey = 1;
    key = new Keys(); 
    genKey();

    playerBoard = new FbFboard(answerKey,-0,0,0.15);
    hintBoard = new Help(answerKey,0,0,0.15,0.26,0.22,0.21);
    display = new Display(-0.25,0.975,0.5,0.14269535673839184);
    hasWon = new WinState();

    wantsReset = false;

}



//Updates the current key then resets the player and hint boards
//NOTE: This will only occur when the player selects a level
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



void Game::draw() const{

    playerBoard->draw();
    hintBoard->draw();
    

    if(playerBoard->isWin() != true){
        display->draw();
    }
    else{
        playerBoard->finalBoard();
        hasWon->draw();   
    }
}



void Game::leftMouseDown(float mx, float my){

    //The player will be unable to interact with the playerBoard 
    //once a win has occured
    if(!playerBoard->isWin()){  
        playerBoard->leftMouseDown(mx,my);
    }

    else if(hasWon->exitClicked(mx,my))
        exit(0);
    
    //Since resetting the board impacts both the TitleScreen and Game, 
    //We use a variable that will be checked in App
    else if(hasWon->restartClicked(mx,my)){
        playerBoard->reset();
        wantsReset = true;    
    }

    

}

//A right click will trigger an x
void Game::rightMouseDown(float mx, float my){
    playerBoard->rightMouseDown(mx,my);
}



void Game::genKey(){

    //We use a switch statement to set the current answerKey equal to an answer key from the keys struct
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



Game::~Game(){

    delete playerBoard;
    delete hintBoard;
    delete display;
    delete hasWon;
    delete key;

}



