#include "FbFboard.h"
#include <iostream>




FbFboard::FbFboard(){

    
    sideLength = 0.25;
    curX = -1;
    curY = 1;

    for(int i = 0; i < 5; i++){

        for(int j = 0; j < 5; j++){
            fbf.push_back(new Tile(curX,curY,sideLength));
            curX = curX + (sideLength + 0.01);
        }
        curX = -1;
        curY = curY - (sideLength + 0.01);
    }


}

FbFboard::FbFboard(float x, float y, float sideLength){
    
    this->sideLength = sideLength;
    curX = x;
    curY = y;

    for(int i = 0; i < 5; i++){

        for(int j = 0; j < 5; j++){
            fbf.push_back(new Tile(curX,curY,sideLength));
            curX = curX + (sideLength + 0.01);
        }
        curX = x;
        curY = curY - (sideLength + 0.01);
    }

    //Horizontal
    curX = x;
    curY = (y + sideLength*3) + 0.05;
    //i controls row; j controls column
    for(int i = 0; i < 3; i++){

        for(int j = 0; j < 5; j++){
            vertHints.push_back(new Hint(curX,curY,sideLength, "ayo"));
            curX = curX + (sideLength + 0.01);
        }
        curX = x;
        curY = curY - (sideLength + 0.01);
    }

    //Vertical
    curX = (x - sideLength*3) - 0.05;
    curY = y;
    //i controls row; j controls column
    for(int i = 0; i < 5; i++){

        for(int j = 0; j < 3; j++){
            horzHints.push_back(new Hint(curX,curY,sideLength, "ayo"));
            curX = curX + (sideLength + 0.01);
        }
        curX = (x - sideLength*3) - 0.05;
        curY = curY - (sideLength + 0.01);
    }

}


void FbFboard::draw() const{
    for(auto i = fbf.begin(); i != fbf.end(); i++){
        (*i)->draw();
    }
    for(auto i = vertHints.begin(); i != vertHints.end(); i++){
        (*i)->draw();
    }    
    for(auto i = horzHints.begin(); i != horzHints.end(); i++){
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


}

void FbFboard::rightMouseDown(float mx, float my){

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


