#pragma once
#include <game_objects/game_objects.hpp>

class Card;
class Conditions {
public:
    Conditions();
    ~Conditions() = default;

    void GiveCondition(Card* card, int cost, int num);
private:
    bool (*conditions_1[28]) (const std::vector<int>& field);
    bool (*conditions_2[8]) (const std::vector<int>& field);
    bool (*conditions_3[8]) (const std::vector<int>& field);
    bool (*conditions_5[5]) (const std::vector<int>& field) = {nullptr, nullptr};
} ;