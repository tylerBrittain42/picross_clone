#include "Help.h"

#include <iostream>
#include <algorithm>





std::vector<Hint*> vertHints;
std::vector<Hint*> horzHints;


Help::Help(){
    

    char key[5][5] = {{'e','c','e','c','c'},
                      {'c','c','e','c','e'},
                      {'e','b','e','e','e'},
                      {'c','e','e','e','c'}, 
                      {'e','c','c','c','e'}};

    horzCountt = generateHoriz(key);
    vertCountt = generateVert(key);

    //PLACEHOLDER VALS
    float sideLength = 0.15;
    float x = 0;
    float y = 0;

    //vertical-----------------------
    float curX = x + (4 *(sideLength+0.01));
    //curY = (y + sideLength*3) + 0.05;
    float curY = (y + sideLength) + 0.05/3;
    //i controls row; j controls column
    int k = 1;
    for(int i = 0; i < 3; i++){

        for(int j = 0; j < 5; j++){
            vertHints.push_back(new Hint(curX,curY,sideLength, std::to_string(k)));
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
                if(vertCountt[cur] != 9){
                    vertHints[i]->getHintText() = std::to_string(vertCountt[cur]);
                    cur++;
                }
                else
                {
                    //COME BACK AND REMOVE HTIS
                    vertHints[i]->getHintText() = "";
                    // vertHints[i]->r = 0;
                    // vertHints[i]->g = 0;
                    // vertHints[i]->b = 0;
                }
                
            }
        }
        cur++;
    }



    //HORIZ-----------------------------------------------------------------------------------------------
    curX = (x - sideLength*3) - 0.05;
    curY = y;
    //i controls row; j controls column
    int countt = 0;
    for(int i = 0; i < 5; i++){

        for(int j = 0; j < 3; j++){
            //if(countt%3 == 0)
            horzHints.push_back(new Hint(curX,curY,sideLength, ""));//std::to_string(countt)));
            //else
            //{      horzHints.push_back(new Hint(curX,curY,sideLength, ("a")));}
            
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
           if(horzCountt[cur] != 9){
               std::cout << horzCountt[cur] <<  " ";
               horzHints[i+j]->setHintText() = std::to_string(horzCountt[cur]);
               std::cout <<std::endl << " hint text: " << horzHints[i+j]->getHintText() <<std::endl;
               cur++;
           }


       }
               std::cout << std::endl;

        while(horzHints[i+2]->getHintText() == "" && (horzHints[i+1]->getHintText() != "" || horzHints[i]->getHintText() != "")){
            horzHints[i+2]->getHintText() = horzHints[i+1]->getHintText();
            horzHints[i+1]->getHintText() = horzHints[i]->getHintText();
            horzHints[i]->getHintText() = "";

        }

       cur++;

    }


    
};

Help::Help(char key[5][5]){
    //come back
};


std::vector<int> Help::generateHoriz(char key[5][5]){
    
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

    //td::reverse(gen.begin(),gen.end());
    int start = 0;
    int end = 0;


    // std::cout << "horz" << std::endl;
    // for(auto i = gen.begin(); i != gen.end(); i++){
    //     std::cout << *i << ' ';
    // }



    return(gen);
};



std::vector<int> Help::generateVert(char key[5][5]){
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

    //std::reverse(gen.begin(),gen.end());
    //std::cout << "vert test" << std::endl;


    std::reverse(gen.begin(),gen.end());

    // std::cout << "vert" << std::endl;
    // for(auto i = gen.begin(); i != gen.end(); i++){
    //     std::cout << *i << ' ';
    // } 

    return(gen);

};


bool Help::checkWin(std::vector<Tile*> fbf){
    
    int curTile = 0;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            //printf("key: %c",  answerKey[i][j]); 
            //std::cout << "cur: "<< fbf[curTile]->getClaimedBy()<<std::endl;
            if(key[i][j] == 'c' && fbf[curTile]->getClaimedBy() != 'c'){
                
                return(false);
                
             }
            curTile++;
        }
        //std::cout << std::endl;
    }
    return true;

};


void Help::draw() const{
    for(auto i = vertHints.begin(); i != vertHints.end(); i++){
        //(*i)->draw();
    }
    for(auto i = horzHints.begin(); i != horzHints.end(); i++){
        (*i)->draw();
    }    
}

Help::~Help(){
    
    for(auto i = vertHints.begin(); i != vertHints.end(); i++){
        delete *i;
    }
    for(auto i = horzHints.begin(); i != horzHints.end(); i++){
        delete *i;
    }




};






