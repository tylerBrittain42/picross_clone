
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
    tB = 1;

    tX = x+0.01;
    tY = y*0.75+0.02;

    helpBox = new WordRect(x,y+0.075, w,h,1,0,0,"Controls",true);
    divide = new Rect(x,y*0.875+0.075,w,h*0.125,0.51,0.44,0.43);

}

SideBar::SideBar(float x, float y){

    widthh = 640;

   
    this->x = x;
    this->y = y;
    w = 0.5;
    h = 0.5; 

    tR = 0.51;
    tG = 0.44;
    tB = 0.43;

    tX = x+0.01;
    tY = y*0.75+0.02;

    helpBox = new WordRect(x,y+0.075, w,h,0.26,0.22,0.21,tR,tG,tB,"Controls",true);
    
    //box divider between the word controls and the actual controls
    divide = new Rect(x,y*0.875+0.075,w,h*0.125,0.51,0.44,0.43);


}



void SideBar::draw() const{
    
    helpBox->draw();
    divide->draw();
    renderText("mark-right click",tX,tY, GLUT_BITMAP_HELVETICA_18, tR,tG,tB);
    renderText("flag-left click",tX,tY-0.1, GLUT_BITMAP_HELVETICA_18, tR,tG,tB);
    
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




SideBar::~SideBar(){
    delete helpBox;
    delete divide;
}
