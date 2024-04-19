#include <conditions/conditions.hpp>

enum colors {WHITE, RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE, BLACK};

Conditions::Conditions() : 
    conditions_1({Card_1_0, Card_1_1, Card_1_2, Card_1_3, Card_1_4, Card_1_5, Card_1_6, 
                  Card_1_7, Card_1_8, Card_1_9, Card_1_10, Card_1_11, Card_1_12, Card_1_13, 
                  Card_1_14, Card_1_15, Card_1_16, Card_1_17, Card_1_18, Card_1_19, Card_1_20,
                  Card_1_21, Card_1_22, Card_1_23,Card_1_24, Card_1_25, Card_1_26, Card_1_27}),
    conditions_2({Card_2_0, Card_2_1, Card_2_2, Card_2_3, Card_2_4, Card_2_5, Card_2_6, Card_2_7}), 
    conditions_3({Card_3_0, Card_3_1, Card_3_2, Card_3_3, Card_3_4, Card_3_5, Card_3_6, Card_3_7}), 
    conditions_5({Card_5_0, Card_5_1, Card_5_2, Card_5_3, Card_5_4}) {}

void Conditions::GiveCondition(Card* card, int cost, int num) {
    switch (cost) {
        case 1 : return card->SetCondition(conditions_1[num]);
        case 2 : return card->SetCondition(conditions_2[num]);
        case 3 : return card->SetCondition(conditions_3[num]);
        case 5 : return card->SetCondition(conditions_5[num]);
        default: break;
    }
}


bool Card_1_0(const std::vector<int>& field) {
    for (int i = 0; i < 6; ++i) {
        if (field[i] == GREEN && field[i + 3] == PURPLE) {
            return 1;
        }
    }
    return 0;
};
bool Card_1_1(const std::vector<int>& field) {
    for (int i = 0; i < 6; ++i) {
        if (field[i] == GREEN && field[i + 3] == RED) {
            return 1;
        }
    }
    return 0;
}
bool Card_1_2(const std::vector<int>& field) {
    for (int i : {0,1,3,4,6,7}) {
        if (field[i] == WHITE && field[i + 1] == GREEN) {
            return 1;
        }
    }
    return 0;
}
bool Card_1_3(const std::vector<int>& field) {
    for (int i : {0,1,3,4,6,7}) {
        if (field[i] == BLUE && field[i + 1] == PURPLE) {
            return 1;
        }
    }
    return 0;
}
bool Card_1_4(const std::vector<int>& field) {
    for (int i = 0; i < 6; ++i) {
        if (field[i] == BLUE && field[i + 3] == WHITE) {
            return 1;
        }
    }
    return 0;
}
bool Card_1_5(const std::vector<int>& field) {
    for (int i = 0; i < 6; ++i) {
        if (field[i] == WHITE && field[i + 3] == WHITE) {
            return 1;
        }
    }
    return 0;
}
bool Card_1_6(const std::vector<int>& field) {
    for (int i = 0; i < 6; ++i) {
        if (field[i] == PURPLE && field[i + 3] == BLUE) {
            return 1;
        }
    }
    return 0;
}
bool Card_1_7(const std::vector<int>& field) {
    for (int i = 0; i < 6; ++i) {
        if (field[i] == BLUE && field[i + 3] == ORANGE) {
            return 1;
        }
    }
    return 0;
}
bool Card_1_8(const std::vector<int>& field) {
    for (int i = 0; i < 6; ++i) {
        if (field[i] == ORANGE && field[i + 3] == PURPLE) {
            return 1;
        }
    }
    return 0;
}
bool Card_1_9(const std::vector<int>& field) {
    for (int i : {0,1,3,4}) {
        if (field[i] == GREEN && field[i + 4] == PURPLE) {
            return 1;
        }
    }
    return 0;
}
bool Card_1_10(const std::vector<int>& field) {
    for (int i = 0; i < 6; ++i) {
        if (field[i] == GREEN && field[i + 3] == WHITE) {
            return 1;
        }
    }
    return 0;
}
bool Card_1_11(const std::vector<int>& field) {
    return field[4] == ORANGE;
}
bool Card_1_12(const std::vector<int>& field) {
    for (int i : {0,1,3,4,6,7}) {
        if (field[i] == PURPLE && field[i + 1] == PURPLE) {
            return 1;
        }
    }
    return 0;
}
bool Card_1_13(const std::vector<int>& field) {
    for (int i : {0,1,3,4,6,7}) {
        if (field[i] == WHITE && field[i + 1] == ORANGE) {
            return 1;
        }
    }
    return 0;
}
bool Card_1_14(const std::vector<int>& field) {
    for (int i : {0,1,3,4,6,7}) {
        if (field[i] == WHITE && field[i + 1] == BLUE) {
            return 1;
        }
    }
    return 0;
}
bool Card_1_15(const std::vector<int>& field) {
    for (int i : {0,1,3,4,6,7}) {
        if (field[i] == BLUE && field[i + 1] == RED) {
            return 1;
        }
    }
    return 0;
}
bool Card_1_16(const std::vector<int>& field) {
    for (int i : {0,1,3,4,6,7}) {
        if (field[i] == ORANGE && field[i + 1] == GREEN) {
            return 1;
        }
    }
    return 0;
}
bool Card_1_17(const std::vector<int>& field) {
    for (int i = 0; i < 6; ++i) {
        if (field[i] == WHITE && field[i + 3] == GREEN) {
            return 1;
        }
    }
    return 0;
}
bool Card_1_18(const std::vector<int>& field) {
    for (int i : {0,1,3,4,6,7}) {
        if (field[i] == GREEN && field[i + 1] == PURPLE) {
            return 1;
        }
    }
    return 0;
}
bool Card_1_19(const std::vector<int>& field) {
    for (int i : {0,1,3,4,6,7}) {
        if (field[i] == PURPLE && field[i + 1] == BLUE) {
            return 1;
        }
    }
    return 0;
}
bool Card_1_20(const std::vector<int>& field) {
    for (int i = 0; i < 6; ++i) {
        if (field[i] == BLUE && field[i + 3] == BLUE) {
            return 1;
        }
    }
    return 0;
}
bool Card_1_21(const std::vector<int>& field) {
    return field[4] == RED;
}
bool Card_1_22(const std::vector<int>& field) {
    for (int i : {0,1,3,4,6,7}) {
        if (field[i] == GREEN && field[i + 1] == GREEN) {
            return 1;
        }
    }
    return 0;
}
bool Card_1_23(const std::vector<int>& field) {
    for (int i = 0; i < 6; ++i) {
        if (field[i] == RED && field[i + 3] == WHITE) {
            return 1;
        }
    }
    return 0;
}
bool Card_1_24(const std::vector<int>& field) {
    for (int i : {0,1,3,4,6,7}) {
        if (field[i] == RED && field[i + 1] == PURPLE) {
            return 1;
        }
    }
    return 0;
}
bool Card_1_25(const std::vector<int>& field) {
    for (int i : {1,2,4,5}) {
        if (field[i] == WHITE && field[i + 2] == BLUE) {
            return 1;
        }
    }
    return 0;
}
bool Card_1_26(const std::vector<int>& field) {
    for (int i = 0; i < 6; ++i) {
        if (field[i] == BLUE && field[i + 3] == PURPLE) {
            return 1;
        }
    }
    return 0;
}
bool Card_1_27(const std::vector<int>& field) {
    for (int i : {0,1,3,4,6,7}) {
        if (field[i] == GREEN && field[i + 1] == WHITE) {
            return 1;
        }
    }
    return 0;
}

bool Card_2_0(const std::vector<int>& field) {
    return field[8] == BLACK;
}
bool Card_2_1(const std::vector<int>& field) {
    for (int i : {6,7,8}) {
        if (field[i] == BLACK) return 1;
    }
    return 0;
}
bool Card_2_2(const std::vector<int>& field) {
    return (field[0] == GREEN && field[8] == ORANGE);
}
bool Card_2_3(const std::vector<int>& field) {
    for (int i : {0,1,3,4,6,7}) {
        if (field[i] == YELLOW && field[i + 1] == PURPLE) {
            return 1;
        }
    }
    return 0;
}
bool Card_2_4(const std::vector<int>& field) {
    for (int i : {0,3,6}) {
        if (field[i] == GREEN && field[i + 2] == WHITE) return 1;
    }
    return 0;
}
bool Card_2_5(const std::vector<int>& field) {
    for (int i : {0,1,2}) {
        if (field[i] == WHITE && field[i + 6] == RED) return 1;
    }
    return 0;
}
bool Card_2_6(const std::vector<int>& field) {
    for (int i : {0,1,3,4,6,7}) {
        if (field[i] == ORANGE && field[i + 1] == ORANGE) {
            return 1;
        }
    }
    return 0;
}
bool Card_2_7(const std::vector<int>& field) {
    for (int i : {0,1,3,4}) {
        if (field[i + 1] == GREEN && field[i + 3] == RED) return 1;
    }
    return 0;
}

bool Card_3_0(const std::vector<int>& field) {
    return (field[1] == WHITE && field[6] == WHITE && field[8] == WHITE);
}
bool Card_3_1(const std::vector<int>& field) {
    for (int i : {0,1,2}) {
        if (field[i] == ORANGE && field[i + 3] == GREEN && field[i + 6] == PURPLE) return 1;
    }
    return 0;
}
bool Card_3_2(const std::vector<int>& field) {
    for (int i : {0,3,6}) {
        if (field[i] == PURPLE && field[i + 1] == RED && field[i + 2] == WHITE) return 1;
    }
    return 0;
}
bool Card_3_3(const std::vector<int>& field) {
    for (int i : {0,1,2}) {
        if (field[i] == BLUE && field[i + 3] == BLUE && field[i + 6] == BLUE) return 1;
    }
    return 0;
}
bool Card_3_4(const std::vector<int>& field) {
    for (int i : {0,1,2}) {
        if (field[i] == ORANGE && field[i + 6] == ORANGE) return 1;
    }
    return 0;    
}
bool Card_3_5(const std::vector<int>& field) {
    for (int i : {0,1,3,4}) {
        if (field[i + 1] == BLUE && field[i + 3] == BLUE && field[i + 4] == BLACK) return 1;
    }
    return 0;
}
bool Card_3_6(const std::vector<int>& field) {
    for (int i : {0,1,2}) {
        if (field[i] == PURPLE && field[i + 3] == PURPLE && field[i + 6] == PURPLE) return 1;
    }
    return 0;
}
bool Card_3_7(const std::vector<int>& field) {
    for (int i : {0,3,6}) {
        if (field[i] == RED && field[i + 2] == RED) return 1;
    }
    return 0;
}


bool Card_5_0(const std::vector<int>& field) {
    return (field[1] == GREEN && field[3] == ORANGE && field[5] == ORANGE && field[7] == BLUE);
}
bool Card_5_1(const std::vector<int>& field) {
    return (field[1] == YELLOW && field[6] == RED && field[8] == RED);
}
bool Card_5_2(const std::vector<int>& field) {
    return (field[1] == WHITE && field[3] == PURPLE && field[5] == PURPLE && field[7] == BLACK);
}
bool Card_5_3(const std::vector<int>& field) {
    return (field[0] == PURPLE && field[2] == GREEN && field[6] == WHITE && field[8] == BLUE);
}
bool Card_5_4(const std::vector<int>& field) {
    return (field[0] == BLACK && field[4] == ORANGE && field[8] == ORANGE);
}
