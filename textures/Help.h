#pragma once

#include "Hint.h"
#include "vector"
#include "Tile.h"

class Help{

private:
    
    char key[5][5];
    
    std::vector<Hint*> topHints;
    std::vector<Hint*> leftHints;
    std::vector<int> topCountt;
    std::vector<int> leftCountt;

public:

    Help();
    Help(char key[5][5]);


    std::vector<int> generateLeft(char key[5][5]); 
    std::vector<int> generateTop(char key[5][5]);

    bool checkWin(std::vector<Tile*> fbf);

    void draw()const;

    ~Help();

};