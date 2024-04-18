#pragma once

#include <game_objects/game_object.hpp>

class Turn {
public:
    Turn(Field* field, Deck* deck, Trash* trash, Hand* hand, Mouse* mouse);
    ~Turn() = default;

    void Update();
    void HandleEvents();

    bool GoodTurn();
    void ToogleWaitForDrop();
    void UnwaitDrop();
private:
    short actionsAvailable = 0;
    bool isGoodTurn = 0;
    bool isWaitingForDrop = 0;


    Field* field;
    Deck* deck;
    Trash* trash;
    Hand* hand;
    Mouse* mouse;
} ;