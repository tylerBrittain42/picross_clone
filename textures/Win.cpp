#include "Win.h"


Win::Win(){
    x = -0.916666667;
    y = 0.25;
    s = 0.4;

    r = 0.51;
    g = 0.44;
    b = 0.43;

    tR = 1;
    tG = 1;
    tB = 1;

    currKey = 1;

    createComponents(x,y,s,r,g,b,tR,tG,tB);

        
}

Win::Win(int currKey){

    x = -0.916666667;
    y = 0.25;
    s = 0.4;

    r = 0.51;
    g = 0.44;
    b = 0.43;

    tR = 1;
    tG = 1;
    tB = 1;

    this->currKey = currKey;

    createComponents(x,y,s,r,g,b,tR,tG,tB);

        
}

Win::Win(float x, float y, float s, float r, float g, float b){
    
    this->x = x;
    this->y = y;
    this->s = s;

    this->r = r;
    this->g = g;
    this->b = b;

    currKey = 1;

    createComponents(x,y,s,r,g,b,tR,tG,tB);
    
}



void Win::createComponents(float x, float y, float s, float r, float g, float b,float tR, float tG, float tB){

    //play again
    buttons.push_back(new Button(x,y,s,s,r,g,b,tR,tG,tB,"Play Again?"));

    //exit
    buttons.push_back(new Button(x,y - s - 0.04,s,s,r,g,b,tR,tG,tB,"Exit"));

    winText = new TexRect("victoryText.png",-1,1.25,2,2);

    key = new Keys(); 
    genKey();

    playerBoard = new FbFboard(answerKey,-0,0,0.15,0.51,0.44,0.43);
    playerBoard->finalBoard();

    hintBoard = new Help(answerKey,0,0,0.15,0.26,0.22,0.21);



}



void Win::draw() const{
    
    winText->draw();

    playerBoard->draw();
    hintBoard->draw();

    for(auto i = buttons.begin(); i != buttons.end(); i++){
        (*i)->draw();
    }
}



bool Win::exitClicked(float mx, float my){

    if(buttons.at(1)->isClicked(mx,my))
        return(true);
    return(false);

}



bool Win::restartClicked(float mx, float my){

    if(buttons.at(0)->isClicked(mx,my))
        return(true);
    return(false);

}

void Win::genKey(){

    //We use a switch statement to set the current answerKey equal to an answer key from the keys struct
    switch (currKey) {

        case 1:
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++){
                    answerKey[i][j] = key->keyOne[i][j];
                }
            }
            break;
        case 2:
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++){
                    answerKey[i][j] = key->keyTwo[i][j];
                }
            }
            break;

        case 3:
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++){
                    answerKey[i][j] = key->keyThree[i][j];
                }
            }
            break;

        case 4:
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++){
                    answerKey[i][j] = key->keyFour[i][j];
                }
            }
            break;
    }
}

void Win::UpdateKey(int currKey){
    this->currKey = currKey;


    delete playerBoard;
    delete hintBoard;

    genKey();

    playerBoard = new FbFboard(answerKey,-0,0,0.15,0.51,0.44,0.43);
    hintBoard = new Help(answerKey,0,0,0.15,0.26,0.22,0.21);

    playerBoard->finalBoard();
    

}


void Win::leftMouseDown(float mx, float my){

    if(exitClicked(mx,my)){
        exit(0);
    }
    else if(restartClicked(mx,my)){
        State::changeState(false);
    }


}


Win::~Win(){
    delete winText;

    for(auto i = buttons.begin(); i != buttons.end(); i++){
        delete *i;
    }

}

