#pragma once

#include <game/game.hpp>

class Menu {
public:
    Menu(SDL_Renderer* renderer, SDL_Window* window, Game* thisGame);
    ~Menu() = default;
    
    void Run();
    
    void HandleEvents();
    void Update();
    void Render();

private:
    SDL_Renderer* renderer;
    SDL_Window* window;
    Game* thisGame;
    int counter = 0;
    bool inMenu = 1;
} ;
