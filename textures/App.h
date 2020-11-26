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
#include "Button.h"

class App: public GlutApp {

std::vector<Tile*> shapes;


public:

    // std::vector<int> vertHints;
    // std::vector<int>horzHints;
    FbFboard* board;
    Hint* hintTest;
    Button* controls;
    Button* instructions;
    Button* gameName;
    Button* subName;
    Button* subTitle;
    Rect* helpBox;

    App(int argc, char** argv, int width, int height, const char* title);
    
    void draw() const;
    
    void keyDown(unsigned char key, float x, float y);

    void leftMouseDown(float mx, float my);

    void rightMouseDown(float mx, float my);
    
    ~App();
};

#endif
