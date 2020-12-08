#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include "Rect.h"

class Button: public Rect {

private:
	
	bool isCentered;
	std::string text;

    float tR;
    float tG;
    float tB;


public:

	Button(); // This is a default constructor (takes no parameters)

	Button(float x, float y, float w, float h);

    Button(float x, float y, float w, float h, std::string text);

	Button(float x, float y, float w, float h, float r, float g, float b, std::string text);

    Button(float x, float y, float w, float h, float r, float g, float b, float tR, float tG, float tB, std::string text);

	void draw();

	bool isClicked(float x, float y);



	void renderCenterText(std::string text, 
    float x, 
    float y, 
    void* font, 
    float r, 
    float g, 
    float b);

    ~Button();


};




#endif
