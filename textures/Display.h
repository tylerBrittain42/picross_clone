#pragma once
#include "Button.h"
#include "Rect.h"

class Display {

private:
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