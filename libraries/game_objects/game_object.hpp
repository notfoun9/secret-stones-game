#pragma once

#include <game/game.hpp>
#include <texture_manager/texture_manager.hpp>

class GameObject;

class Button;
class Mouse;
class Field;
class Tile;
class Card;
class Hand;
class Deck;
class Pull;


class GameObject {
public:
    GameObject() = default;
    GameObject(const char* textureSheet);
    virtual ~GameObject() = default;

    virtual void Update();
    virtual void Render();

    void setBoarders(int x1, int y1, int x2, int y2);
    void setPos(int x1, int y1, int x2, int y2);
    SDL_Rect srcRect;
    SDL_Rect destRect;
protected:
    SDL_Texture* objTexture = nullptr;
} ;


class Button : public GameObject {
public:
    Button(const char* defaultStateTexture, const char* selectedStateTexture);
    ~Button() = default;

    virtual void Update();
    void checkSelected(Mouse* mouse);
    bool selected = 0;
private:
    SDL_Texture* defaultStateTexture = nullptr;
    SDL_Texture* selectedStateTexture = nullptr;
} ;

class Mouse : public GameObject {
public:
    Mouse();
    ~Mouse() = default;

    void Render();

    SDL_Rect cursor;
    SDL_Rect tip;
} ; 

class Field : public GameObject {
public:
    Field();
    ~Field();

    void Update();
    void Render();

    enum Tiles {GR_WH_1, GR_WH_2, GR_WH_3, BLU_PUR_1, BLU_PUR_2, BLU_PUR_3, RED_OR_1, RED_OR_2, BLA_YEL_1};
    enum colors {GREEN, WHITE, BLUE, PURPLE, RED, ORANGE, BLACK, YELLOW};
    Tile* positions[9];
    void constructRandomField();
private:

    Tile* allTiles[9];
} ;

class Tile : public GameObject {
public:
    Tile(const char* side1, const char* side2, int colintor1, int color2);
    ~Tile() = default;

    int GetActiveColor();
    SDL_Texture* GetActiveSide();
    void Flip();

    void Select();
private:

    SDL_Texture* side1 = nullptr;
    SDL_Texture* side2 = nullptr;
    int color1;
    int color2;

    int activeColor = color1;
    SDL_Texture** activeSide = &side1;
} ;

class Card : public GameObject {
public: 
    Card();
    ~Card();

    virtual void Update();
    void checkSelected(Mouse* mouse);
    bool selected = 0;

    enum colors {GREEN, WHITE, BLUE, PURPLE, RED, ORANGE, BLACK, YELLOW};
private:

} ;

class Hand : public GameObject {
public: 
    Hand();
    ~Hand();

    void Fill();

    Card* cardsInHand[4];
private:
    Deck* deck;
    short size = 0;
} ;

class Deck : public GameObject {
public:
    Deck();
    ~Deck();

    void Shuffle();

    Card* cardsInDeck[4];
private:
    Pull* pull;
    short size = 0;
} ;

class Pull : public GameObject {
public:
    Pull();
    ~Pull();

    Card* points_1[8];
    Card* points_2[4];
    Card* points_3[3];
    Card* points_5[1];
} ;