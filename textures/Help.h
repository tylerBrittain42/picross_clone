#pragma once

#include "Hint.h"
#include "vector"
#include "Tile.h"

class Help{

private:
    
    char key[5][5];
    
    std::vector<Hint*> vertHints;
    std::vector<Hint*> horzHints;
    std::vector<int> vertCountt;
    std::vector<int> horzCountt;

public:

    Help();
    Help(char key[5][5]);


    std::vector<int> generateHoriz(char key[5][5]); 
    std::vector<int> generateVert(char key[5][5]);

    bool checkWin(std::vector<Tile*> fbf);

    void draw()const;

    ~Help();

};