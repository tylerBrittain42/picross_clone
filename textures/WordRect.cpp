#include "WordRect.h"
#include "GlutApp.h"
#include <iostream>

WordRect::WordRect():Rect(){
    
    text = "";
    isCentered = false;

}


WordRect::WordRect(float x, float y, float side, float r, float g, float b, std::string text, bool isCentered):Rect(x,y,side,side,r,g,b){
    
    this->text = text;
    this->isCentered = isCentered;

}


void WordRect::draw(float z=0) const{
    
    Rect::draw();
    
    if(isCentered)
        renderCenterText(text,x ,y-0.075, GLUT_BITMAP_TIMES_ROMAN_24, 1,0,0);
    else if(!isCentered)
        renderText(text,x ,y-0.075, GLUT_BITMAP_TIMES_ROMAN_24, 1,0,0);

}

void WordRect::renderText(std::string text, 
float x, 
float y, 
void* font, 
float r, 
float g, 
float b) const{
    
    glColor3f(r, g, b);
    float offset = 0;
    for (int i = 0; i < text.length(); i++) {
        glRasterPos2f(x+offset, y);
        glutBitmapCharacter(font, text[i]);
        int w = glutBitmapWidth(font, text[i]);
        offset += ((float)w / widthh)*2;
    }

}


void WordRect::renderCenterText(std::string text, 
float x, 
float y, 
void* font, 
float r, 
float g, 
float b) const{
    
    glColor3f(r, g, b);
    float offset2 = 0;
    int textWidth;
    float buff = 0;

    //Calculates the total amount of space the text will take and created a buffer corresponding to it
    for (int i = 0; i < text.length(); i++) {
        int textWidth = glutBitmapWidth(font, text[i]);
        offset2 += ((float)textWidth / widthh)*2;
    }
    buff = (w - offset2)/2;


    float offset = 0;
    offset = buff+offset;

    //draws the text with respect to the buffer
    for (int i = 0; i < text.length(); i++) {
        glRasterPos2f(x+offset, y);
        glutBitmapCharacter(font, text[i]);
        int w = glutBitmapWidth(font, text[i]);
        offset += ((float)w / widthh)*2;
    }
}


std::string WordRect::getText() const{
    return(text);
}

void WordRect::setText(std::string text){
    this->text = text;
}


WordRect::~WordRect(){

}

