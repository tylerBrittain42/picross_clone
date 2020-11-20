#include "FbFboard.h"
#include <iostream>




FbFboard::FbFboard(){
    std::cout << "board created" << std::endl;

    
    
    float cW = -1;
    float cH = 1;

    for(int i = 0; i < 5; i++){

        for(int j = 0; j < 5; j++){
            fbf.push_back(new Tile(cW,cH));
            cW = cW + 0.25;
        }
        cW = -1;
        cH = cH - 0.25;
    }
}

FbFboard::FbFboard(float x, float y){
    
}


void FbFboard::draw() const{
    std::cout << "board draw triggered" << std::endl;
    for(auto i = fbf.begin(); i != fbf.end(); i++){
        (*i)->draw();
    }    
    
}



void FbFboard::leftMouseDown(float mx, float my){

    for(auto i = fbf.begin(); i != fbf.end(); i++){
        if ((*i)->contains(mx,my) && (*i)->getClaimedBy() == 'c')
            (*i)->SetClaimedBy('e');
        else if ((*i)->contains(mx,my))
            (*i)->SetClaimedBy('c');
    }

    std::cout << "Left click in board" << std::endl;

}


void FbFboard::rightMouseDown(float mx, float my){

    std::cout << "Right click in board" << std::endl;
    for(auto i = fbf.begin(); i != fbf.end(); i++){
        if ((*i)->contains(mx,my) && (*i)->getClaimedBy() == 'x')
            (*i)->SetClaimedBy('e');
        else if ((*i)->contains(mx,my))
            (*i)->SetClaimedBy('x');
    }
}

FbFboard::~FbFboard(){
    for(auto i = fbf.begin(); i != fbf.end(); i++){
        delete *i;
    }
}


