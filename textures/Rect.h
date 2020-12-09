#ifndef RECT_H
#define RECT_H

#include "Shape.h"

class Rect: public Shape{
protected:
	float x;
	float y;
	float w;
	float h;
	float r;
	float g;
	float b;


public:

	Rect();
	Rect(float, float, float, float, float r=1, float g=0, float b=0);
	Rect(float x, float y, float side);

	void draw(float z=0) const;

	void setY(float y);
	float getY() const;

	float getX() const;
	void setX(float x);

	void incX(float x);
	void incY(float y);

	float getH() const;
	float getW() const;

	void setR(float r);
	void setG(float g);
	void setB(float b);

	bool contains(float, float) const;

	~Rect();
};

#endif
