#include "Hint.h"
#include "GlutApp.h"
#include <iostream>



Hint::Hint():Rect(0,0,0.5){
    std::cout << "default constructor triggered" << std::endl;

    
}

Hint::Hint(float x, float y, float side, std::string hintText):Rect(x,y,side){
    std::cout << "constructor with hint " << hintText << "triggered" << std::endl;


}

void Hint::draw() const{
    std::cout << "Hint draw called";
    Rect::draw();

}

Hint::~Hint(){
    
}



