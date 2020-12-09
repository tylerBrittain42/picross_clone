#pragma once
#include "Button.h"
#include "TexRect.h"
#include <vector>
#include <iostream>



class WinState {

private:

    std::vector<Button*> buttons;
    TexRect* winText;

    //Since we want squares, we are using "s"
    //for both width and height
    float x;
    float y;
    float s;

    float r;
    float g;
    float b;

    float tR;
    float tG;
    float tB;

    

public:

    WinState();

    WinState(float x, float y, float s, float r, float g, float b);

    void createComponents(float x, float y, float s, float r, float g, float b,float tR, float tG, float tB);

    void draw() const;

    bool exitClicked(float x, float y);

    bool restartClicked(float mx, float my);
    

    ~WinState();

};