#ifndef App_h
#define App_h

#include "GlutApp.h"
#include "Game.h"
#include "TitleScreen.h"

class App: public GlutApp {

private:

    Game* game;
    TitleScreen* titleScreen;

    //A part of App because it is needed by both game and titlescreen
    int currLvl;


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
