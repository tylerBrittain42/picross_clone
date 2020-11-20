#pragma once

#include "Tile.h"
#include <vector>

class FbFboard {
public:
    std::vector<Tile*> fbf;

    FbFboard();

    FbFboard(float x, float y);

    void draw() const;


    void leftMouseDown(float mx, float my);


    void rightMouseDown(float mx, float my);

    ~FbFboard();
};