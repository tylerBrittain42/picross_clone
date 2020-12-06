#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include "Rect.h"

class Button: public Rect {

private:
	
	bool isCentered;
	std::string text;


public:

	Button(); // This is a default constructor (takes no parameters)

	Button(float x, float y, float w, float h, bool);

    Button(float x, float y, float w, float h, std::string text, bool);

	Button(float x, float y, float w, float h, float r, float g, float b, std::string text, bool);

	void draw();

	bool isClicked(float x, float y);



	void renderText(std::string text, 
    float x, 
    float y, 
    void* font, 
    float r, 
    float g, 
    float b);


	void renderCenterText(std::string text, 
    float x, 
    float y, 
    void* font, 
    float r, 
    float g, 
    float b);


};




#endif
