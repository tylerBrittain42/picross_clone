#pragma once

#include <vector>
#include "FbFboard.h"
#include "Help.h"
#include "Display.h"
#include "WinState.h"
#include "Keys.cpp"

class Game{


private:

    FbFboard* playerBoard;
    Help* hintBoard;
    Display* display;
    WinState* hasWon;
    Keys* key;


    int currKey;
    char answerKey[5][5];

    bool wantsReset;




public:

    Game();

    void draw() const;
    
    void leftMouseDown(float mx, float my);

    void rightMouseDown(float mx, float my);

    void idle();

    void genKey();

    void UpdateKey(int currKey);

    bool getWantsReset();

    void setWantsReset(bool wantsReset);
    
    ~Game();




};