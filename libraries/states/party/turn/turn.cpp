#include <turn/turn.hpp>

Turn::Turn(Field* field_, Deck* deck_, Trash* trash_, Hand* hand_, Mouse* mouse_) 
: field(field_), deck(deck_), trash(trash_), hand(hand_), mouse(mouse_) {
}   

bool Separated(int i, int j) {
    int sep = std::abs((i / 3) - (j / 3)) + std::abs((i % 3) - (j % 3));
    std::cout << "Distanse: " << sep << '\n';
    return sep > 1;
}

void Turn::HandleEvents() {
    if (isWaitingForDrop) {
        HandleDropAction();
    }
    else {
        HandleAchieveAction();
    }

    if (actionsAvailable > 0) {
        HandleTilesActions();
    }
}

void Turn::HandleDropAction() {
    for (Card* card : hand->cardsInHand) {
        if (card && card->selected) {
            hand->Remove(card);
            std::cout << "Card to remove is " << card << '\n';
            card->Drop(trash);
            ++actionsAvailable;
            std::cout << "Actions left: " << actionsAvailable << '\n';
            std::cout << "card dropped" << '\n';
            return;
        }
    }
}

void Turn::HandleAchieveAction() {
    for (Card* card : hand->cardsInHand) {
        if (card && card->selected) {
            std::cout << "Card is not achievable" << '\n';
        }
    }
}

void Turn::HandleTilesActions() {
    for (int i = 0; i < 9; ++i) {
        Tile* &tile = field->positions[i];
        if (tile->selected) {
            if (selectedTiles.first == nullptr) {
                selectedTiles.first = tile;
                selectedTilesNums.first = i;
            }
            else {
                selectedTiles.second = tile;
                selectedTilesNums.second = i;
                if (Separated(selectedTilesNums.first, selectedTilesNums.second)) {
                    std::cout << "Separated" << '\n';
                    selectedTiles = {nullptr, nullptr};
                    return;
                }
                MakeAction();
                --actionsAvailable;
                selectedTiles = {nullptr, nullptr};
            }
        }
    }
}

void Turn::MakeAction() {
    if (selectedTiles.first == selectedTiles.second) {
        selectedTiles.first->Flip();
    }
    else {
        field->SwapCards(selectedTilesNums.first, selectedTilesNums.second);
    }
}

void Turn::ToogleWaitForDrop() {
    isWaitingForDrop = !isWaitingForDrop;
    std::cout << isWaitingForDrop << '\n';
}
bool Turn::GoodTurn() {
    return !isGoodTurn;
}
void Turn::UnwaitDrop() {
    isWaitingForDrop = 0;
}