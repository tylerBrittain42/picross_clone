#include <iostream>
#include "App.h"




App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){

    titleScreen = new TitleScreen();
    game = new Game();

} 

void App::draw() const {

    if(!titleScreen->getStartGame())
    {
        titleScreen->draw();
    }
    else{
        game->draw();
    }
}

void App::keyDown(unsigned char key, float x, float y){

    if (key == 27){
        exit(0);
    }
}

void App::leftMouseDown(float mx, float my) {
	// Convert from Window to Scene coordinates
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

void App::rightMouseDown(float mx, float my) {
	// Convert from Window to Scene coordinates
    if(titleScreen->getStartGame()){
        game->rightMouseDown(mx,my);
    }
    
    redraw();
}

void App::idle(){
    titleScreen->idle();
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
