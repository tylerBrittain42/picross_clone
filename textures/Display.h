#pragma once
#include "Button.h"
#include "Rect.h"

class Display {

private:
    float titleX;
    float titleY;
    float titleW;
    float titleH;

    float helpBoxX;
    float helpBoxY;
    float helpBoxW;
    float helpBoxH;




    Button* controls;
    Button* instructions;
    Button* gameName;
    Button* subName;
    Button* subTitle;
    Rect* helpBox;

public:
    Display();

    void draw() const;

    ~Display();

};