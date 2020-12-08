#pragma once

#include "Button.h"
#include "TexRect.h"

class TitleScreen{

private:

    bool curX;

    Button* start;

    TexRect* titleCard;

    bool startGame;

    float velX;
    float velY;

public:
    TitleScreen();

    void draw() const;

    void leftMouseDown(float mx, float my);

    bool getStartGame();

    bool hasHitBounds(Button* checkee);

    void idle();

    ~TitleScreen();

};