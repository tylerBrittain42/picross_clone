#include "FbFboard.h"
#include <iostream>
#include <string>




FbFboard::FbFboard(){

    
    sideLength = 0.25;
    curX = -1;
    curY = 1;




}

FbFboard::FbFboard(float x, float y, float sideLength){

    //---------------------------------------------------
     //This is for testing an answer key


    char answerKey[5][5] = {{'e','c','e','c','c'},
                            {'c','c','e','c','e'},
                            {'e','b','e','e','e'},
                            {'c','e','e','e','c'}, 
                            {'e','c','c','c','e'}};


                            
    // char answerKey[5][5] = {{'c','e','c','c','e'},make
    //                         {'e','c','e','c','e'},
    //                         {'c','e','c','c','e'},
    //                         {'e','c','e','c','e'}, 
    //                         {'c','e','c','c','e'}};

    std::vector<int> vertCountt;
    std::vector<int> horzCountt;

    horzCountt = generateHoriz(answerKey);
    vertCountt = generateVert(answerKey);
    //---------------------------------------------------


    
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


    //Horizontal
    //curX = x;
    curX = x + (4 *(sideLength+0.01));
    //curY = (y + sideLength*3) + 0.05;
    curY = (y + sideLength) + 0.05/3;
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
                    vertHints[i]->hintText = std::to_string(vertCountt[cur]);
                    cur++;
                }
                else
                {
                    //COME BACK AND REMOVE HTIS
                    vertHints[i]->hintText = "";
                    // vertHints[i]->r = 0;
                    // vertHints[i]->g = 0;
                    // vertHints[i]->b = 0;
                }
                
            }
        }
        cur++;
    }

//---------------------------------------------------
//attempting left
    //Vertical
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
               horzHints[i+j]->hintText = std::to_string(horzCountt[cur]);
               cur++;
           }

       }
        while(horzHints[i+2]->hintText == "" && (horzHints[i+1]->hintText != "" || horzHints[i]->hintText != "")){
            horzHints[i+2]->hintText = horzHints[i+1]->hintText;
            horzHints[i+1]->hintText = horzHints[i]->hintText;
            horzHints[i]->hintText = "";

        }

       cur++;

    }
   
    for(auto i = horzHints.begin(); i != horzHints.end(); i++){
        if( (*i)->hintText == ""){
            //COME BACK AND REMOVE THIS

            // (*i)->r = 0;
            // (*i)->g = 0;
            // (*i)->b = 0;
        }
    }



//     

//     cur = 0;
//     for(int j = 0; j < 5; j ++){
//         for(int i = 14; i >=0 ; i--){
//             if(i%5 == j){
                
//                 if(horzCountt[cur] != 9){
                    
//                     horzHints[i]->hintText = std::to_string(horzCountt[cur]);
//                     cur++;
//                 }
//                 else
//                 {

//                     horzHints[i]->hintText = "";
//                     horzHints[i]->r = 0;
//                     horzHints[i]->g = 0;
//                     horzHints[i]->b = 0;
//                 }
                
//             }
//         }
//         cur++;
//     }
//     std::string temp;
    
//     for(int mod = 0; mod < 5; mod++){
//         for(int i = 0; i < 10; i++){
//             if(i%5 == mod && (horzHints[i]->hintText != "9") && ((horzHints[i+5]->hintText) == "1") || (horzHints[i+5]->hintText == "2") || (horzHints[i+5]->hintText == "3")){
//                 temp = horzHints[i]->hintText;
//                 horzHints[i]->hintText = horzHints[i+5]->hintText;
//                 horzHints[i+5]->hintText = temp;

//             }


//         }
//     }
// //if we call it twice everything works for some reason
//     for(int mod = 0; mod < 5; mod++){
//         for(int j = 14; j >= 5; j--){
//             if(j % 5 == mod){
//                 //std::cout << (j) << " ";
//                 if (horzHints[j]->hintText == "" && horzHints[j-5]->hintText != ""){
//                                     //std::cout<< j << " " << (j-5)<< ": " << horzHints[j]->hintText << " " << horzHints[j-5]->hintText << std::endl;

                    
//                     temp = horzHints[j]->hintText;
//                     horzHints[j]->hintText = horzHints[j-5]->hintText;
//                     horzHints[j-5]->hintText = "";
//                 }
//             }
//         }
//         //std::cout << std::endl;
//     }


//     /*
//     for(int mod = 0; mod < 5; mod++){
//         for(int j = 14; j >= 5; j--){
//             if(j % 5 == mod){
//                 //std::cout << (j) << " ";
//                 if (horzHints[j]->hintText == "" && horzHints[j-5]->hintText != ""){
//                 std::cout<< j << " " << (j-5)<< ": " << horzHints[j]->hintText << " " << horzHints[j-5]->hintText << std::endl;

                    
//                     temp = horzHints[j]->hintText;
//                     horzHints[j]->hintText = horzHints[j-5]->hintText;
//                     horzHints[j-5]->hintText = "";
//                 }
//             }
//         }
//         //std::cout << std::endl;
//     }
//     */


//     cur = 0;
//     //std::cout << std::endl << std::endl;
//     for(int i = 0; i < 5; i++){
//         for(int j = 0; j < 3; j++){
//             //std::cout << horzHints[cur]->hintText ;
//             cur++;
//         }
//         //std::cout << std::endl;
//     }



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

    //td::reverse(gen.begin(),gen.end());
    int start = 0;
    int end = 0;


    

    // std::cout << "horz" << std::endl;
    // for(auto i = gen.begin(); i != gen.end(); i++){
    //     std::cout << *i << ' ';
    // }



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
    //std::cout << "vert test" << std::endl;


    std::reverse(gen.begin(),gen.end());
/*
    std::cout << "vert" << std::endl;
    for(auto i = gen.begin(); i != gen.end(); i++){
        std::cout << *i << ' ';
    } */

    return(gen);

}

bool FbFboard::isWin() {

    //printing both boards

    //Player Board
    std::cout << "PLAYER BOARD" << std::endl;
    for (int i = 0; i <= 15; i = i + 5){
        for(int j = 0; j < 5; j++){
            std::cout << fbf[i+j]->getClaimedBy() << " ";

        }
        std::cout << std::endl;
    }
    char answerKey[5][5] = {{'e','c','e','c','c'},
                            {'c','c','e','c','e'},
                            {'e','b','e','e','e'},
                            {'c','e','e','e','c'}, 
                            {'e','c','c','c','e'}};

    //answer key
    std::cout << std::endl << "Answer key" << std::endl;
    std::cout << "answer" << answerKey[0][0] <<  std::endl;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            std::cout << answerKey[i][j] << " ";
        }
        std::cout<< std::endl;
    }
    std::cout << std::endl;


    //std::cout<<"iswin called"<<std::endl;
    int curTile = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            //printf("key: %c",  answerKey[i][j]); 
            //std::cout << "cur: "<< fbf[curTile]->getClaimedBy()<<std::endl;
            if(answerKey[i][j] == 'c' && fbf[curTile]->getClaimedBy() != 'c'){
                
                return(false);
                
             }
            curTile++;
        }
        //std::cout << std::endl;
    }
    return true;


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

    if(isWin()){
        std::cout << "WIN" << std::endl;
    }
    else
        std::cout<<"not yet" << std::endl;

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


