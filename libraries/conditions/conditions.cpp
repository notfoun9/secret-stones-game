#include <conditions/conditions.hpp>

enum colors {WHITE, RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE, BLACK};

Conditions::Conditions() : 
    conditions_1({Cards_N_N::Card_1_0, Cards_N_N::Card_1_1, Cards_N_N::Card_1_2, Cards_N_N::Card_1_3, Cards_N_N::Card_1_4, Cards_N_N::Card_1_5, Cards_N_N::Card_1_6, 
                  Cards_N_N::Card_1_7, Cards_N_N::Card_1_8, Cards_N_N::Card_1_9, Cards_N_N::Card_1_10, Cards_N_N::Card_1_11, Cards_N_N::Card_1_12, Cards_N_N::Card_1_13, 
                  Cards_N_N::Card_1_14, Cards_N_N::Card_1_15, Cards_N_N::Card_1_16, Cards_N_N::Card_1_17, Cards_N_N::Card_1_18, Cards_N_N::Card_1_19, Cards_N_N::Card_1_20,
                  Cards_N_N::Card_1_21, Cards_N_N::Card_1_22, Cards_N_N::Card_1_23, Cards_N_N::Card_1_24, Cards_N_N::Card_1_25, Cards_N_N::Card_1_26, Cards_N_N::Card_1_27}),
    conditions_2({Cards_N_N::Card_2_0, Cards_N_N::Card_2_1, Cards_N_N::Card_2_2, Cards_N_N::Card_2_3, Cards_N_N::Card_2_4, Cards_N_N::Card_2_5, Cards_N_N::Card_2_6, Cards_N_N::Card_2_7}), 
    conditions_3({Cards_N_N::Card_3_0, Cards_N_N::Card_3_1, Cards_N_N::Card_3_2, Cards_N_N::Card_3_3, Cards_N_N::Card_3_4, Cards_N_N::Card_3_5, Cards_N_N::Card_3_6, Cards_N_N::Card_3_7}), 
    conditions_5({Cards_N_N::Card_5_0, Cards_N_N::Card_5_1, Cards_N_N::Card_5_2, Cards_N_N::Card_5_3, Cards_N_N::Card_5_4}) {}

void Conditions::GiveCondition(Card* card, int cost, int num) {
    switch (cost) {
        case 1 : return card->SetCondition(conditions_1[num]);
        case 2 : return card->SetCondition(conditions_2[num]);
        case 3 : return card->SetCondition(conditions_3[num]);
        case 5 : return card->SetCondition(conditions_5[num]);
        default: break;
    }
}
