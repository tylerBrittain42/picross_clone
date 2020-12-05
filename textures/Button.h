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

	bool isCentered;

	std::string text;


	Button(); // This is a default constructor (takes no parameters)

	Button(float x, float y, float w, float h, bool);

    Button(float x, float y, float w, float h, std::string text, bool);

	Button(float x, float y, float w, float h, float red, float green, float blue, std::string text, bool);

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
