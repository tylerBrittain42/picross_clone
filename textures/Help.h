#pragma once

#include "WordRect.h"
#include <vector>

class Help{

private:

    //testing 2d vectors with left first
    std::vector<std::vector<int>> leftVal;
    std::vector<std::vector<WordRect*>> leftHints;

    std::vector<std::vector<int>> topVal;
    std::vector<std::vector<WordRect*>> topHints;

    std::vector<WordRect*> tempVec;
    
    float r;
    float g;
    float b;

    char key[5][5];

    float sideLength;
    float x;
    float y;

    float curX;
    float curY;
    
   

public:

    Help();
    Help(char key[5][5],float x, float y, float sideLength,float r, float g, float b);


    void calculateLeftValues();
    void generateLeftHints(); 

    void calculateTopValues();
    void generateTopHints();


    void draw()const;

    ~Help();

};