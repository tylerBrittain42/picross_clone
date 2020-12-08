#ifndef App_h
#define App_h

#include <vector>
#include "GlutApp.h"
#include "Game.h"
#include "TitleScreen.h"

class App: public GlutApp {

private:

    Game* game;
    TitleScreen* titleScreen;


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
