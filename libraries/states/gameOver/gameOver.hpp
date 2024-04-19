#pragma once

#include <game/game.hpp>
#include <card/card.hpp>
#include <interface_objects/interface_objects.hpp>

class GameOver {
public:
    GameOver(SDL_Renderer* renderer, SDL_Window* window, Game* thisGame);
    ~GameOver();
    
    void Run();
    
    void HandleEvents();
    void Update();
    void Render();


private:
    Mouse* mouse = new Mouse();
    Button* goToMenu;
    GameObject* back;

    SDL_Renderer* renderer;
    SDL_Window* window;
    Game* thisGame;
} ;
