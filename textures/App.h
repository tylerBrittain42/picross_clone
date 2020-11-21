#ifndef App_h
#define App_h

#include <vector>
#include "GlutApp.h"
#include "Rect.h"
#include "Circle.h"
#include "TexRect.h"
#include "Tile.h"
#include "FbFboard.h"
#include "Hint.h"

class App: public GlutApp {

std::vector<Tile*> shapes;


public:

    FbFboard* board;
    Hint* hintTest;
    
    App(int argc, char** argv, int width, int height, const char* title);
    
    void draw() const;
    
    void keyDown(unsigned char key, float x, float y);

    void leftMouseDown(float mx, float my);

    void rightMouseDown(float mx, float my);
    
    ~App();
};

#endif
