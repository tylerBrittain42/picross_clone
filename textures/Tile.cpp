#include "Tile.h"
#include "GlutApp.h"
#include <iostream>

Tile::Tile(){
	x = 0;
	y = 0;
	w = 0.5;
	h = 0.5;
	r = 1;
	g = 0;
	b = 0;
	claimedBy = 'e';
}

Tile::Tile(float x, float y, float w, float h, float r, float g, float b){
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->r = r;
	this->g = g;
	this->b = b;
	claimedBy = 'e';
}

Tile::Tile(float x, float y){
	this->x = x;
	this->y = y;
	w = 0.25;
	h = 0.25;
	r = 1;
	g = 0;
	b = 0;
	claimedBy = 'e';
}

void Tile::draw(float z) const {
	
	glColor3f(r, g, b);

	glBegin(GL_POLYGON);

	glVertex2f(x, y);
	glVertex2f(x+w, y);
	glVertex2f(x+w, y-h);
	glVertex2f(x, y-h);
	glEnd();

	std::cout << claimedBy << std::endl;
	if (claimedBy == 'c'){

		std::cout << "triggered" << std::endl;
		drawC();
	}
	else if (claimedBy == 'x'){

		std::cout << "triggered" << std::endl;
		drawX();
	}


}

void Tile::drawX() const{
	glColor3f(1, 1, 1);

	glPointSize(10);
	glBegin(GL_LINES);
	glVertex2f(x,y);
	glVertex2f(x+w,y-h);
	glEnd();

	glPointSize(10);
	glBegin(GL_LINES);
	glVertex2f(x+w,y);
	glVertex2f(x,y-h);
	glEnd();

}

void Tile::drawC() const{
	
	glColor3f(1,1,1);

	glBegin(GL_POLYGON);

	glVertex2f(x + 0.005, y - 0.005);
	glVertex2f(x+w - 0.005, y - 0.005);
	glVertex2f(x+w - 0.005, y-h + 0.005);
	glVertex2f(x + 0.005, y-h + 0.005);
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


char Tile::getClaimedBy() const {
	return claimedBy;

}
void Tile::SetClaimedBy(char claimedBy){
	this->claimedBy = claimedBy;
}




bool Tile::contains(float x, float y) const{
	return x >= this->x && x <= this->x + w && y <= this->y && y >= this->y - h;
}

void Tile::onClick(float mx, float my){

};