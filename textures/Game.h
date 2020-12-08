#pragma once

#include <vector>
#include "FbFboard.h"
#include "Help.h"
#include "Display.h"
#include "WinState.h"

class Game{


private:

    FbFboard* playerBoard;
    Help* hintBoard;
    Display* display;
    WinState* hasWon;



public:

    Game();

    void draw() const;
    
    void leftMouseDown(float mx, float my);

    void rightMouseDown(float mx, float my);

    void idle();
    
    ~Game();




};