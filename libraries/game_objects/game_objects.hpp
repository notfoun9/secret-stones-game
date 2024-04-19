#pragma once

#include <game/game.hpp>
#include <texture_manager/texture_manager.hpp>
#include <pull/pull.hpp>
#include <conditions/conditions.hpp>

class Pull;
class GameObject;
class Button;
class Mouse;
class Field;
class Tile;
class Card;
class Hand;
class Deck;
class Trash;

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

class Switch : public GameObject {
public:
    Switch(const char* defaultStateTexture, const char* selectedStateTexture);
    ~Switch() = default;

    bool checkSelected(Mouse* mouse);
    void Deselect();
    virtual void Update(Mouse* mouse);
    void Click();
private:
    bool active = 0;

    SDL_Texture* defaultStateTexture = nullptr;
    SDL_Texture* activetateTexture = nullptr;
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

class Card : public Button {
public: 
    Card(const char* defaultTexture, const char* selectedTexture);
    ~Card() = default;
    bool Usable(Field* field);
    void Drop(Trash* trash);
    void Update(Mouse* mouse);

    enum colors {WHITE, RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE, BLACK};
    bool CardIsAchievable(const Field* field) const;
    void SetCondition(bool (*)(const std::vector<int>& fieldStatus));
private:
    bool (*cardCondition)(const std::vector<int>& fieldStatus);
} ;

class Hand : public GameObject {
public: 
    Hand(Deck* deck, Trash* trash);
    ~Hand() = default;

    void Render();
    void CheckClicks();
    void Update(Mouse* mouse);
    void Fill();
    void addCard();
    void Push();
    void Remove(Card* card);
    std::vector<Card*> cardsInHand;
private:
    Deck* deck;
    Trash* trash;
    short size = 0;
} ;

class Deck : public GameObject {
public:
    Deck(Pull* pull);
    Deck(Trash*);
    ~Deck() = default;
    
    void Render();

    int Size();
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
    int Size();
private:
    std::vector<Card*> cards;
} ;