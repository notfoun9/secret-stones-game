#pragma once

#include <game_objects/game_object.hpp>
#include <conditions/conditions.hpp>

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
    Card* points_2[8];
    Card* points_3[8];
    Card* points_5[5];
} ;