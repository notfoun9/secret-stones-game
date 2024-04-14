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
    void update();
    void render();
    void clean();
    
    bool running();

    void toggleFullscreen();
private:
    int counter = 0;
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool fullscreen_ = 0;
} ;



#endif 