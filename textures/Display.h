#pragma once
#include "Button.h"
#include "Rect.h"
#include "SideBar.h"
#include "TexRect.h"

class Display {

private:
    float titleX;
    float titleY;
    float titleW;
    float titleH;



    TexRect* titleCard;
    SideBar* leftBar;
    TexRect* subName;

public:
    Display();
    Display(float titleX, float titleY, float titleW, float titleH);

    void draw() const;

    ~Display();

};