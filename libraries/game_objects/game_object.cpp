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


Button::Button (const char* defaultTexture, const char* selectedTexture) {
    defaultStateTexture = TextureManager::LoadTexture(defaultTexture);
    selectedStateTexture = TextureManager::LoadTexture(selectedTexture);
}
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
    for (int i = 0; i < 8; ++i) {
        points_1[i] = new Card("../../assets/blankCard.png","../../assets/blankCard.png");
    }
    for (int i = 0; i < 4; ++i) {
        points_2[i] = new Card("../../assets/blankCard.png","../../assets/blankCard.png");
    }
    for (int i = 0; i < 3; ++i) {
        points_3[i] = new Card("../../assets/blankCard.png","../../assets/blankCard.png");
    }
    for (int i = 0; i < 1; ++i) {
        points_5[i] = new Card("../../assets/blankCard.png","../../assets/blankCard.png");
    }
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
    return points_1[cardNo];
}
Card* Pull::Take2() {
    srand(time(0));
    int cardNo = rand() % 4;
    while (takenCards.find(points_2[cardNo]) != takenCards.end()) {
        cardNo = rand() % 4;
    }
    return points_2[cardNo];    
}
Card* Pull::Take3() {
    srand(time(0));
    int cardNo = rand() % 3;
    while (takenCards.find(points_3[cardNo]) != takenCards.end()) {
        cardNo = rand() % 3;
    }
    return points_3[cardNo];    
}
Card* Pull::Take5() {
    srand(time(0));
    int cardNo = rand() % 1;
    while (takenCards.find(points_5[cardNo]) != takenCards.end()) {
        cardNo = rand() % 1;
    }
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
    for (auto card : cards) {
        std::cout << card.first << '\n';
        cardsInDeck.push(card.second);
    }
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
    return card;
}
bool Deck::Empty() {
    return cardsInDeck.empty();
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

Hand::Hand(Deck* deck_, Trash* trash_) : trash(trash_), deck(deck_), size(4) {
    for (int i = 0; i < size; ++i) {
        cardsInHand.push_back(deck->Take());
    }
}
void Hand::Push() {
    int numOfcards = cardsInHand.size();
    int nullpts = 0;
    for (auto card : cardsInHand) {
        if (card == nullptr) ++nullpts;
    }
    if (numOfcards > 4 && nullpts > 0) {
        for (int i = 0, j = size; i < j; ) {
            while (cardsInHand[i] != nullptr) ++i;
            while (cardsInHand[j] == nullptr) --j;
            std::swap(cardsInHand[i], cardsInHand[j]);
        }
    }
    cardsInHand.resize(std::max(numOfcards - nullpts, 0));
    size = cardsInHand.size();
}
void Hand::Fill() {
    Push();
    if (size < 4 && deck->Empty()) {
        delete deck;
        deck = new Deck(trash);
    }
    if (size < 4) {
        size = 4;
        for (Card* card : cardsInHand) {
            if (card == nullptr && !deck->Empty()) {
                card = deck->Take();
            }
        }
    }
}
void Hand::Update(Mouse* mouse) {
    if (size == 4) {
        if (cardsInHand[0]) {
            cardsInHand[0]->setPos(0, 0, 64, 96);
        }
        if (cardsInHand[1]) {
            cardsInHand[1]->setPos(64, 0, 64, 96);
        }
        if (cardsInHand[2]) {
            cardsInHand[2]->setPos(128, 0, 64, 96);
        }
        if (cardsInHand[3]) {
            cardsInHand[3]->setPos(192, 0, 64, 96);
        }
    }
    // for (auto card : cardsInHand) {
    //     card->Update(mouse);
    // }
}
void Hand::Render() {
    for (auto card : cardsInHand) {
        // std::cout << card->destRect.x << ' ' << card->destRect.y << ' ' << 
        card->Render();
    }
}

Card::Card(const char* defaultTexture, const char* selectedTexture) {
    srcRect = {0,0, 127, 192};
    defaultStateTexture = TextureManager::LoadTexture(defaultTexture);
    selectedStateTexture = TextureManager::LoadTexture(selectedTexture);
    objTexture = defaultStateTexture;
}