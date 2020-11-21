#include "App.h"
#include <iostream>
#include <vector>

int main(int argc, char** argv) {
    GlutApp* app = new App(argc, argv, 600, 600, "OpenGL Demo");

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

    //horizontal counter(works)
    int count = 0;
    for(int j = 0; j < 5; j++) {
        for(int i = 0; i < 5; i++){
            if (answerKey[j][i] == 'c')
                count++;
            else{
                
                if(count != 0)
                    horzCountt.push_back(count);

                count = 0;
            }   
        }
        if(count != 0)
            horzCountt.push_back(count);
        horzCountt.push_back(9);
        count = 0;
    }

    
    std::cout << "horz test" << std::endl;
    for(auto i = horzCountt.begin(); i != horzCountt.end(); i++){
        std::cout << *i << ' ';

    }
    std::cout << std::endl << std::endl;

    
    //vertical counter
    count = 0;
    for(int j = 0; j < 5; j++) {
        for(int i = 0; i < 5; i++){
            if (answerKey[i][j] == 'c')
                count++;
            else{
                
                if(count != 0)
                    vertCountt.push_back(count);

                count = 0;
            }   
        }
        if(count != 0)
            vertCountt.push_back(count);
        vertCountt.push_back(9);
        count = 0;
    }

    
    std::cout << "horz test" << std::endl;
    for(auto i = vertCountt.begin(); i != vertCountt.end(); i++){
        std::cout << *i << ' ';

    }
    std::cout << std::endl << std::endl;



    //app->run();

}
