#include "Help.h"
#include <iostream>
#include <algorithm>
#include <string>


Help::Help(){
    
   std::cout << "WARNING: no puzzle given";

    
};

Help::Help(char key[5][5], float x, float y, float sideLength,float r, float g, float b){
    
    //sets the help key equal to the key passed in
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            this->key[i][j] = key[i][j];
        }
    }


    this->sideLength = sideLength;
    this->x = x;
    this->y = y;

    this->r = r;
    this->g = g;
    this->b = b;

   


    //Creates hint arrays for each
    generateLeftHints();

    curX = x + (4 *(sideLength+0.01));
    curY = (y + sideLength) + 0.05/3;
    
    generateTopHints();
    
};


//Calculates the numeric values needed for each hint tile
void Help::calculateLeftValues(){


    std::vector<int> curRow;
    int count = 0;

    //row -- top to bottoms
    for(int i = 0; i < 5; i++){
        
        //column -- right to left (BACKWARDS)
        for(int j = 4; j >= 0; j--){

            //counting the number of consecutive claimed spaces
            if(key[i][j] == 'c'){
                count++;
            }
            
            //triggers once a series of spaces ends
            else{
                //ensures an empty row is not stored
                if(count != 0){
                    curRow.push_back(count);
                    count = 0;
                }
            }
    
        }
        //makes sure the final count value is added if it is not zero
        if(count != 0)
            curRow.push_back(count);
        
        //Added the row to our left vector
        leftVal.push_back(curRow);
        curRow.clear();
        count = 0;
    }

};

//Creates the left side hint tiles
void Help::generateLeftHints(){

    calculateLeftValues();

    //figure out how to reverse this formula
    //curX = (x - sideLength*3) - 0.05;
    curY = y;
    curX = -0.18;


    for(int i = 0; i < leftVal.size(); i++){

        for(int j = 0; j < (leftVal[i]).size(); j++){

            tempVec.push_back(new WordRect(curX,curY,sideLength,r,g,b,std::to_string(leftVal[i][j]),true));
            curX = curX - sideLength - 0.01;
        }

        curX = -0.18;
        curY = curY - (sideLength + 0.01);

        leftHints.push_back(tempVec);
        tempVec.clear();

    }
}



void Help::calculateTopValues(){

    int count = 0;
    std::vector<int> curCol;

    //we are still treating this as a 5x3 similar to calculateLeftValues
    
    //Iterating columns left to right
    for(int j = 0; j < 5; j++){
        
        //Iterating rows bottom to top
        for(int i = 4; i >= 0; i--){

            //counting the number of consecutive claimed spaces
            if(key[i][j] == 'c'){
                count++;
            }
            
            //triggers once a series of spaces ends
            else{
                //ensures an empty row is not stored
                if(count != 0){
                    curCol.push_back(count);
                    count = 0;
                }
            }
    
        }
        //makes sure the final count value is added if it is not zero
        if(count != 0)
            curCol.push_back(count);
        
        //Added the row to our left vector
        topVal.push_back(curCol);
        curCol.clear();
        count = 0;
    }


}


void Help::generateTopHints(){

    calculateTopValues();

    curY = 0.326667 - sideLength - 0.01;
    curX = x;

    for(int i = 0; i < topVal.size(); i++){

        for(int j = 0; j < (topVal[i]).size(); j++){
            tempVec.push_back(new WordRect(curX,curY,sideLength,r,g,b,std::to_string(topVal[i][j]),true));
            curY = curY + (sideLength + 0.01);
        }
        
        curY = 0.326667 - sideLength - 0.01;
        curX = curX + sideLength + 0.01;
        topHints.push_back(tempVec);
        tempVec.clear();

    }
}





void Help::draw() const{

   for(int i = 0; i < leftHints.size(); i++){
        for(int j = 0; j < (leftHints[i]).size(); j++){
            leftHints[i][j]->draw();}
    } 


    for(int i = 0; i < topHints.size(); i++){
        for(int j = 0; j < (topHints[i]).size(); j++){
            topHints[i][j]->draw();}
    }


}

Help::~Help(){
    
    for(int i = 0; i < topHints.size(); i++){
        for(int j = 0; j < (topHints[i]).size(); j++){
            delete topHints[i][j];
        }
    }

    for(int i = 0; i < leftHints.size(); i++){
        for(int j = 0; j < (leftHints[i]).size(); j++){
            delete leftHints[i][j];
        }
    }

    for(auto i = tempVec.begin(); i != tempVec.end(); i++){
        delete *i;
    }

};






