#include "Tile.h"
#include "GlutApp.h"

Tile::Tile(){
	x = 0;
	y = 0;
	w = 0.5;
	h = 0.5;
	r = 1;
	g = 0;
	b = 0;
}

Tile::Tile(float x, float y, float w, float h, float r, float g, float b){
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->r = r;
	this->g = g;
	this->b = b;
}

void Tile::draw(float z) const {
	glColor3f(r, g, b);

	glBegin(GL_POLYGON);

	glVertex2f(x, y);
	glVertex2f(x+w, y);
	glVertex2f(x+w, y-h);
	glVertex2f(x, y-h);

	glEnd();
}


void Tile::setY(float y){
	this-> y = y;
}

void Tile::setX(float x){
	this-> x = x;
}

float Tile::getY() const {
	return y;
}

float Tile::getX() const {
	return x;
}

bool Tile::contains(float x, float y) const{
	return x >= this->x && x <= this->x + w && y <= this->y && y >= this->y - h;
}

