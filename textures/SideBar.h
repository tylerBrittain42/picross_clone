#pragma once
#include "Button.h"
#include "Rect.h"
#include <string>


class SideBar {

private:

    float widthh;

    float x;
    float y;
    float w;
    float h;

    float tR;
    float tG;
    float tB;

    Rect* helpBox;
    Rect* divide;
    Button* instructions;


public:
    SideBar();

    SideBar(float x, float y);

    void draw() const;

    void renderText(std::string text, 
    float x, 
    float y, 
    void* font, 
    float r, 
    float g, 
    float b) const;


	void renderCenterText(std::string text, 
    float x, 
    float y, 
    void* font, 
    float r, 
    float g, 
    float b) const;


    ~SideBar();

};