#include <field/field.hpp>


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
