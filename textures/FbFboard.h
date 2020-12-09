#pragma once

#include "Tile.h"
#include <vector>
#include <algorithm>
#include <iostream>



class FbFboard {
private:

    //Coordinate information for entire board
    float x;
    float y; 
    float w;
    float h;

    char answerKey[5][5];
    float sideLength;
    float curX;
    float curY;
    int currHint;

    float tR;
    float tG;
    float tB;

    std::vector<char*> keyVec;
    std::vector<Tile*> fbf;


public:
    FbFboard();

    FbFboard(char answerKey[5][5],float x, float y, float sideLength, float tR, float tG, float tB);

    bool isWin() const;

    void draw() const;

    void leftMouseDown(float mx, float my);

    void rightMouseDown(float mx, float my);

    void finalBoard();

    ~FbFboard();
};