#pragma once

#include "Tile.h"
#include <vector>
#include <algorithm>


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

    std::vector<char*> keyVec;
    std::vector<Tile*> fbf;


public:
    FbFboard();

    FbFboard(char answerKey[5][5],float x, float y, float sideLength);

    void reset();

    bool isWin() const;

    void draw() const;

    bool isClicked(float x, float y) const;

    void leftMouseDown(float mx, float my);


    void rightMouseDown(float mx, float my);

    void finalBoard();

    ~FbFboard();
};