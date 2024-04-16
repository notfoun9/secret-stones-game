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
    GameObject* note = new GameObject("../../assets/note.png");
private:
    Button* exitButton = new Button("../../assets/goBackButton.png", "../../assets/activeGoBack.png");;

    int Score = 0;
    Field* field = nullptr;

    SDL_Renderer* renderer;
    SDL_Window* window;
    Game* thisGame;
} ;
