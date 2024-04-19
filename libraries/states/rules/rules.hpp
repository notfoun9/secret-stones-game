#pragma once

#include <game/game.hpp>
#include <game_objects/game_objects.hpp>

class Rules {
public:
    Rules(SDL_Renderer* renderer, SDL_Window* window, Game* thisGame);
    ~Rules();
    
    void Run();
    
    void HandleEvents();
    void Update();
    void Render();

    Mouse* mouse = new Mouse();
    Button* goBack;

    GameObject* rules;
private:
    SDL_Renderer* renderer;
    SDL_Window* window;
    Game* thisGame;
} ;
