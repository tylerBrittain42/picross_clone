#ifndef TILE_H
#define TILE_H

#include "Rect.h"
#include <string>

class WordRect:Rect{

private:

    int widthh = 640;
	std::string text;

protected:

    bool isCentered;

public:

	WordRect();
	WordRect(float x, float y, float side, float r, float g, float b, std::string text, bool isCentered);


	void draw(float z=0) const;

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


	~WordRect();

};

#endif
