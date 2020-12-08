#pragma once

#include "Button.h"
#include "TexRect.h"
#include <vector>

class TitleScreen{

private:

    bool curX;
    int curLvl;

    float r;
    float g;
    float b;


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

    void draw() const;

    void leftMouseDown(float mx, float my);

    bool getStartGame();

    bool hasHitBounds(Button* checkee);

    void idle();

    int getLevel();

    ~TitleScreen();

};