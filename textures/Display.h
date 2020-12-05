#pragma once
#include "Button.h"
#include "Rect.h"
#include "SideBar.h"

class Display {

private:
    float titleX;
    float titleY;
    float titleW;
    float titleH;




    SideBar* leftBar;
    Button* gameName;
    Button* subName;

public:
    Display();

    void draw() const;

    ~Display();

};