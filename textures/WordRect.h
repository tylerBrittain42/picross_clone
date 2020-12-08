#ifndef WORDRECT_H
#define WORDRECT_H

#include "Rect.h"
#include <string>

class WordRect:Rect{

private:

    int widthh = 640;
	std::string text;

    float tR;
    float tG;
    float tB;

protected:

    bool isCentered;

public:

	WordRect();
	WordRect(float x, float y, float side, float r, float g, float b, std::string text, bool isCentered);
    WordRect(float x, float y, float w, float h, float r, float g, float b, std::string text, bool isCentered);
    WordRect(float x, float y, float w, float h, float r, float g, float b, float tR, float tG, float tB, std::string text, bool isCentered);

	void draw() const;

    void renderText(std::string text, 
    float x, 
    float y, 
    void* font, 
    float r, 
    float g, 
    float b) const;


	void renderCenterText(std::string text, 
    float x, 
    float y, 
    void* font, 
    float r, 
    float g, 
    float b) const;

    std::string getText() const;

    void setText(std::string text); 

    void setColors(float r, float g, float b);


	~WordRect();

};

#endif
