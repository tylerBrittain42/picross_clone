#include <iostream>
#include "App.h"




App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){

    char answerKey[5][5] = {{'e','c','e','c','c'},
                            {'c','c','e','c','e'},
                            {'e','b','e','e','e'},
                            {'c','e','e','e','c'}, 
                            {'e','c','c','c','e'}};


    // Pushing different kinds of Shape in the collection
    //shapes.push_back(new TexRect("lion.png", -1, 1, 2, 2));
    playerBoard = new FbFboard(-0,0,0.15);
    hintBoard = new Help(answerKey,0.15,0,0);
    display = new Display();
    
    

   

} 

void App::draw() const {

    playerBoard->draw();
    hintBoard->draw();
    display->draw();
    

}

void App::keyDown(unsigned char key, float x, float y){

    if (key == 27){
        exit(0);
    }
}

void App::leftMouseDown(float mx, float my) {
	// Convert from Window to Scene coordinates
    playerBoard->leftMouseDown(mx,my);
    redraw();
}

void App::rightMouseDown(float mx, float my) {
	// Convert from Window to Scene coordinates
    playerBoard->rightMouseDown(mx,my);
    
    redraw();
}


App::~App(){   

    delete playerBoard;
    delete hintBoard;
    delete display;
    std::cout << "Exiting..." << std::endl;
}
