#pragma once

#include <game/game.hpp>
#include <game_objects/game_object.hpp>

class Menu {
public:
    Menu(SDL_Renderer* renderer, SDL_Window* window, Game* thisGame);
    ~Menu();
    
    void Run();
    
    void HandleEvents();
    void Update();
    void Render();

    Mouse* mouse = new Mouse();

    enum ButtonNames {START, OPTIONS, EXIT};
    Button* button[1];
private:
    SDL_Renderer* renderer;
    SDL_Window* window;
    Game* thisGame;
    int counter = 0;
    bool inMenu = 1;
} ;
