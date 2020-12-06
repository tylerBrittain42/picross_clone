#ifndef App_h
#define App_h

#include <vector>
#include "GlutApp.h"
#include "FbFboard.h"
#include "Help.h"
#include "Display.h"
#include "WinState.h"

class App: public GlutApp {

private:

    FbFboard* playerBoard;
    Help* hintBoard;
    Display* display;
    WinState* hasWon;

public:

    App(int argc, char** argv, int width, int height, const char* title);
    
    void draw() const;
    
    void keyDown(unsigned char key, float x, float y);

    void leftMouseDown(float mx, float my);

    void rightMouseDown(float mx, float my);

    void idle();
    
    ~App();
};

#endif
