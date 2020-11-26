#include <string>

#ifndef BUTTON_H
#define BUTTON_H


struct Button {
	float x;
	float y;

	float red;
	float green; 
	float blue;

	float w;
	float h;

	std::string text;


	Button(); // This is a default constructor (takes no parameters)

	Button(float x, float y, float w, float h);

    Button(float x, float y, float w, float h, std::string text);

	Button(float x, float y, float w, float h, float red, float green, float blue, std::string text);

	void draw();

	bool isClicked(float x, float y);



	void renderText(std::string text, 
    float x, 
    float y, 
    void* font, 
    float r, 
    float g, 
    float b);


};




#endif