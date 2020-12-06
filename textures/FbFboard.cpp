#include "FbFboard.h"
#include <iostream>
#include <string>




FbFboard::FbFboard(){

    sideLength = 0.25;

    x = 0;
    y = 0;
    w = 0.79;
    h = 0.79;

    curX = -1;
    curY = 1;

    std::cout << "WARNING: NO PUZZLE FOUND";




}

FbFboard::FbFboard(char answerKey[5][5],float x, float y, float sideLength){

    w = 0.79;
    h = 0.79;

    //Copying answerkey
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            this->answerKey[i][j] = answerKey[i][j];
        }
    }

    
    this->sideLength = sideLength;
    curX = x;
    curY = y;
    currHint = 0;


    //Creating playerboard
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            fbf.push_back(new Tile(curX,curY,sideLength,1,0,0));
            curX = curX + (sideLength + 0.01);
        }
        curX = x;
        curY = curY - (sideLength + 0.01);
    }

}

//resets the gameboard
void FbFboard::reset(){
    
    for(auto i = fbf.begin(); i != fbf.end(); i++){
        (*i)->SetClaimedBy('e');
    }
    
}


bool FbFboard::isWin() const{

    int curTile = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if((answerKey[i][j] == 'c' && fbf[curTile]->getClaimedBy() != 'c') || (answerKey[i][j] == 'e' && fbf[curTile]->getClaimedBy() == 'c')){
                return(false);
             }
            curTile++;
        }
    }
    return true;


}


void FbFboard::draw() const{
    for(auto i = fbf.begin(); i != fbf.end(); i++){
        (*i)->draw();
    }
}


bool FbFboard::isClicked(float x, float y) const{
	return (x > this->x) && (x < this->x + this->w) && (y < this->y) && (y > this->y - this->h);
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


