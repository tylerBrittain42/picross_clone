#pragma once
#include "Button.h"


#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif


//used for renderText
int widthh = 640;


Button::Button():Rect(){

    text = "";
    isCentered = false;

	
}

Button::Button(float x, float y, float w, float h):Rect(x,y,w,h,0,0,0){

    text = "";

    tR = 1;
    tG = 1;
    tB = 1;


}

//Used for a text block with default white box
Button::Button(float x, float y, float w, float h, std::string text):Rect(x,y,w,h,1,1,1){

    this->text = text;

    tR = 1;
    tG = 1;
    tB = 1;


}


Button::Button(float x, float y, float w, float h, float r, float g, float b, std::string text):Rect(x,y,w,h,r,g,b){
	
    this->text = text;

    tR = 1;
    tG = 1;
    tB = 1;



}


Button::Button(float x, float y, float w, float h, float r, float g, float b, float tR, float tG, float tB, std::string text):Rect(x,y,w,h,r,g,b){

    this->text = text;

    this->tR = tR;
    this->tG = tG;
    this->tB = tB;

}



bool Button::isClicked(float x, float y) const{
	return (x > this->x) && (x < this->x + this->w) && (y < this->y) && (y > this->y - this->h);
}



void Button::renderCenterText(
    std::string text, 
    float x, 
    float y, 
    void* font = GLUT_BITMAP_HELVETICA_18, 
    float r = 0, 
    float g = 1, 
    float b = 1
){
    
    glColor3f(r, g, b);
    float offset2 = 0;
    int textWidth;
    float buff = 0;


    //This loop finds the length of the text and uses it to calculate an offset to draw the text with
    for (int i = 0; i < text.length(); i++) {
        int textWidth = glutBitmapWidth(font, text[i]);
        offset2 += ((float)textWidth / widthh)*2;
    }
    buff = (w - offset2)/2;


    float offset = 0;
    offset = buff+offset;

    for (int i = 0; i < text.length(); i++) {
        glRasterPos2f(x+offset, y);
        glutBitmapCharacter(font, text[i]);
        int w = glutBitmapWidth(font, text[i]);
        offset += ((float)w / widthh)*2;
    }
}


void Button::draw(){
    
    Rect::draw();
    renderCenterText(text,x ,y-0.075, GLUT_BITMAP_TIMES_ROMAN_24, tR,tG,tB);

}

Button::~Button(){
    
}
