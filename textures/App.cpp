#include <iostream>
#include "App.h"

//picross_clone
//Author: Tyler Brittain 
//Last updated 12/08/2020
//Description: Recreation of the game picross in openGL.
//Game generates hints based off of puzzles stored in key struct
//meaning that if a key is modified, the game will adjust the hints
//and winState accordingly

//We are diving the applicaiton into three states:
//TitleScreen, Game, and WinState

//We will use the current state to decide what action the 
//application will take 

App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){

    titleScreen = new TitleScreen(0.26,0.22,0.21,0.51,0.44,0.43);
    game = new Game();
    game->changeState(false);

    
} 




void App::draw() const {

    if(titleScreen->isCurrState()){
        titleScreen->draw();
    }

    else if(game->isCurrState()){
        game->draw();
    }

    else if(winState->isCurrState()){
        winState->draw();
    }

}



//We want to be able to exit the application regardless of the current state
void App::keyDown(unsigned char key, float x, float y){

    if (key == 27){
        exit(0);
    }
}

void App::leftMouseDown(float mx, float my) {
// Convert from Window to Scene coordinates

    //Actions for TitleScreen state
    if(titleScreen->isCurrState()){

        titleScreen->leftMouseDown(mx,my);
        
        //If the state changes to false, we know that a level has been selected
        if(!titleScreen->isCurrState()){

            currLvl = titleScreen->getLevel();
         
            delete game;
            game = new Game(currLvl);

        }
    }

    //Actions for Game state
    else if(game->isCurrState()){
        game->leftMouseDown(mx,my);
    }

    //Actions for Win state
    else if(winState->isCurrState()){
        
        winState->leftMouseDown(mx,my);
        
        if(!winState->isCurrState()){
            titleScreen->changeState(true);
        }
    }


    //We check to see if the player has won anytime they left click
    if(game->hasWon()){
        game->changeState(false);
        delete winState;
        winState = new Win(currLvl);
    }

    redraw();
}

//Since right clicking is only a valid action during the game state
//we do not bother passing the other states
void App::rightMouseDown(float mx, float my){
	// Convert from Window to Scene coordinates
 
    if(game->isCurrState()){
        game->rightMouseDown(mx,my);
    }
    
    redraw();
}



App::~App(){   

    delete winState;
    delete game;
    delete titleScreen;

    std::cout << "Exiting..." << std::endl;
}
