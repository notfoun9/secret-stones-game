#include <pull/pull.hpp>
#include <game_objects/game_object.hpp>
#include <conditions/conditions.hpp>


Pull::Pull(Conditions* conditions) {
    std::cout << "Pull has cards: " << '\n';
    for (int i = 0; i < 28; ++i) {
        points_1[i] = new Card("../../assets/unselectedBlankCard.png","../../assets/selectedBlankCard.png");
        conditions->GiveCondition(points_1[i], 1, i);
    }
    for (int i = 0; i < 8; ++i) {
        points_2[i] = new Card("../../assets/unselectedBlankCard.png","../../assets/selectedBlankCard.png");
        conditions->GiveCondition(points_2[i], 2, i);
    }
    for (int i = 0; i < 8; ++i) {
        points_3[i] = new Card("../../assets/unselectedBlankCard.png","../../assets/selectedBlankCard.png");
        conditions->GiveCondition(points_3[i], 3, i);
    }
    for (int i = 0; i < 5; ++i) {
        points_5[i] = new Card("../../assets/unselectedBlankCard.png","../../assets/selectedBlankCard.png");
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
    int cardNo = rand() % 8;
    while (takenCards.find(points_1[cardNo]) != takenCards.end()) {
        cardNo = rand() % 8;
    }
    takenCards.insert(points_1[cardNo]);
    std::cout << points_1[cardNo] << " isTaken 1" << '\n';
    return points_1[cardNo];
}
Card* Pull::Take2() {
    srand(time(0));
    int cardNo = rand() % 4;
    while (takenCards.find(points_2[cardNo]) != takenCards.end()) {
        std::cout << "somehow entered" << '\n';
        cardNo = rand() % 4;
    }
    takenCards.insert(points_2[cardNo]);
    std::cout << points_2[cardNo] << " isTaken 2" << '\n';
    return points_2[cardNo];    
}
Card* Pull::Take3() {
    srand(time(0));
    int cardNo = rand() % 3;
    while (takenCards.find(points_3[cardNo]) != takenCards.end()) {
        cardNo = rand() % 3;
    }
    takenCards.insert(points_3[cardNo]);
    std::cout << points_3[cardNo] << " isTaken 3" << '\n';
    return points_3[cardNo];    
}
Card* Pull::Take5() {
    srand(time(0));
    int cardNo = rand() % 1;
    while (takenCards.find(points_5[cardNo]) != takenCards.end()) {
        std::cout << "Aflasf"<< '\n';
        cardNo = rand() % 1;
    }
    takenCards.insert(points_5[cardNo]);
    return points_5[cardNo];    
}
void Pull::ClearTaken() {
    takenCards.clear();
}
