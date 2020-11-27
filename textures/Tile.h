#ifndef TILE_H
#define TILE_H

//#include "Rect.h"

class Tile{
private:
	float x;
	float y;
	float w;
	float l;
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
	void setX(float x);
	float getX() const;
	char getClaimedBy() const;
	void SetClaimedBy(char claimedBy);


	bool contains(float, float) const;

	~Tile();

};

#endif
