#include "FbFboard.h"
#include <iostream>




FbFboard::FbFboard(){
    std::cout << "board created" << std::endl;

    fbf.push_back(new Tile(0,0));
    std::cout<<"x: "<<fbf[0]->getX() <<std::endl;


}

void FbFboard::draw() const{
    std::cout << "board draw triggered" << std::endl;
    for(auto i = fbf.begin(); i != fbf.end(); i++){
        (*i)->draw();
    }    
    
}

// void FbFboard::keyDown(unsigned char key, float x, float y){

// }

// void FbFboard::leftMouseDown(float mx, float my){

// }


// void FbFboard::rightMouseDown(float mx, float my){

// }

FbFboard::~FbFboard(){
    for(auto i = fbf.begin(); i != fbf.end(); i++){
        delete *i;
    }
}


