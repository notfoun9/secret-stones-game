#include <card/card.hpp>

#include <field/field.hpp>
#include <interface/interface.hpp>
#include "../../src/inc/SDL2/SDL_image.h"

Deck::Deck(Pull* pull) {   
    objTexture = TextureManager::LoadTexture("../../assets/deck.png");
    cardsInDeckNum = new Text("../../assets/SomeFont.ttf", 22, {0,0,0,255});
    setBoarders(0,0, 128, 192);
    setPos(760, 283, 128, 192); 
    srand(time(0));
    std::vector<std::pair<int, Card*>> cards;
    for (int i = 0; i < 12; ++i) {
        cards.push_back({rand() % 100, pull->Take1()});
    }
    for (int i = 0; i < 6; ++i) {
        cards.push_back({rand() % 100, pull->Take2()});
    }
    for (int i = 0; i < 5; ++i) {
        cards.push_back({rand() % 100, pull->Take3()});
    }
    for (int i = 0; i < 2; ++i) {
        cards.push_back({rand() % 100, pull->Take5()});
    }
    std::sort(cards.begin(), cards.end(), [](std::pair<int, Card*> a, std::pair<int, Card*> b) {
        return a.first > b.first;
    } );
    for (auto card : cards) {
        cardsInDeck.push(card.second);
    }
}
void Deck::Fill(Trash* trash) {
    while (!trash->Empty()) {
        cardsInDeck.push(trash->Take());
    }
}
Card* Deck::Take() {
    if (cardsInDeck.empty()) return nullptr;
    
    Card* card = cardsInDeck.top();
    cardsInDeck.pop();
    return card;
}
bool Deck::Empty() {
    return cardsInDeck.empty();
}
int Deck::Size() {
    return cardsInDeck.size();
}
void Deck::Render() {
    cardsInDeckNum->SetMessage(std::to_string(Size()));
    if (Size() > 9) {
        cardsInDeckNum->SetDest(812,225);
    }
    else {
        cardsInDeckNum->SetDest(816,225);
    }
    if (!Empty()) {
        SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
        cardsInDeckNum->Update();
        cardsInDeckNum->Render();
    }
}

Trash::Trash() {
    cardsInTrash = new Text("../../assets/SomeFont.ttf", 22, {0,0,0,255});
    setBoarders(0,0, 128, 192);
    setPos(900, 277, 136, 204);
}
void Trash::Clear() {
    cards.clear();
}
void Trash::Add(Card* card) {
    cards.push_back(card);
}
Card* Trash::Take() {
    Card* card = cards.back();
    cards.pop_back();
    return card;
}
bool Trash::Empty() {
    return cards.empty();
}
int Trash::Size() {
    return cards.size();
}
void Trash::Render() {
    if (!Empty()) {
        cardsInTrash->SetMessage(std::to_string(Size()));
        if (Size() > 9) {
            cardsInTrash->SetDest(951,225);
        }
        else {
            cardsInTrash->SetDest(960,225);
        }
        objTexture = cards.back()->GetTexture();
        SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
        cardsInTrash->Update();
        cardsInTrash->Render();
    }
}

Hand::Hand(Deck* deck_, Trash* trash_) : trash(trash_), deck(deck_), size(4) {
    for (int i = 0; i < size; ++i) {
        cardsInHand.push_back(deck->Take());
    }
}

void Hand::Fill() {
    int nullpts = 0;
    for (auto card : cardsInHand) {
        if (card == nullptr) ++nullpts;
    }
    size -= nullpts;
    if (size < 4 && (!deck->Empty() || !trash->Empty())) {
        size = 4;
        for (int i = 0; i < 4; ++i) {
            if (deck->Empty() && trash->Empty()) {
                return;
            }
            if (deck->Empty()) {
                deck->Fill(trash);
            }
            if (!cardsInHand[i]) {
                cardsInHand[i] = deck->Take();
            }
        }
    }
}
void Hand::Update(Mouse* mouse) {
    if (size == 4) {
        for (int i = 0; i < 4; ++i) {
            if (cardsInHand[i]) {
                cardsInHand[i]->setPos(300 + 128 * i, 488, 128, 192);
            }
        }
    }
    for (auto card : cardsInHand) {
        if (card) card->Update(mouse);
    }
}
void Hand::Render() {
    for (auto card : cardsInHand) {
        if (card) card->Render();
    }
}
void Hand::Remove(Card* card_) {
    for (Card* &card : cardsInHand) {
        if (card == card_) {
            card = nullptr;
            return;
        }
    }

}
bool Hand::Empty() {
    short nullpts = 0;
    for (auto card : cardsInHand) {
        if (!card) ++nullpts;
    }
    return (cardsInHand.size() - nullpts == 0);
}

Card::Card(const char* texture) {
    srcRect = {0,0, 127, 192};
    objTexture = TextureManager::LoadTexture(texture);
}
void Card::Drop(Trash* trash) {
    trash->Add(this);
}
void Card::Update(Mouse* mouse) {
    checkSelected(mouse);
    if (selected) {
        destRect.y = 500;
    }
    else {
        destRect.y = 488;
    }
}
bool Card::CardIsAchievable(const Field* field) const {
    std::vector<int> CurrentFieldStatus = field->GetStatus();
    return cardCondition(CurrentFieldStatus);
}
void Card::SetCondition(bool (*condition)(const std::vector<int>& fieldStatus)) {
    cardCondition = condition;
}