#include "Help.h"

#include <iostream>
#include <algorithm>





std::vector<Hint*> topHints;
std::vector<Hint*> leftHints;


Help::Help(){
    

    char key[5][5] = {{'e','c','e','c','c'},
                      {'c','c','e','c','e'},
                      {'e','b','e','e','e'},
                      {'c','e','e','e','c'}, 
                      {'e','c','c','c','e'}};

    leftCountt = generateLeft(key);
    topCountt = generateTop(key);

    //PLACEHOLDER VALS
    float sideLength = 0.15;
    float x = 0;
    float y = 0;

    //topical-----------------------
    float curX = x + (4 *(sideLength+0.01));
    float curY = (y + sideLength) + 0.05/3;
    //i controls row; j controls column
    int k = 1;
    for(int i = 0; i < 3; i++){

        for(int j = 0; j < 5; j++){
            topHints.push_back(new Hint(curX,curY,sideLength, std::to_string(k)));
            curX = curX - (sideLength + 0.01);
            k++;
            
            
        }
        curX = x + (4 *(sideLength+0.01));
        curY = curY + (sideLength + 0.01);
    }

//-----------------------------------------------------
    int cur = 0;
    for(int j = 0; j < 5; j ++){
        for(int i = 0; i < 15; i++){
            if(i%5 == j){
                if(topCountt[cur] != 9){
                    topHints[i]->setHintText(std::to_string(topCountt[cur]));
                    cur++;
                }
                else
                {
                    topHints[i]->setHintText("");
                     topHints[i]->r = 0;
                     topHints[i]->g = 0;
                     topHints[i]->b = 0;
                }
                
            }
        }
        cur++;
    }



    //LEFT-----------------------------------------------------------------------------------------------
    curX = (x - sideLength*3) - 0.05;
    curY = y;
    //i controls row; j controls column
    int countt = 0;
    for(int i = 0; i < 5; i++){

        for(int j = 0; j < 3; j++){
            leftHints.push_back(new Hint(curX,curY,sideLength, ""));
            
            curX = curX + (sideLength + 0.01);
            countt++;
        }
        curY = curY - (sideLength + 0.01);
        curX = (x - sideLength*3) - 0.05;;
    }

    cur = 0;
    
    //adding in hint vals---------------------------
    for(int i = 0; i < 14; i=i+3){

       for(int j = 0; j < 3; j++){
           if(leftCountt[cur] != 9){
               leftHints[i+j]->setHintText(std::to_string(leftCountt[cur]));
               cur++;
           }


       }
               std::cout << std::endl;

        while(leftHints[i+2]->getHintText() == "" && (leftHints[i+1]->getHintText() != "" || leftHints[i]->getHintText() != "")){
            leftHints[i+2]->setHintText(leftHints[i+1]->getHintText());
            leftHints[i+1]->setHintText(leftHints[i]->getHintText());
            leftHints[i]->setHintText("");

        }

       cur++;

    }

    for(auto i = leftHints.begin(); i != leftHints.end(); i++){
        if( (*i)->getHintText() == ""){

            (*i)->r = 0;
            (*i)->g = 0;
            (*i)->b = 0;
        }
    }


    
};

Help::Help(char key[5][5]){
    //come back
};


std::vector<int> Help::generateLeft(char key[5][5]){
    
    std::vector<int> gen;
    int count = 0;
    for(int j = 0; j < 5; j++) {
        for(int i = 0; i < 5; i++){
            if (key[j][i] == 'c')
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

    int start = 0;
    int end = 0;





    return(gen);
};



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



    return(gen);

};


bool Help::checkWin(std::vector<Tile*> fbf){
    
    int curTile = 0;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(key[i][j] == 'c' && fbf[curTile]->getClaimedBy() != 'c'){
                
                return(false);
             }
            curTile++;
        }    }
    return true;

};


void Help::draw() const{
    for(auto i = topHints.begin(); i != topHints.end(); i++){
        (*i)->draw();
    }
    for(auto i = leftHints.begin(); i != leftHints.end(); i++){
        (*i)->draw();
    }    
}

Help::~Help(){
    
    for(auto i = topHints.begin(); i != topHints.end(); i++){
        delete *i;
    }
    for(auto i = leftHints.begin(); i != leftHints.end(); i++){
        delete *i;
    }
};






