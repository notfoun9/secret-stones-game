#pragma once

#ifndef Game_hpp
#define Game_hpp

#include "../../src/inc/SDL2/SDL.h"
#include "../../src/inc/SDL2/SDL_image.h"
#include "../../src/inc/SDL2/SDL_ttf.h"
#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

class Game {
public:
    Game();
    ~Game();

    void init(const char* title, int xPos, int yPos, int widht, int height, bool fullscreen);
    
    void handleEvents(); 
    void clean();
    
    bool running();
    void quit();

    void toggleFullscreen();
    static SDL_Renderer *renderer;

    bool inMenu = 1;
    bool inParty = 0;
    bool inRules = 0;
    bool inGameOver = 0;

    bool isWin = 0;
private:
    SDL_Window *window;

    bool isRunning = 1;
    bool fullscreen_ = 0;
} ;
#endif 