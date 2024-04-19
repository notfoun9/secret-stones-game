#pragma once

#include<interface_objects/interface_objects.hpp>
#include<field/field.hpp>
#include<pull/pull.hpp>
#include<conditions/conditions.hpp>

class Trash;
class Deck;
class Field;
class Pull;

class Card : public Button {
public: 
    Card(const char* texture);
    ~Card() = default;
    bool Usable(Field* field);
    void Drop(Trash* trash);
    void Update(Mouse* mouse);

    void Achieve();
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
    bool Empty();
    std::vector<Card*> cardsInHand;
private:
    Deck* deck;
    Trash* trash;
    short size = 0;
} ;

class Deck : public GameObject {
public:
    Deck(Pull* pull);
    ~Deck() = default;
    
    void Render();

    int Size();
    bool Empty();
    Card* Take();
    void Fill(Trash* trash);
private:
    std::stack<Card*> cardsInDeck;
} ;

class Trash : public GameObject {
public:
    Trash();
    ~Trash() = default;

    void Render();
    void Clear();
    void Add(Card* card);
    Card* Take();
    bool Empty();
    int Size();
private:
    std::vector<Card*> cards;
} ;