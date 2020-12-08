#include "Game.h"

#pragma once

#include <vector>
#include "FbFboard.h"
#include "Help.h"
#include "Display.h"
#include "WinState.h"



Game::Game(){


    Rect* Test = new Rect (0.1,0.1,0.1,0.1,1,1);
    char answerKey[5][5] = {{'e','c','e','c','c'},
                            {'c','c','e','c','e'},
                            {'e','b','e','e','e'},
                            {'c','e','e','e','c'}, 
                            {'e','c','c','c','e'}}; 

    playerBoard = new FbFboard(answerKey,-0,0,0.15);
    hintBoard = new Help(answerKey,0,0,0.15,0,0,1);
    display = new Display(-0.25,0.925,0.5,0.1);
    hasWon = new WinState();


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
    
    else if(hasWon->restartClicked(mx,my))
        playerBoard->reset();

    

}

void Game::rightMouseDown(float mx, float my){

    playerBoard->rightMouseDown(mx,my);

}

void Game::idle(){

}

Game::~Game(){
    
    
    
    delete playerBoard;
    delete hintBoard;
    delete display;

}



