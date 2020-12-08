#include "FbFboard.h"



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

FbFboard::FbFboard(char answerKey[5][5],float x, float y, float sideLength, float tR, float tG, float tB){

    //Copying answerkey
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            this->answerKey[i][j] = answerKey[i][j];
        }
    }

    w = 0.79;
    h = 0.79;

    this->tR = tR;
    this->tG = tG;
    this->tB = tB;

    this->sideLength = sideLength;
    curX = x;
    curY = y;
    currHint = 0;


    //Creating playerboard
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            fbf.push_back(new Tile(curX,curY,sideLength,tR,tG,tB));
            curX = curX + (sideLength + 0.01);
        }
        curX = x;
        curY = curY - (sideLength + 0.01);
    }

}



//Checks to see if the answerKey 'c' values are the same as the player c values
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



//Left click claims a space
void FbFboard::leftMouseDown(float mx, float my){

    for(auto i = fbf.begin(); i != fbf.end(); i++){
        if ((*i)->contains(mx,my) && (*i)->getClaimedBy() == 'c')
            (*i)->SetClaimedBy('e');
        else if ((*i)->contains(mx,my))
            (*i)->SetClaimedBy('c');
    }
}



//Right click marks a space as 'x'
//Note: has no impace on game, solely used as a note for the player
void FbFboard::rightMouseDown(float mx, float my){

    for(auto i = fbf.begin(); i != fbf.end(); i++){
        if ((*i)->contains(mx,my) && (*i)->getClaimedBy() == 'x')
            (*i)->SetClaimedBy('e');
        else if ((*i)->contains(mx,my))
            (*i)->SetClaimedBy('x');
    }
}



//Once the player has accurately completed a board
//We want the board to display only the correct answers
//and not the x's
void FbFboard::finalBoard(){

    for(auto i = fbf.begin(); i != fbf.end(); i++){
        if ((*i)->getClaimedBy() == 'x'){
            (*i)->SetClaimedBy('e');
        }
    }

}



FbFboard::~FbFboard(){

    for(auto i = fbf.begin(); i != fbf.end(); i++){
        delete *i;
    }

    for(auto i = keyVec.begin(); i != keyVec.end(); i++){
        delete *i;
    }
}


