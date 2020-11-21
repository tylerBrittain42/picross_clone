#include <iostream>
#include "App.h"




App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){

    // Pushing different kinds of Shape in the collection
    //shapes.push_back(new TexRect("lion.png", -1, 1, 2, 2));
    //shapes.push_back(new Rect());
    //shapes.push_back(new Circle());
    shapes.push_back(new Tile(2,2,0.01));
    board = new FbFboard(-0.5,0.5,0.15);
    hintTest = new Hint(-1,1,0.25,"ayo");
    

} 

void App::draw() const {
    //board->draw();
    shapes[0]->draw();
    //board->draw();
    hintTest->draw();
}

void App::keyDown(unsigned char key, float x, float y){
    if (key == ' '){
        
        shapes[0]->SetClaimedBy('c');
        
    }

    if (key == 27){
        exit(0);
    }
}

void App::leftMouseDown(float mx, float my) {
	// Convert from Window to Scene coordinates

    
    if (shapes[0]->contains(mx,my) && shapes[0]->getClaimedBy() == 'c')
        shapes[0]->SetClaimedBy('e');
    else if (shapes[0]->contains(mx,my))
        shapes[0]->SetClaimedBy('c');
    board->leftMouseDown(mx,my);
    redraw();
}

void App::rightMouseDown(float mx, float my) {
	// Convert from Window to Scene coordinates

    
    if (shapes[0]->contains(mx,my) && shapes[0]->getClaimedBy() == 'x')
        shapes[0]->SetClaimedBy('e');
    else if (shapes[0]->contains(mx,my))
        shapes[0]->SetClaimedBy('x');
    board->rightMouseDown(mx,my);
    
    redraw();
}


App::~App(){   
    for(auto i = shapes.begin(); i != shapes.end(); i++){
        delete *i;
    }
    std::cout << "Exiting..." << std::endl;
}
