#include "FbFboard.h"
#include <iostream>




FbFboard::FbFboard(){

    
    
    float cW = -1;
    float cH = 1;

    for(int i = 0; i < 5; i++){

        for(int j = 0; j < 5; j++){
            fbf.push_back(new Tile(cW,cH,0.25));
            cW = cW + 0.26;
        }
        cW = -1;
        cH = cH - 0.26;
    }
}

FbFboard::FbFboard(float x, float y){
    
    float cW = x;
    float cH = y;

    // for(int i = 0; i < 5; i++){

    //     for(int j = 0; j < 5; j++){
    //         fbf.push_back(new Tile(cW,cH));
    //         cW = cW + 0.25;
    //     }
    //     cW = x;
    //     cH = cH - 0.25;
    // }
    fbf.push_back(new Tile(-0.25,0.25,0.5));

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


