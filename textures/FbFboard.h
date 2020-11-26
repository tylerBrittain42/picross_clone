#pragma once

#include "Tile.h"
#include "Hint.h"
#include <vector>
#include <algorithm>

class FbFboard {
public:
    char answerKey[5][5];
    float sideLength;
    float curX;
    float curY;
    int currHint;

    std::vector<char*> keyVec;
    std::vector<Tile*> fbf;

    FbFboard();

    FbFboard(float x, float y, float sideLength);

    bool isWin() ;

    void draw() const;


    void leftMouseDown(float mx, float my);


    void rightMouseDown(float mx, float my);

    ~FbFboard();
};