#pragma once

#include "Tile.h"
#include <vector>

class FbFboard {
public:

    float sideLength;
    float curX;
    float curY;

    std::vector<Tile*> fbf;

    FbFboard();

    FbFboard(float x, float y, float sideLength);

    void draw() const;


    void leftMouseDown(float mx, float my);


    void rightMouseDown(float mx, float my);

    ~FbFboard();
};