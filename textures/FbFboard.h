#pragma once

#include "Tile.h"
#include <vector>

class FbFboard {
public:
    std::vector<Tile*> fbf;

    FbFboard();

    void draw() const;

    // void keyDown(unsigned char key, float x, float y);

    // void leftMouseDown(float mx, float my);


    // void rightMouseDown(float mx, float my);

    ~FbFboard();
};