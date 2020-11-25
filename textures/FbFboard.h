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

    std::vector<Tile*> fbf;
    std::vector<Hint*> vertHints;
    std::vector<Hint*> horzHints;

    FbFboard();

    FbFboard(float x, float y, float sideLength);
    
    std::vector<int> generateHoriz(char key[5][5]); 

    std::vector<int> generateVert(char key[5][5]); 

    bool isWin() ;

    void draw() const;


    void leftMouseDown(float mx, float my);


    void rightMouseDown(float mx, float my);

    ~FbFboard();
};