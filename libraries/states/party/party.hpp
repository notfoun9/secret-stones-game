#pragma once

#include <game/game.hpp>
#include <game_objects/game_object.hpp>

class Party {
public:
    Party(SDL_Renderer* renderer, SDL_Window* window, Game* thisGame);
    ~Party();
    
    void Run();
    
    void HandleEvents();
    void Update();
    void Render();

    Mouse* mouse = new Mouse();
    GameObject* note;
private:
    Button* exitButton;

    int Score = 0;
    Field* field = nullptr;

    SDL_Renderer* renderer;
    SDL_Window* window;
    Game* thisGame;
} ;
