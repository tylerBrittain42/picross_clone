#include "FbFboard.h"
#include <iostream>
#include <string>




FbFboard::FbFboard(){

    
    sideLength = 0.25;
    curX = -1;
    curY = 1;




}

FbFboard::FbFboard(char answerKey[5][5],float x, float y, float sideLength){

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            this->answerKey[i][j] = answerKey[i][j];
        }
    }

    
    this->sideLength = sideLength;
    curX = x;
    curY = y;
    currHint = 0;

    for(int i = 0; i < 5; i++){

        for(int j = 0; j < 5; j++){
            fbf.push_back(new Tile(curX,curY,sideLength));
            curX = curX + (sideLength + 0.01);
        }
        curX = x;
        curY = curY - (sideLength + 0.01);
    }

}



bool FbFboard::isWin() {

    //printing both boards
    char answerKey[5][5] = {{'e','c','e','c','c'},
                            {'c','c','e','c','e'},
                            {'e','b','e','e','e'},
                            {'c','e','e','e','c'}, 
                            {'e','c','c','c','e'}};

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

void FbFboard::leftMouseDown(float mx, float my){

    for(auto i = fbf.begin(); i != fbf.end(); i++){
        if ((*i)->contains(mx,my) && (*i)->getClaimedBy() == 'c')
            (*i)->SetClaimedBy('e');
        else if ((*i)->contains(mx,my))
            (*i)->SetClaimedBy('c');
    }

    if(isWin()){
        std::cout << "WIN" << std::endl;
    }
    else
        std::cout<<"not yet" << std::endl;

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


