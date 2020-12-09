#pragma once

#include "Button.h"
#include "TexRect.h"
#include <vector>
#include <iostream>
#include "State.h"
#include "FbFboard.h"
#include "Help.h"
#include "Keys.cpp"


class Win:public State{

private:

    std::vector<Button*> buttons;
    TexRect* winText;
    FbFboard* playerBoard;
    Help* hintBoard;
    Keys* key;

    int currKey;
    char answerKey[5][5];




    //Since we want squares, we are using "s"
    //for both width and height
    float x;
    float y;
    float s;

    float r;
    float g;
    float b;

    float tR;
    float tG;
    float tB;

    

public:

    Win();

    Win(int currKey);

    Win(float x, float y, float s, float r, float g, float b);

    void createComponents(float x, float y, float s, float r, float g, float b,float tR, float tG, float tB);

    void draw() const;

    bool exitClicked(float mx, float my);

    bool restartClicked(float mx, float my);

    void leftMouseDown(float mx, float my);

    void genKey();

    void UpdateKey(int currKey);

    ~Win();

};