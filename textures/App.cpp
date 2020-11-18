#include <iostream>
#include "App.h"




App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){

    // Pushing different kinds of Shape in the collection
    //shapes.push_back(new TexRect("lion.png", -1, 1, 2, 2));
    //shapes.push_back(new Rect());
    //shapes.push_back(new Circle());
    shapes.push_back(new Tile());
} 

void App::draw() const {
    for(auto i = shapes.begin(); i != shapes.end(); i++){
        (*i)->draw();
    }
}

void App::keyDown(unsigned char key, float x, float y){
    if (key == ' '){
        std::cout << "space hit " << shapes[0]->claimStatus << std::endl;
        shapes[0]->claimStatus = 'c';
        
    }

    if (key == 27){
        exit(0);
    }
}

void App::leftMouseDown(float mx, float my) {
	// Convert from Window to Scene coordinates

    std::cout << "Clicke" << std::endl;
    if (shapes[0]->contains(mx,my))
        std::cout << "tile clicked" << std::endl;
    redraw();
}

App::~App(){   
    for(auto i = shapes.begin(); i != shapes.end(); i++){
        delete *i;
    }
    std::cout << "Exiting..." << std::endl;
}
