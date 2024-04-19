#pragma once

#include <game/game.hpp>
#include <game_objects/game_objects.hpp>
#include <turn/turn.hpp>
#include <pull/pull.hpp>

class Party {
public:
    Party(SDL_Renderer* renderer, SDL_Window* window, Game* thisGame, Pull* pull);
    ~Party();
    
    void Run();
    
    void HandleEvents();
    void HandleMouseLeftClick();
    void Update();
    void Render();
    void StartNewParty();
private:
    Mouse* mouse;
    Button* exitButton;
    Button* endTurnButton;
    Switch* dropGetButton;

    GameObject* note;
    Turn* currentTurn;

    int badTurns = 0;
    int Score = 0;
    Field* field = nullptr;

    SDL_Renderer* renderer;
    SDL_Window* window;
    Game* thisGame;

    Pull* pull;
    Deck* deck;
    Trash* trash;
    Hand* hand;
} ;
