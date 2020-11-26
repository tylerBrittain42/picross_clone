#include <iostream>
#include "App.h"




App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){

    // Pushing different kinds of Shape in the collection
    //shapes.push_back(new TexRect("lion.png", -1, 1, 2, 2));
    playerBoard = new FbFboard(-0,0,0.15);
    //gameName = new Button(-0.25,(1-0.075),0.5,0.15,"Picross");
    //subName = new Button(-0.25,(1-0.075-0.15),0.5,0.15/2,1,1,0,"subName");
    //helpBox = new Rect(-1 + (0.15 + 0.05/3)*0.5,1 - (0.15 + 0.05/3)*1.5, (0.15 + 0.05/3)*3,(0.15 + 0.05/3)*3,1,0,0);
    //controls = new Button(-1 + (0.15 + 0.05/3)*0.5,1 - (0.15 + 0.05/3)*1.5, (0.15 + 0.05/3)*3,((0.15 + 0.05/3)*3)*0.25,0,0,1,"Controls");
    //instructions = new Button(-1 + (0.15 + 0.05/3)*0.5,(1 - (0.15 + 0.05/3)*1.5)*0.75, (0.15 + 0.05/3)*3,((0.15 + 0.05/3)*3)*0.75,0,0,1,"instructions");
    //hintTest = new Hint(-1,1,0.15,"ayo");

   

} 

void App::draw() const {
    //playerBoard->draw();
    //gameName->draw();
    //subName->draw();
    //helpBox->draw();
    //controls->draw();
    //instructions->draw();

    //shapes[0]->draw();
    playerBoard->draw();
    //hintTest->draw();
}

void App::keyDown(unsigned char key, float x, float y){
    if (key == ' '){
        
        //shapes[0]->SetClaimedBy('c');
        
    }

    if (key == 27){
        exit(0);
    }
}

void App::leftMouseDown(float mx, float my) {
	// Convert from Window to Scene coordinates

    
    // if (shapes[0]->contains(mx,my) && shapes[0]->getClaimedBy() == 'c')
    //     shapes[0]->SetClaimedBy('e');
    // else if (shapes[0]->contains(mx,my))
    //     shapes[0]->SetClaimedBy('c');
    playerBoard->leftMouseDown(mx,my);
    redraw();
}

void App::rightMouseDown(float mx, float my) {
	// Convert from Window to Scene coordinates

    
    // if (shapes[0]->contains(mx,my) && shapes[0]->getClaimedBy() == 'x')
    //     shapes[0]->SetClaimedBy('e');
    // else if (shapes[0]->contains(mx,my))
    //     shapes[0]->SetClaimedBy('x');
    playerBoard->rightMouseDown(mx,my);
    
    redraw();
}


App::~App(){   
    //Ref for deleting vec
    // for(auto i = shapes.begin(); i != shapes.end(); i++){
    //     delete *i;
    // }
    delete playerBoard;
    std::cout << "Exiting..." << std::endl;
}
