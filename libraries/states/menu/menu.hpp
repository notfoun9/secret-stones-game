#pragma once

#include <game/game.hpp>
#include <interface_objects/interface_objects.hpp>

class Menu {
public:
    Menu(SDL_Renderer* renderer, SDL_Window* window, Game* thisGame);
    ~Menu();
    
    void Run();
    
    void HandleEvents();
    void Update();
    void Render();

    Mouse* mouse = new Mouse();

    enum ButtonNames {START, RULES, EXIT};
    Button* button[3];
private:
    SDL_Renderer* renderer;
    SDL_Window* window;
    Game* thisGame;
} ;
