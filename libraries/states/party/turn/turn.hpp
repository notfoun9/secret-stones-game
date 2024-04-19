#pragma once

#include <card/card.hpp>
#include <field/field.hpp>

class Turn {
public:
    Turn(Field* field, Deck* deck, Trash* trash, Hand* hand, Mouse* mouse);
    ~Turn() = default;

    void HandleEvents();
    void HandleTilesActions();
    void HandleDropAction();
    void HandleAchieveAction();

    void MakeAction();

    bool GoodTurn();
    void ToogleWaitForDrop();
    void UnwaitDrop();


    std::pair<Tile*, Tile*> selectedTiles = {nullptr, nullptr};
    std::pair<int, int> selectedTilesNums = {-1, -1};
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