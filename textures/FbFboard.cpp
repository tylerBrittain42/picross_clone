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

    //---------------------------------------------------
     //This is for testing an answer key
    char answerKey[5][5] = {{'e','c','e','c','e'},
                            {'e','c','e','c','e'},
                            {'e','b','e','e','e'},
                            {'c','e','e','e','c'}, 
                            {'e','c','c','c','e'}};

    std::vector<int> vertCountt;
    std::vector<int> horzCountt;

    horzCountt = generateHoriz(answerKey);
    vertCountt = generateVert(answerKey);
    //---------------------------------------------------

    std::cout << "past gen" << std::endl;


    
    this->sideLength = sideLength;
    curX = x;
    curY = y;
    currHint = 0;

    for(int i = 0; i < 5; i++){

        for(int j = 0; j < 5; j++){
            fbf.push_back(new Tile(curX,curY,sideLength));
            curX = curX + (sideLength + 0.01);
        }
        curX = x;
        curY = curY - (sideLength + 0.01);
    }

        std::cout << "past tile creation" << std::endl;


    //Horizontal
    //curX = x;
    curX = x + (4 *(sideLength+0.01));
    //curY = (y + sideLength*3) + 0.05;
    curY = (y + sideLength) + 0.05;
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
                std::cout << std::endl << vertHints[i]->hintText << " " << vertCountt[i];
                if(vertCountt[cur] != 9){
                    std::cout << " " << vertCountt[cur];
                    vertHints[i]->hintText = std::to_string(vertCountt[cur]);
                    cur++;
                }
                else
                {
                    std::cout << " 0";
                    vertHints[i]->hintText = "";
                    vertHints[i]->r = 0;
                    vertHints[i]->g = 0;
                    vertHints[i]->b = 0;
                }
                
            }
        }
        cur++;
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
    std::cout << "vert test" << std::endl;


    std::reverse(gen.begin(),gen.end());

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
    for(auto i = vertHints.begin(); i != vertHints.end(); i++){
        delete *i;
    }
    for(auto i = horzHints.begin(); i != horzHints.end(); i++){
        delete *i;
    }
}


