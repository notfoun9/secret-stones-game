#pragma once

#include <card/card.hpp>
#include <interface/interface.hpp>

class Card;
class Conditions;
class Pull {
public:
    Pull(Conditions* conditions);
    ~Pull();
    
    Card* Take1();
    Card* Take2();
    Card* Take3();
    Card* Take5();
    void ClearTaken();
private:
    std::unordered_set<Card*> takenCards;

    Card* points_1[28];
    Card* points_2[19];
    Card* points_3[13];
    Card* points_5[5];
} ;
