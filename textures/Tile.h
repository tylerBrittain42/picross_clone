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
	char claimedBy;
	

public:

	Tile();
	Tile(float x, float y, float side);


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

	~Tile();

};

#endif
