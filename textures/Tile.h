#ifndef TILE_H
#define TILE_H

#include "Rect.h"

class Tile:Rect{
private:
	char claimedBy;
	

public:

	Tile();
	Tile(float x, float y, float side, float r, float g, float b);


	void draw(float z=0) const;
	void drawX() const;
	void drawC() const;

	char getClaimedBy() const;
	void SetClaimedBy(char claimedBy);

	bool contains(float, float) const;

	~Tile();

};

#endif
