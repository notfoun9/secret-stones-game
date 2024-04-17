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
class Trash;
class Pull;


class GameObject {
public:
    GameObject() = default;
    GameObject(const char* textureSheet);
    virtual ~GameObject() = default;

    virtual void Update();
    virtual void Render();

    virtual void setBoarders(int x1, int y1, int x2, int y2);
    void setPos(int x1, int y1, int x2, int y2);
    SDL_Rect srcRect;
    SDL_Rect destRect;
protected:
    SDL_Texture* objTexture = nullptr;
} ;


class Button : public GameObject {
public:
    Button() = default;
    Button(const char* defaultStateTexture, const char* selectedStateTexture);
    virtual ~Button() = default;

    virtual void Update(Mouse* mouse);
    void checkSelected(Mouse* mouse);
    bool selected = 0;
protected:
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

    void Update(Mouse* mouse);
    void Render();

    enum Tiles {GR_WH_1, GR_WH_2, GR_WH_3, BLU_PUR_1, BLU_PUR_2, BLU_PUR_3, RED_OR_1, RED_OR_2, BLA_YEL_1};
    enum colors {GREEN, WHITE, BLUE, PURPLE, RED, ORANGE, BLACK, YELLOW};
    Tile* positions[9];
    void constructRandomField();
private:

    Tile* allTiles[9];
} ;

class Tile : public Button {
public:
    Tile(const char* side1, const char* side2, int colintor1, int color2);
    ~Tile() = default;

    int GetActiveColor();
    SDL_Texture* GetActiveSide();
    void Flip();
    void Update(Mouse* mouse);

    void Select();

private:
    SDL_Texture* side1 = nullptr;
    SDL_Texture* side2 = nullptr;
    int color1;
    int color2;

    int activeColor = color1;
    SDL_Texture** activeSide = &side1;
} ;

class Card : public Button {
public: 
    Card(const char* defaultTexture, const char* selectedTexture);
    ~Card() = default;
    bool Usable(Field* field);
    void Drop(Trash* trash);

    enum colors {GREEN, WHITE, BLUE, PURPLE, RED, ORANGE, BLACK, YELLOW};
    int num = 0;
} ;

class Hand : public GameObject {
public: 
    Hand(Deck* deck, Trash* trash);
    ~Hand() = default;

    void Render();
    void Update(Mouse* mouse);
    void Fill();
    void addCard();
    void Push();
private:
    std::vector<Card*> cardsInHand;
    Deck* deck;
    Trash* trash;
    short size = 0;
} ;

class Deck : public GameObject {
public:
    Deck(Pull* pull);
    Deck(Trash*);
    ~Deck() = default;

    bool Empty();
    Card* Take();
private:
    std::stack<Card*> cardsInDeck;
} ;

class Trash : public GameObject {
public:
    Trash() = default;
    ~Trash() = default;

    void Clear();
    void Add(Card* card);
    Card* Take();
    bool Empty();
private:
    std::vector<Card*> cards;
} ;

class Pull : public GameObject {
public:
    Pull();
    ~Pull();
    
    Card* Take1();
    Card* Take2();
    Card* Take3();
    Card* Take5();

private:
    std::unordered_set<Card*> takenCards;

    Card* points_1[8];
    Card* points_2[4];
    Card* points_3[3];
    Card* points_5[1];
} ;