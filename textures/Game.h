#pragma once

#include <vector>
#include "FbFboard.h"
#include "Help.h"
#include "Display.h"
#include "Keys.cpp"
#include "State.h"

class Game:public State{



private:

    FbFboard* playerBoard;
    Help* hintBoard;
    Display* display;
    Keys* key;


    int currKey;
    char answerKey[5][5];



public:

    Game();

    Game(int currKey);

    void genKey();

    void UpdateKey(int currKey);

    void draw() const;
    
    void leftMouseDown(float mx, float my);

    void rightMouseDown(float mx, float my);
    
    bool hasWon() const;
    
    ~Game();




};