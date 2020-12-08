#pragma once

#include "Button.h"
#include "TexRect.h"
#include <vector>
#include <iostream>

class TitleScreen{

private:

    bool curX;
    int curLvl;

    float r;
    float g;
    float b;

    //text colors
    float tR;
    float tG;
    float tB;

    //button coordinates
    float bX;
    float bY;
    float bW;
    float bH;

    //Button* start;

    TexRect* titleCard;

    std::vector<Button*> levels;

    bool startGame;

    float velX;
    float velY;

public:
    TitleScreen();

    TitleScreen(float r, float g, float b, float tR, float tG, float tB);
    void draw() const;

    void leftMouseDown(float mx, float my);

    bool getStartGame();

    void setStartGame(bool startGame);

    int getLevel();

    bool hasHitBounds(Button* checkee);

    void idle();

    ~TitleScreen();

};