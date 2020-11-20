#include "Tile.h"
#include "GlutApp.h"
#include <iostream>
#include <cmath> 

/*Tile represents a single picross tile.
 *claimedBY values indicate the choice that the user has made regarding the tile
 *e = empty
 *c = claimed
 *x = avoided
*/

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

//Since tiles are square, the height and width should always be the same value
Tile::Tile(float x, float y, float side){
	this->x = x;
	this->y = y;
	w = side;
	h = side;
	r = 1;
	g = 0;
	b = 0;
	claimedBy = 'e';
}

//Draws the tile as well as the claimed decision
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
		drawC();
	}
	else if (claimedBy == 'x'){
		drawX();
	}
	


}

//Draws an X
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

//Fills in 95% of a claimed tile
//Note: using ratios to scale 95% with size of tile
void Tile::drawC() const{
	
	glColor3f(1,1,1);

	glBegin(GL_POLYGON);

	glVertex2f((x + std::abs(w*0.05)), (y - std::abs(h*0.05)));
	glVertex2f((x+w - std::abs(w*0.05)), (y - std::abs(h*0.05)));
	glVertex2f((x+w - std::abs(w*0.05)), ((y-h) + std::abs(h*0.05)));
	glVertex2f((x + std::abs(w*0.05)), (y-h) + std::abs(h*0.05));
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

Tile::~Tile(){

}