#ifndef HINT_H
#define HINT_H

#include <string>
#include "Rect.h"

class Hint: public Rect{
private:
    std::string hintText;

public:
    Hint();
    Hint(float x, float y, float side, std::string hintText);
 
    void draw() const;

    void renderText(
    float x, 
    float y, 
    void* font, 
    float r, 
    float g, 
    float b) const;


    std::string getHintText() const;

    void setHintText(std::string hintText); 


    ~Hint();




};

#endif