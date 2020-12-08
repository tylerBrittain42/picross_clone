#include <iostream>
#include "App.h"



//This application is made up of two states, the first state is the title screen and the second screen is the actual game. 
//However, since certain aspects of these two states interact with each other, I have decided to leave them as part of app
//Rather than abstract them further

App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){

    titleScreen = new TitleScreen(0.26,0.22,0.21,0.51,0.44,0.43);
    game = new Game();

} 



//We will draw the title screen until the user has selected a level
//(Note: selecting a level will set startGame to true)
void App::draw() const {

    if(!titleScreen->getStartGame())
    {
        titleScreen->draw();
    }
    else{
        game->draw();
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

//While the user is on the title screen, we will set the App currLvl 
//equal to the level that the user has selected as well as update the answer key
//for the game state. This process will repeat until the user has made avalid level selection
    if(!titleScreen->getStartGame()){
        titleScreen->leftMouseDown(mx,my);
        currLvl = titleScreen->getLevel();
        game->UpdateKey(currLvl);
    }
    else{
        game->leftMouseDown(mx,my);
    }

    redraw();
}

//Since right clicking is only a valid action during the game state
//we do not bother passing it to titleScreen
void App::rightMouseDown(float mx, float my) {
	// Convert from Window to Scene coordinates
    if(titleScreen->getStartGame()){
        game->rightMouseDown(mx,my);
    }
    
    redraw();
}



void App::idle(){
    //ONLY ADD THIS LINE BACK IN IF I NEED PROOF OF ANIMATION
    //titleScreen->idle();

    //If WantsReset is true then we will trigger the titleScreen again
    //And set game WantsReset to false again
    if(game->getWantsReset()){
        titleScreen->setStartGame(false);
        game->setWantsReset(false);
    }
    redraw();
}



App::~App(){   

    delete game;
    delete titleScreen;

    std::cout << "Exiting..." << std::endl;
}
