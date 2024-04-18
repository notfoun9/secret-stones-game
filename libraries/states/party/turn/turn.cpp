#include <turn/turn.hpp>

Turn::Turn(Field* field_, Deck* deck_, Trash* trash_, Hand* hand_, Mouse* mouse_) 
: field(field_), deck(deck_), trash(trash_), hand(hand_), mouse(mouse_) {
}   


void Turn::HandleEvents() {
    for (Card* card : hand->cardsInHand) {
        if (card && card->selected && isWaitingForDrop && card->clicked) {
            hand->Remove(card);
            std::cout << "Card to remove is " << card << '\n';
            card->Drop(trash);
            ++actionsAvailable;
            std::cout << "card dropped" << '\n';
            return;
        }
    }
}
void Turn::Update() {

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