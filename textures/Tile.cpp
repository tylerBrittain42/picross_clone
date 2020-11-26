#include "Tile.h"
#include "GlutApp.h"
#include <cmath> 

/*Tile represents a single picross tile.
 *claimedBY values indicate the choice that the user has made regarding the tile
 *e = empty
 *c = claimed
 *x = avoided
 *
 *Since tiles are squares, height and width are both represensented by a single length value called l
*/

//Default contructor 
Tile::Tile(){
	x = 0;
	y = 0;
	l = 0.5;
	r = 1;
	g = 0;
	b = 0;
	claimedBy = 'e';
}

Tile::Tile(float x, float y, float l){
	this->x = x;
	this->y = y;
	this->l = l;
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
	glVertex2f(x+l, y);
	glVertex2f(x+l, y-l);
	glVertex2f(x, y-l);
	glEnd();

	if (claimedBy == 'c'){
		drawC();
	}
	else if (claimedBy == 'x'){
		drawX();
	}
	


}

//Draws an X over the tile
void Tile::drawX() const{
	glColor3f(1, 1, 1);

	glPointSize(10);
	glBegin(GL_LINES);
	glVertex2f(x,y);
	glVertex2f(x+l,y-l);
	glEnd();

	glPointSize(10);
	glBegin(GL_LINES);
	glVertex2f(x+l,y);
	glVertex2f(x,y-l);
	glEnd();

}

//Fills in 95% of a claimed tile
void Tile::drawC() const{
	
	glColor3f(1,1,1);

	glBegin(GL_POLYGON);

	glVertex2f((x + std::abs(l*0.05)), (y - std::abs(l*0.05)));
	glVertex2f((x+l - std::abs(l*0.05)), (y - std::abs(l*0.05)));
	glVertex2f((x+l - std::abs(l*0.05)), ((y-l) + std::abs(l*0.05)));
	glVertex2f((x + std::abs(l*0.05)), (y-l) + std::abs(l*0.05));
	glEnd();
	
}


void Tile::setY(float y){
	this-> y = y;
}

float Tile::getY() const {
	return y;
}

void Tile::setX(float x){
	this-> x = x;
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
	return x >= this->x && x <= this->x + l && y <= this->y && y >= this->y - l;
}

Tile::~Tile(){

}