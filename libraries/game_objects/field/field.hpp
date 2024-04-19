#pragma once 

#include <card/card.hpp>

class Tile;

class Field : public GameObject {
public:
    Field();
    ~Field();

    void Update(Mouse* mouse);
    void Render();
    void SwapCards(int i, int j);
    std::vector<int> GetStatus() const;

    enum Tiles {GR_WH_1, GR_WH_2, GR_WH_3, BLU_PUR_1, BLU_PUR_2, BLU_PUR_3, RED_OR_1, RED_OR_2, BLA_YEL_1};
    enum colors {WHITE, RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE, BLACK};
    Tile* positions[9];
    void constructRandomField();
private:

    Tile* allTiles[9];
} ;

class Tile : public Button {
public:
    Tile(const char* deSide1, const char* side1, const char* deSide2, const char* side2, int color1, int color2);
    ~Tile() = default;

    int GetActiveColor();
    SDL_Texture* GetActiveSide();
    void Flip();
    void Update(Mouse* mouse);

    void Select();
    void Click();
    void Unclick();
private:
    std::pair<SDL_Texture*, SDL_Texture*> side1 = {nullptr, nullptr};
    std::pair<SDL_Texture*, SDL_Texture*> side2 = {nullptr, nullptr};
    int color1;
    int color2;
    bool clicked = 0;

    int activeColor = color1;
    std::pair<SDL_Texture*, SDL_Texture*>* activeSide = &side1;
} ;