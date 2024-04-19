#pragma once

#include <game/game.hpp>
#include <card/card.hpp>
#include <interface_objects/interface_objects.hpp>
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
    void EndDropAction();
private:
    Mouse* mouse;
    Button* exitButton;
    Button* endTurnButton;
    Switch* dropGetButton;

    GameObject* note;
    SDL_Texture* strikes[4];
    SDL_Rect strikesDest = {860, 495, 120, 120};
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
