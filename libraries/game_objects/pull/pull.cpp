#include <pull/pull.hpp>
#include<conditions/conditions.hpp>

Pull::Pull(Conditions* conditions) {
    std::string cardID;
    for (int i = 0; i < 28; ++i) {
        std::string cardID = "../../assets/Card_1_" + std::to_string(i) + ".png";
        points_1[i] = new Card(cardID.data());
        conditions->GiveCondition(points_1[i], 1, i);
    }
    for (int i = 0; i < 8; ++i) {
        std::string cardID = "../../assets/Card_2_" + std::to_string(i) + ".png";
        points_2[i] = new Card(cardID.data());
        conditions->GiveCondition(points_2[i], 2, i);
    }
    for (int i = 0; i < 8; ++i) {
        std::string cardID = "../../assets/Card_3_" + std::to_string(i) + ".png";
        points_3[i] = new Card(cardID.data());
        conditions->GiveCondition(points_3[i], 3, i);
    }
    for (int i = 0; i < 5; ++i) {
        std::string cardID = "../../assets/Card_5_" + std::to_string(i) + ".png";
        points_5[i] = new Card(cardID.data());
        conditions->GiveCondition(points_5[i], 5, i);
    }
    std::cout << '\n';
}
Pull::~Pull() {
    for (auto card : points_1) {
        delete card;
    }
    for (auto card : points_2) {
        delete card;
    }
    for (auto card : points_3) {
        delete card;
    }
    for (auto card : points_5) {
        delete card;
    }
}
Card* Pull::Take1() {
    srand(time(0));
    int cardNo = rand() % 28;
    while (takenCards.find(points_1[cardNo]) != takenCards.end()) {
        cardNo = rand() % 28;
    }
    takenCards.insert(points_1[cardNo]);
    return points_1[cardNo];
}
Card* Pull::Take2() {
    srand(time(0));
    int cardNo = rand() % 8;
    while (takenCards.find(points_2[cardNo]) != takenCards.end()) {
        cardNo = rand() % 8;
    }
    takenCards.insert(points_2[cardNo]);
    return points_2[cardNo];    
}
Card* Pull::Take3() {
    srand(time(0));
    int cardNo = rand() % 8;
    while (takenCards.find(points_3[cardNo]) != takenCards.end()) {
        cardNo = rand() % 8;
    }
    takenCards.insert(points_3[cardNo]);
    return points_3[cardNo];    
}
Card* Pull::Take5() {
    srand(time(0));
    int cardNo = rand() % 5;
    while (takenCards.find(points_5[cardNo]) != takenCards.end()) {
        cardNo = rand() % 5;
    }
    takenCards.insert(points_5[cardNo]);
    return points_5[cardNo];    
}
void Pull::ClearTaken() {
    takenCards.clear();
}

