
#include "SideBar.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif


SideBar::SideBar(){

    widthh = 640;

    x = -0.916666667;
    y = 0.75;
    w = 0.5;
    h = 0.5; 

    tR = 1;
    tG = 1;
    tB = 0;

    helpBox = new Rect(x,y+0.075, w,h,1,0,0);
    divide = new Rect(x,y*0.875+0.075,w,h*0.125,0,0,1);

   

}




SideBar::SideBar(float x, float y){
    this->x = x;
    this->y = y;
    w = 0.5;
    h = 0.5; 

    tR = 1;
    tG = 1;
    tB = 1;

    helpBox = new Rect(x,y, w,h,1,0,0);
    divide = new Rect(x,y, w,h,1,0,0);

    
}



void SideBar::draw() const{
    
    //controls->draw();
    //instructions->draw();
    helpBox->draw();
    divide->draw();
    renderCenterText("Controls",x ,y, GLUT_BITMAP_TIMES_ROMAN_24, tR,tG,tB);
    renderText("mark-right click",x+0.01 ,y*0.75+0.05, GLUT_BITMAP_HELVETICA_18, tR,tG,tB);
    renderText("flag-left click",x+0.01 ,y*0.75-0.1+0.05, GLUT_BITMAP_HELVETICA_18, tR,tG,tB);

    
}




void SideBar::renderText(
    std::string text, 
    float x, 
    float y, 
    void* font = GLUT_BITMAP_HELVETICA_18, 
    float r = 0, 
    float g = 1, 
    float b = 1
) const{
    
    glColor3f(r, g, b);
    float offset = 0;
    for (int i = 0; i < text.length(); i++) {
        glRasterPos2f(x+offset, y);
        glutBitmapCharacter(font, text[i]);
        int w = glutBitmapWidth(font, text[i]);
        offset += ((float)w / widthh)*2;
    }
}



void SideBar::renderCenterText(
    std::string text, 
    float x, 
    float y, 
    void* font = GLUT_BITMAP_HELVETICA_18, 
    float r = 0, 
    float g = 1, 
    float b = 1
) const{
    
    glColor3f(r, g, b);
    float offset2 = 0;
    int textWidth;
    float buff = 0;

    for (int i = 0; i < text.length(); i++) {
        int textWidth = glutBitmapWidth(font, text[i]);
        offset2 += ((float)textWidth / widthh)*2;
    }
    buff = (w - offset2)/2;


    //glColor3f(r, g, b);
    float offset = 0;
    offset = buff+offset;

    for (int i = 0; i < text.length(); i++) {
        glRasterPos2f(x+offset, y);
        glutBitmapCharacter(font, text[i]);
        int w = glutBitmapWidth(font, text[i]);
        offset += ((float)w / widthh)*2;
    }
}




SideBar::~SideBar(){
    delete helpBox;
    delete divide;
    delete instructions;
}
