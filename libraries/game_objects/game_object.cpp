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
void Button::Update() {
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
void Field::Update() {
    for (Tile* t : positions) {
        
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



