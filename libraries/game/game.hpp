#pragma once

#ifndef Game_hpp
#define Game_hpp

#include "../../src/inc/SDL2/SDL.h"
#include "../../src/inc/SDL2/SDL_image.h"
#include <iostream>
#include <thread>
#include <chrono>

class Game {
public:
    Game();
    ~Game();

    void init(const char* title, int xPos, int yPos, int widht, int height, bool fullscreen);
    
    void handleEvents(); 
    // void update();
    // void render();
    void clean();
    
    bool running();
    void quit();

    void toggleFullscreen();
    static SDL_Renderer *renderer;

    bool inMenu = 1;
    bool inParty = 0;
    bool inRules = 0;
private:
    SDL_Window *window;

    bool isRunning = 1;
    bool fullscreen_ = 0;
} ;



#endif 