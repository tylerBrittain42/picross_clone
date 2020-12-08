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

Button::Button(float x, float y, float w, float h, bool isCentered):Rect(x,y,w,h,0,0,0){

    text = "";
    this->isCentered = isCentered;

    tR = 1;
    tG = 1;
    tB = 1;


}

//Used for a text block with default white box
Button::Button(float x, float y, float w, float h, std::string text, bool isCentered):Rect(x,y,w,h,1,1,1){

    this->text = text;
    this->isCentered = isCentered;

    tR = 1;
    tG = 1;
    tB = 1;


}


Button::Button(float x, float y, float w, float h, float r, float g, float b, std::string text, bool isCentered):Rect(x,y,w,h,r,g,b){
	
    this->text = text;
    this->isCentered = isCentered;

    tR = 1;
    tG = 1;
    tB = 1;



}


Button::Button(float x, float y, float w, float h, float r, float g, float b, float tR, float tG, float tB, std::string text, bool):Rect(x,y,w,h,r,g,b){

    this->text = text;
    this->isCentered = isCentered;

    this->tR = tR;
    this->tG = tG;
    this->tB = tB;

}



bool Button::isClicked(float x, float y){
	return (x > this->x) && (x < this->x + this->w) && (y < this->y) && (y > this->y - this->h);
}





void Button::renderText(
    std::string text, 
    float x, 
    float y, 
    void* font = GLUT_BITMAP_HELVETICA_18, 
    float r = 0, 
    float g = 1, 
    float b = 1
){
    
    glColor3f(r, g, b);
    float offset = 0;
    for (int i = 0; i < text.length(); i++) {
        glRasterPos2f(x+offset, y);
        glutBitmapCharacter(font, text[i]);
        int w = glutBitmapWidth(font, text[i]);
        offset += ((float)w / widthh)*2;
    }
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
    

    //Black outline around each button 
    //NOTE:Won't be seen when the background is black
    glColor3f(0,0,0);
    glLineWidth(2);
    glBegin(GL_LINES);

    glVertex2f(x, y);
    glVertex2f(x+w, y);

    glVertex2f(x+w, y);
    glVertex2f(x+w, y-h);
    
    glVertex2f(x+w, y-h);
    glVertex2f(x, y-h);
    
    glVertex2f(x, y-h);
    glVertex2f(x, y);

    glEnd();

    //Draws actual button
   Rect::draw();

    //renders text inside of button
    if(isCentered)
        renderCenterText(text,x ,y-0.075, GLUT_BITMAP_TIMES_ROMAN_24, tR,tG,tB);
    else if(!isCentered)
        renderText(text,x ,y-0.075, GLUT_BITMAP_TIMES_ROMAN_24, tR,tG,tB);


}

Button::~Button(){
    
}
