#include "Hint.h"
#include "GlutApp.h"
#include <iostream>



Hint::Hint():Rect(0,0,0.5){
    std::cout << "default constructor triggered" << std::endl;

    
}

Hint::Hint(float x, float y, float side, std::string hintText):Rect(x,y,side){
    this->hintText = hintText;

}

void Hint::draw() const{
    Rect::draw();
    renderText(x+(0.5*w),y-(h*0.5),GLUT_BITMAP_TIMES_ROMAN_24, 1,1,1);
    
}

//renders text
void Hint::renderText(
    float x, 
    float y, 
    void* font = GLUT_BITMAP_HELVETICA_18, 
    float r = 1, 
    float g = 1, 
    float b = 1
) const{
    
    glColor3f(r, g, b);
    float offset = 0;
    for (int i = 0; i < hintText.length(); i++) {
        glRasterPos2f(x+offset, y);
        glutBitmapCharacter(font, hintText[i]);
        int w = glutBitmapWidth(font, hintText[i]);
        offset += ((float)w / 640)*2;
    }
}


Hint::~Hint(){
    
}



