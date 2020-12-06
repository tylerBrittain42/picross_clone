#ifndef App_h
#define App_h

#include <vector>
#include "GlutApp.h"
#include "Rect.h"
#include "TexRect.h"
#include "Tile.h"
#include "FbFboard.h"
#include "Button.h"
#include "Help.h"
#include "Display.h"
#include "WinState.h"
#include "WordRect.h"

class App: public GlutApp {

std::vector<Tile*> shapes;


public:
    bool a;

    // std::vector<int> vertHints;
    // std::vector<int>horzHints;
    FbFboard* playerBoard;
    Help* hintBoard;
    Display* display;
    WinState* hasWon;

    App(int argc, char** argv, int width, int height, const char* title);
    
    void draw() const;
    
    void keyDown(unsigned char key, float x, float y);

    void leftMouseDown(float mx, float my);

    void rightMouseDown(float mx, float my);

    void idle();
    
    ~App();
};

#endif
