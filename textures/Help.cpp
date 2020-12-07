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
    
    topCountt = generateTop(key);

    setTopHint();
    
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



std::vector<int> Help::generateTop(char key[5][5]){
    std::vector<int> gen;
    gen.push_back(9);
    int count = 0;
    for(int j = 0; j < 5; j++) {
        for(int i = 0; i < 5; i++){
            if (key[i][j] == 'c')
                count++;
            else{
                
                if(count != 0)
                    gen.push_back(count);

                count = 0;
            }   
        }
        if(count != 0)
            gen.push_back(count);
        gen.push_back(9);
        count = 0;
    }
    gen.pop_back();

    std::reverse(gen.begin(),gen.end());

    //example of how to do it
    //testLeft.push_back(gen);
    //std::cout << testLeft[0][1] << std::endl;


    std::vector<int> curCol;


    //we are still freating this as a 5x3 similar to calculateLeftValues
    
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
        TestTopVal.push_back(curCol);
        curCol.clear();
        count = 0;
    }


    for(int i = 0; i < TestTopVal.size(); i++){
        
        //column -- right to left (BACKWARDS)
        for(int j = 0; j < (TestTopVal[i]).size(); j++){
            std::cout << TestTopVal[i][j] << " " ;
        }
        std::cout<<std::endl;
    }

    return(gen);
}

void Help::setTopHint(){

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            topHints.push_back(new WordRect(curX,curY,sideLength,r,g,b, "",true));
            curX = curX - (sideLength + 0.01);
                        std::cout << "X: " << curX << std::endl;

        }
        curX = x + (4 *(sideLength+0.01));
        curY = curY + (sideLength + 0.01);
        std::cout << curY << std::endl;
    }

    int cur = 0;
    for(int j = 0; j < 5; j ++){
        for(int i = 0; i < 15; i++){
            if(i%5 == j){
                if(topCountt[cur] != 9){
                    topHints[i]->setText(std::to_string(topCountt[cur]));
                    cur++;
                }
                else
                {
                     topHints[i]->setText("");
                     topHints[i]->setColors(0,0,0);
                }
                
            }
        }
        cur++;
    }


    curY = 0.326667 - sideLength - 0.01;
    curX = x;

    for(int i = 0; i < TestTopVal.size(); i++){

        for(int j = 0; j < (TestTopVal[i]).size(); j++){
            std::cout << TestTopVal[i][j] << " ";
            tempVec.push_back(new WordRect(curX,curY,sideLength,r,g,b,std::to_string(TestTopVal[i][j]),true));
            curY = curY + (sideLength + 0.01);
        }
        std::cout << std::endl;

        
        curY = 0.326667 - sideLength - 0.01;
        curX = curX + sideLength + 0.01;
        TestTopHints.push_back(tempVec);
        tempVec.clear();

    }






}





void Help::draw() const{
  /*   for(auto i = topHints.begin(); i != topHints.end(); i++){
        (*i)->draw();
    }

   for(int i = 0; i < leftHints.size(); i++){
        for(int j = 0; j < (leftHints[i]).size(); j++){
            leftHints[i][j]->draw();}
    } 

*/
    for(int i = 0; i < TestTopHints.size(); i++){
        for(int j = 0; j < (TestTopHints[i]).size(); j++){
            TestTopHints[i][j]->draw();}
    }


}

Help::~Help(){
    
    for(auto i = topHints.begin(); i != topHints.end(); i++){
        delete *i;
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






