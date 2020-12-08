#include "Tile.h"


/*Tile represents a single picross tile.
 *claimedBY values indicate the choice that the user has made regarding the tile
 *e = empty
 *c = claimed
 *x = avoided
 *
 *Since tiles are squares, height and width are both represensented by a single length value called l
*/

Tile::Tile():Rect(0,0,0.5,0.5,1,0,0){
	claimedBy = 'e';
}

Tile::Tile(float x, float y, float l,float r,float g,float b):Rect(x,y,l,l,r,g,b){
	claimedBy = 'e';
}



//Draws the tile as well as the claimed decision
void Tile::draw(float z) const {
	
	Rect::draw();

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
	glVertex2f(x+w,y-w);
	glEnd();

	glPointSize(10);
	glBegin(GL_LINES);
	glVertex2f(x+w,y);
	glVertex2f(x,y-w);
	glEnd();

}

//Fills in 95% of a claimed tile
void Tile::drawC() const{
	
	glColor3f(1,1,1);

	glBegin(GL_POLYGON);

	glVertex2f((x + (w*0.05)), (y - (w*0.05)));
	glVertex2f((x+w - (w*0.05)), (y - (w*0.05)));
	glVertex2f((x+w - (w*0.05)), ((y-w) + (w*0.05)));
	glVertex2f((x + (w*0.05)), (y-w) + (w*0.05));
	glEnd();
	
}



char Tile::getClaimedBy() const {
	return claimedBy;
}

void Tile::SetClaimedBy(char claimedBy){
	this->claimedBy = claimedBy;
}

//Checks to see if the passed coordinates are within the tile
bool Tile::contains(float x, float y) const{
	return x >= this->x && x <= this->x + w && y <= this->y && y >= this->y - w;
}

Tile::~Tile(){

}