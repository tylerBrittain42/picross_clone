#include "FbFboard.h"
#include <iostream>




FbFboard::FbFboard(){

    
    sideLength = 0.25;
    curX = -1;
    curY = 1;

    for(int i = 0; i < 5; i++){

        for(int j = 0; j < 5; j++){
            fbf.push_back(new Tile(curX,curY,sideLength));
            curX = curX + (sideLength + 0.01);
        }
        curX = -1;
        curY = curY - (sideLength + 0.01);
    }


}

FbFboard::FbFboard(float x, float y, float sideLength){
    
    this->sideLength = sideLength;
    curX = x;
    curY = y;

    for(int i = 0; i < 5; i++){

        for(int j = 0; j < 5; j++){
            fbf.push_back(new Tile(curX,curY,sideLength));
            curX = curX + (sideLength + 0.01);
        }
        curX = x;
        curY = curY - (sideLength + 0.01);
    }

    //Horizontal
    curX = x;
    curY = (y + sideLength*3) + 0.05;
    //i controls row; j controls column
    for(int i = 0; i < 3; i++){

        for(int j = 0; j < 5; j++){
            vertHints.push_back(new Hint(curX,curY,sideLength, "1"));
            curX = curX + (sideLength + 0.01);
        }
        curX = x;
        curY = curY - (sideLength + 0.01);
    }

    //Vertical
    curX = (x - sideLength*3) - 0.05;
    curY = y;
    //i controls row; j controls column
    for(int i = 0; i < 5; i++){

        for(int j = 0; j < 3; j++){
            horzHints.push_back(new Hint(curX,curY,sideLength, "2"));
            curX = curX + (sideLength + 0.01);
        }
        curX = (x - sideLength*3) - 0.05;
        curY = curY - (sideLength + 0.01);
    }


    //---------------------------------------------------
     //This is for testing an answer key
    char answerKey[5][5] = {{'e','c','e','c','b'},
                            {'e','c','e','c','e'},
                            {'e','e','e','e','e'},
                            {'c','e','e','e','c'}, 
                            {'e','c','c','c','e'}};
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++){
            std::cout << answerKey[i][j];
        }
        std::cout << std::endl;
    }
    
    std::cout << std::endl << std::endl;

    std::vector<int> vertCountt;
    std::vector<int> horzCountt;

    horzCountt = generateHoriz(answerKey);
    vertCountt = generateVert(answerKey);
    
    


}

std::vector<int> FbFboard::generateHoriz(char key[5][5]){
       
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

    
    
    return(gen);

}

std::vector<int> FbFboard::generateVert(char key[5][5]){
       
    std::vector<int> gen;
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

    std::cout << "vert test" << std::endl;
    for(auto i = gen.begin(); i != gen.end(); i++){
        std::cout << *i << ' ';
    }
    
    return(gen);

}



void FbFboard::draw() const{
    for(auto i = fbf.begin(); i != fbf.end(); i++){
        (*i)->draw();
    }
    for(auto i = vertHints.begin(); i != vertHints.end(); i++){
        (*i)->draw();
    }    
    for(auto i = horzHints.begin(); i != horzHints.end(); i++){
        (*i)->draw();
    } 

}

void FbFboard::leftMouseDown(float mx, float my){

    for(auto i = fbf.begin(); i != fbf.end(); i++){
        if ((*i)->contains(mx,my) && (*i)->getClaimedBy() == 'c')
            (*i)->SetClaimedBy('e');
        else if ((*i)->contains(mx,my))
            (*i)->SetClaimedBy('c');
    }


}

void FbFboard::rightMouseDown(float mx, float my){

    for(auto i = fbf.begin(); i != fbf.end(); i++){
        if ((*i)->contains(mx,my) && (*i)->getClaimedBy() == 'x')
            (*i)->SetClaimedBy('e');
        else if ((*i)->contains(mx,my))
            (*i)->SetClaimedBy('x');
    }
}

FbFboard::~FbFboard(){
    for(auto i = fbf.begin(); i != fbf.end(); i++){
        delete *i;
    }
}


