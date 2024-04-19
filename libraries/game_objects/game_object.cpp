#include <game_objects/game_objects.hpp>
#include "../../src/inc/SDL2/SDL_image.h"

GameObject::GameObject(const char* textureSheet) {
    objTexture = TextureManager::LoadTexture(textureSheet);
}
void GameObject::setPos(int x1, int y1, int x2, int y2) {
    destRect.x = x1;
    destRect.y = y1;
    destRect.w = x2;
    destRect.h = y2;
}
void GameObject::setBoarders(int x1, int y1, int x2, int y2) {
    srcRect.x = x1;
    srcRect.y = y1;
    srcRect.w = x2;
    srcRect.h = y2;
}
void GameObject::Render() {
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
void GameObject::Update() {}
SDL_Texture* GameObject::GetTexture() {
    return objTexture;
}


Button::Button (const char* defaultTexture, const char* selectedTexture) : 
    defaultStateTexture(TextureManager::LoadTexture(defaultTexture)), 
    selectedStateTexture(TextureManager::LoadTexture(selectedTexture)) {}
void Button::Update(Mouse* mouse) {
    checkSelected(mouse);
    if (selected) {
        objTexture = selectedStateTexture;
    }
    else {
        objTexture = defaultStateTexture;
    }
}
void Button::checkSelected(Mouse* mouse) {
    if (SDL_HasIntersection(&(mouse->tip), &destRect)) {
        selected = true;
    }
    else {
        selected = false;
    }
}

Switch::Switch(const char* defaultStateTexture_, const char* selectedStateTexture) :
    defaultStateTexture(TextureManager::LoadTexture(defaultStateTexture_)),
    activetateTexture(TextureManager::LoadTexture(selectedStateTexture)) {}
bool Switch::checkSelected(Mouse* mouse) {
    if (SDL_HasIntersection(&(mouse->tip), &destRect)) return true;
    return false;
}
void Switch::Update(Mouse* mouse) {
    if (active) {
        objTexture = activetateTexture;
    }
    else {
        objTexture = defaultStateTexture;
    }
} 
void Switch::Click() {
    active = !active;
}
void Switch::Deselect() {
    active = 0;
}

Mouse::Mouse() {
    objTexture = TextureManager::LoadTexture("../../assets/mouses.png");
    setBoarders(7, 12, 28, 32);
    tip = {0, 0, 2, 2};
    cursor = {0, 0, 50, 50};
} 
void Mouse::Render() {
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &cursor);
}

Field::Field() {
    allTiles[GR_WH_1] = new Tile("../../assets/deselectedGreen.png", "../../assets/selectedGreen.png", "../../assets/deselectedWhite.png","../../assets/selectedWhite.png",  GREEN, WHITE);
    allTiles[GR_WH_2] = new Tile("../../assets/deselectedGreen.png", "../../assets/selectedGreen.png", "../../assets/deselectedWhite.png","../../assets/selectedWhite.png", GREEN, WHITE);
    allTiles[GR_WH_3] = new Tile("../../assets/deselectedGreen.png", "../../assets/selectedGreen.png", "../../assets/deselectedWhite.png","../../assets/selectedWhite.png", GREEN, WHITE);
    allTiles[BLU_PUR_1] = new Tile("../../assets/deselectedBlue.png", "../../assets/selectedBlue.png", "../../assets/deselectedPurple.png","../../assets/selectedPurple.png", BLUE, PURPLE);
    allTiles[BLU_PUR_2] = new Tile("../../assets/deselectedBlue.png", "../../assets/selectedBlue.png", "../../assets/deselectedPurple.png","../../assets/selectedPurple.png", BLUE, PURPLE);
    allTiles[BLU_PUR_3] = new Tile("../../assets/deselectedBlue.png", "../../assets/selectedBlue.png", "../../assets/deselectedPurple.png","../../assets/selectedPurple.png", BLUE, PURPLE);
    allTiles[RED_OR_1] = new Tile("../../assets/deselectedRed.png", "../../assets/selectedRed.png", "../../assets/deselectedOrange.png","../../assets/selectedOrange.png", RED, ORANGE);
    allTiles[RED_OR_2] = new Tile("../../assets/deselectedRed.png", "../../assets/selectedRed.png", "../../assets/deselectedOrange.png","../../assets/selectedOrange.png", RED, ORANGE);
    allTiles[BLA_YEL_1] = new Tile("../../assets/deselectedBlack.png", "../../assets/selectedBlack.png", "../../assets/deselectedYellow.png","../../assets/selectedYellow.png", BLACK, YELLOW);

    constructRandomField();
}
Field::~Field() {
    for (Tile* t : allTiles) {
        delete t;
    }
}
void Field::Update(Mouse* mouse) {
    positions[0]->setPos(300,30,150,150);
    positions[1]->setPos(450,30,150,150);
    positions[2]->setPos(600,30,150,150);
    positions[3]->setPos(300,180,150,150);
    positions[4]->setPos(450,180,150,150);
    positions[5]->setPos(600,180,150,150);
    positions[6]->setPos(300,330,150,150);
    positions[7]->setPos(450,330,150,150);
    positions[8]->setPos(600,330,150,150);
    for (Tile* t : positions) {
        t->Update(mouse);
    }
}
void Field::Render() {
    for (Tile* t : positions) {
        SDL_RenderCopy(Game::renderer, t->GetActiveSide(), NULL, &(t->destRect));
    }
}
void Field::constructRandomField() {
    srand(time(0)); 

    for (Tile* tile : allTiles) {
        int a = rand() % 2;
        if (a == 1) {
            tile->Flip();
        } 
        tile->Unclick();
    }

    std::vector<std::pair<int, Tile*>> seq(9); 
    for (int i = 0; i < 9; ++i) {
        seq[i].first = rand() % 100;
        seq[i].second = allTiles[i];
    }
    std::sort(seq.begin(), seq.end(), 
        [](std::pair<int, Tile*> a, std::pair<int, Tile*> b) {
            return a.first < b.first;
        } );
    for (int i = 0; i < 9; ++i) {
        positions[i] = seq[i].second;
    }

    positions[0]->setPos(300,30,150,150);
    positions[1]->setPos(450,30,150,150);
    positions[2]->setPos(600,30,150,150);
    positions[3]->setPos(300,180,150,150);
    positions[4]->setPos(450,180,150,150);
    positions[5]->setPos(600,180,150,150);
    positions[6]->setPos(300,330,150,150);
    positions[7]->setPos(450,330,150,150);
    positions[8]->setPos(600,330,150,150);
}   
void Field::SwapCards(int i, int j) {
    Tile* tmp = positions[i];
    positions[i] = positions[j];
    positions[j] = tmp;
}
std::vector<int> Field::GetStatus() const {
    std::vector<int> status;
    for (Tile* tile : positions) {
        status.push_back(tile->GetActiveColor());
    }
    return status;
}

Tile::Tile(const char* deSide1_, const char* side1_, const char* deSide2_, const char* side2_, int color1_, int color2_) 
: color1(color1_), color2(color2_) {
    side1 = {TextureManager::LoadTexture(deSide1_), TextureManager::LoadTexture(side1_)};
    side2 = {TextureManager::LoadTexture(deSide2_), TextureManager::LoadTexture(side2_)};
}
int Tile::GetActiveColor() {
    return activeColor;
}
SDL_Texture* Tile::GetActiveSide() {
    if (selected || clicked) return activeSide->second;
    return activeSide->first;
}  
void Tile::Update(Mouse* mouse) {
    checkSelected(mouse);
} 
void Tile::Flip() {
    if (activeColor == color1) {
        activeSide = &side2;
        activeColor = color2;
    }
    else {
        activeSide = &side1;
        activeColor = color1;
    }
}
void Tile::Select() {
    return;
}
void Tile::Click() {
    clicked =  1;
}
void Tile::Unclick() {
    clicked = 0;
}

Deck::Deck(Pull* pull) {   
    objTexture = TextureManager::LoadTexture("../../assets/deck.png");
    setBoarders(0,0, 128, 192);
    setPos(760, 283, 128, 192); 
    srand(time(0));
    std::vector<std::pair<int, Card*>> cards;
    for (int i = 0; i < 8; ++i) {
        cards.push_back({rand() % 100, pull->Take1()});
    }
    for (int i = 0; i < 4; ++i) {
        cards.push_back({rand() % 100, pull->Take2()});
    }
    for (int i = 0; i < 3; ++i) {
        cards.push_back({rand() % 100, pull->Take3()});
    }
    for (int i = 0; i < 1; ++i) {
        cards.push_back({rand() % 100, pull->Take5()});
    }
    std::sort(cards.begin(), cards.end(), [](std::pair<int, Card*> a, std::pair<int, Card*> b) {
        return a.first > b.first;
    } );
    for (auto card : cards) {
        cardsInDeck.push(card.second);
    }
    std::cout << '\n';
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
    if (!Empty()) SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

Trash::Trash() {
    setBoarders(0,0, 128, 192);
    setPos(900, 190, 128, 192);
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
        objTexture = cards.back()->GetTexture();
        SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
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