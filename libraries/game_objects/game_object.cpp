#include <game_objects/game_object.hpp>
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
    allTiles[GR_WH_1] = new Tile("../../assets/gr.png", "../../assets/wh.png", GREEN, WHITE);
    allTiles[GR_WH_2] = new Tile("../../assets/gr.png", "../../assets/wh.png", GREEN, WHITE);
    allTiles[GR_WH_3] = new Tile("../../assets/gr.png", "../../assets/wh.png", GREEN, WHITE);
    allTiles[BLU_PUR_1] = new Tile("../../assets/blu.png", "../../assets/pur.png", BLUE, PURPLE);
    allTiles[BLU_PUR_2] = new Tile("../../assets/blu.png", "../../assets/pur.png", BLUE, PURPLE);
    allTiles[BLU_PUR_3] = new Tile("../../assets/blu.png", "../../assets/pur.png", BLUE, PURPLE);
    allTiles[RED_OR_1] = new Tile("../../assets/red.png", "../../assets/or.png", RED, ORANGE);
    allTiles[RED_OR_2] = new Tile("../../assets/red.png", "../../assets/or.png", RED, ORANGE);
    allTiles[BLA_YEL_1] = new Tile("../../assets/bla.png", "../../assets/yel.png", BLACK, YELLOW);

    constructRandomField();
}
Field::~Field() {
    for (Tile* t : allTiles) {
        delete t;
    }
}
void Field::Update(Mouse* mouse) {
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

    positions[0]->setPos(280,30,150,150);
    positions[1]->setPos(430,30,150,150);
    positions[2]->setPos(580,30,150,150);
    positions[3]->setPos(280,180,150,150);
    positions[4]->setPos(430,180,150,150);
    positions[5]->setPos(580,180,150,150);
    positions[6]->setPos(280,330,150,150);
    positions[7]->setPos(430,330,150,150);
    positions[8]->setPos(580,330,150,150);
}   

Tile::Tile(const char* side1_, const char* side2_, int color1_, int color2_) : color1(color1_), color2(color2_) {
    side1 = TextureManager::LoadTexture(side1_);
    side2 = TextureManager::LoadTexture(side2_);
}
int Tile::GetActiveColor() {
    return activeColor;
}
SDL_Texture* Tile::GetActiveSide() {
    return *activeSide;
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

Pull::Pull() {
    std::cout << "Pull has cards: " << '\n';
    for (int i = 0; i < 8; ++i) {
        points_1[i] = new Card("../../assets/unselectedBlankCard.png","../../assets/selectedBlankCard.png");
        std::cout << points_1[i] << '\n'; 
    }
    for (int i = 0; i < 4; ++i) {
        points_2[i] = new Card("../../assets/unselectedBlankCard.png","../../assets/selectedBlankCard.png");
        std::cout << points_2[i] << '\n';
    }
    for (int i = 0; i < 3; ++i) {
        points_3[i] = new Card("../../assets/unselectedBlankCard.png","../../assets/selectedBlankCard.png");
        std::cout << points_3[i] << '\n';
    }
    for (int i = 0; i < 1; ++i) {
        points_5[i] = new Card("../../assets/unselectedBlankCard.png","../../assets/selectedBlankCard.png");
        std::cout << points_5[i] << '\n';
    }
    std::cout << '\n';
}
Pull::~Pull() {
    for (auto card : points_1) {
        delete card;
    }
    for (auto card : points_2) {
        delete card;
    }
    for (auto card : points_3) {
        delete card;
    }
    for (auto card : points_5) {
        delete card;
    }
}
Card* Pull::Take1() {
    srand(time(0));
    int cardNo = rand() % 8;
    while (takenCards.find(points_1[cardNo]) != takenCards.end()) {
        cardNo = rand() % 8;
    }
    takenCards.insert(points_1[cardNo]);
    std::cout << points_1[cardNo] << "isTaken" << '\n';
    return points_1[cardNo];
}
Card* Pull::Take2() {
    srand(time(0));
    int cardNo = rand() % 4;
    while (takenCards.find(points_2[cardNo]) != takenCards.end()) {
        cardNo = rand() % 4;
    }
    takenCards.insert(points_2[cardNo]);
    std::cout << points_2[cardNo] << "isTaken" << '\n';
    return points_2[cardNo];    
}
Card* Pull::Take3() {
    srand(time(0));
    int cardNo = rand() % 3;
    while (takenCards.find(points_3[cardNo]) != takenCards.end()) {
        cardNo = rand() % 3;
    }
    takenCards.insert(points_3[cardNo]);
    std::cout << points_3[cardNo] << "isTaken" << '\n';
    return points_3[cardNo];    
}
Card* Pull::Take5() {
    srand(time(0));
    int cardNo = rand() % 1;
    while (takenCards.find(points_5[cardNo]) != takenCards.end()) {
        cardNo = rand() % 1;
    }
    takenCards.insert(points_5[cardNo]);
    std::cout << points_5[cardNo] << "isTaken" << '\n';
    return points_5[cardNo];    
}

Deck::Deck(Pull* pull) {   
    srand(time(0));
    std::vector<std::pair<int, Card*>> cards;
    for (int i = 0; i < 2; ++i) {
        cards.push_back({rand() % 100, pull->Take1()});
    }
    cards.push_back({rand() % 100, pull->Take2()});
    cards.push_back({rand() % 100, pull->Take3()});
    cards.push_back({rand() % 100, pull->Take5()});
    std::sort(cards.begin(), cards.end(), [](std::pair<int, Card*> a, std::pair<int, Card*> b) {
        return a.first > b.first;
    } );
    std::cout << "Deck has Cards: " << '\n';
    for (auto card : cards) {
        std::cout << card.second << '\n';
        cardsInDeck.push(card.second);
    }
    std::cout << '\n';
}
Deck::Deck(Trash* trash) {
    while (!trash->Empty()) {
        cardsInDeck.push(trash->Take());
    }
}
Card* Deck::Take() {
    if (cardsInDeck.empty()) return nullptr;
    
    Card* card = cardsInDeck.top();
    cardsInDeck.pop();
    std::cout << "Card taken from deck is " << card << '\n';
    return card;
}
bool Deck::Empty() {
    return cardsInDeck.empty();
}
int Deck::Size() {
    return cardsInDeck.size();
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

Hand::Hand(Deck* deck_, Trash* trash_) : trash(trash_), deck(deck_), size(4) {
    for (int i = 0; i < size; ++i) {
        cardsInHand.push_back(deck->Take());
    }
}
// void Hand::Push() {
//     int numOfcards = cardsInHand.size();
//     int nullpts = 0;
//     for (auto card : cardsInHand) {
//         if (card == nullptr) ++nullpts;
//     }
//     if (nullpts > 0) {
//         for (int i = 0, j = numOfcards; i < j; ++i, --j) {
//             while (cardsInHand[i] != nullptr && i < j) ++i;
//             while (cardsInHand[j] == nullptr && i < j) --j;
//             if (i < j) std::swap(cardsInHand[i], cardsInHand[j]);
//             std::cout << "reached123" << '\n';
//         }
//     }
//     size = numOfcards - nullpts;
//     cardsInHand.resize(std::max(int(size), 4));
// }
void Hand::Fill() {
    int nullpts = 0;
    for (auto card : cardsInHand) {
        if (card == nullptr) ++nullpts;
    }
    size -= nullpts;
    // if (size < 4 && deck->Empty() && !trash->Empty()) {
    //     delete deck;
    //     deck = new Deck(trash);
    // }
    if (size < 4 && (!deck->Empty() || !trash->Empty())) {
        size = 4;
        for (int i = 0; i < 4; ++i) {
            if (!cardsInHand[i] && !deck->Empty()) {
                cardsInHand[i] = deck->Take();
            }
        }
    }
}
void Hand::Update(Mouse* mouse) {
    if (size == 4) {
        for (int i = 0; i < 4; ++i) {
            if (cardsInHand[i]) {
                cardsInHand[i]->setPos(350 + 128 * i, 488, 128, 192);
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
            std::cout << "Card " << card << "is now nullptr" << '\n';
            card = nullptr;
            return;
        }
    }

}
void Hand::CheckClicks() {
    for (Card* card : cardsInHand) {
        if (card) {
            if (card->selected) {
                card->clicked = 1;
                return;
            }
        }
    }
}

Card::Card(const char* defaultTexture, const char* selectedTexture) {
    srcRect = {0,0, 127, 192};
    defaultStateTexture = TextureManager::LoadTexture(defaultTexture);
    selectedStateTexture = TextureManager::LoadTexture(selectedTexture);
    objTexture = defaultStateTexture;
}
void Card::Drop(Trash* trash) {
    trash->Add(this);
}
void Card::Update(Mouse* mouse) {
    checkSelected(mouse);
    if (selected) {
        objTexture = selectedStateTexture;
    }
    else {
        objTexture = defaultStateTexture;
    }
    clicked = 0;
}
