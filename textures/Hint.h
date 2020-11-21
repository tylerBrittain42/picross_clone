#ifndef HINT_H
#define HINT_H

#include <string>
#include "Rect.h"

class Hint: public Rect{
protected:
    std::string hintText;

public:

    Hint();
    Hint(float x, float y, float side, std::string hintText);
 
    void draw() const;

    ~Hint();




};

#endif