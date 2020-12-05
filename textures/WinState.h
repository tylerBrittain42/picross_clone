#pragma once
#include "Button.h"
#include "TexRect.h"
#include <vector>

class WinState {

private:

    std::vector<Button*> buttons;

    float x;
    float y;
    float s;

    TexRect* winText;

public:

    WinState();

    void draw() const;

    bool exitClicked(float x, float y);

    bool restartClicked(float mx, float my);

    void leftMouseDown(float mx, float my);

    ~WinState();

};