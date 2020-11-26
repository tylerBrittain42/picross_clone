#pragma once
#include "Button.h"
#include <iostream>


#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

using namespace std;

//used for renderText
int widthh = 640;


Button::Button(){
	x = 0;
	y = 0;
	red = 1;
	green = 1;
	blue = 0;

	w = 0.2;
	h = 0.2;
    text = "";

	
}

Button::Button(float x, float y, float w, float h){
	this->x = x;
	this->y = y;

	red = 1;
	green = 0;
	blue = 0;

	this->w = w;
	this->h = h;
    text = "";


}

//Used for a text block with default black box, white text
Button::Button(float x, float y, float w, float h, string text){
    this->x = x;
	this->y = y;

	red = 1;
	green = 1;
	blue = 1;

	this->w = w;
	this->h = h;

    this->text = text;


}


Button::Button(float x, float y, float w, float h, float red, float green, float blue, string text){
	this->x = x;
	this->y = y;

	this->red = red;
	this->green = green;
	this->blue = blue;

	this->w = w;
	this->h = h;
    this->text = text;



}

bool Button::isClicked(float x, float y){
	return (x > this->x) && (x < this->x + this->w) && (y < this->y) && (y > this->y - this->h);
}





void Button::renderText(
    string text, 
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


void Button::draw(){
    

    

	
    //Black outline around each button 
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
    
    glColor3f(red, green, blue);

    glBegin(GL_POLYGON);

    glVertex2f(x, y);
    glVertex2f(x+w, y);
    glVertex2f(x+w, y-h);
    glVertex2f(x, y-h);

    glEnd();

    
    


    glColor3f(red, green, blue);

    glBegin(GL_POLYGON);

    glVertex2f(x, y);
    glVertex2f(x+w, y);
    glVertex2f(x+w, y-h);
    glVertex2f(x, y-h);

    glEnd();

    renderText(text,x ,y-0.1, GLUT_BITMAP_TIMES_ROMAN_24, 1,0,0);



}
