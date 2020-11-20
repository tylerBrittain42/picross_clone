#ifndef TILE_H
#define TILE_H

#include "Shape.h"

class Tile: public Shape{
protected:
	float x;
	float y;
	float w;
	float h;
	float r;
	float g;
	float b;
	

public:
char claimedBy;
	Tile();
	Tile(float, float, float, float, float r=1, float g=0, float b=0);
	Tile(float x, float y);


	void draw(float z=0) const;
	void drawX() const;
	void drawC() const;

	void setY(float y);
	float getY() const;
	float getX() const;
	void setX(float x);
	char getClaimedBy() const;
	void SetClaimedBy(char claimedBy);


	bool contains(float, float) const;

	void onClick(float mx, float my);
};

#endif
