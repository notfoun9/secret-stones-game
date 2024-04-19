#include <party/party.hpp>
#include <vector>

void Party::StartNewParty() {
    pull->ClearTaken();
    field->constructRandomField();
    dropGetButton->Deselect();
    trash->Clear();

    delete deck;
    delete hand;
    
    deck = new Deck(pull);
    hand = new Hand(deck, trash);

    delete currentTurn;
    currentTurn = new Turn(field, deck, trash, hand, mouse);
    badTurns = 0;
}

Party::Party(SDL_Renderer* renderer_, SDL_Window* window_, Game* thisGame_, Pull* pull_) : renderer(renderer_), window(window_), thisGame(thisGame_), pull(pull_) {
    strikes[0] = TextureManager::LoadTexture("../../assets/strikes0.png");
    strikes[1] = TextureManager::LoadTexture("../../assets/strikes1.png");
    strikes[2] = TextureManager::LoadTexture("../../assets/strikes2.png");
    strikes[3] = TextureManager::LoadTexture("../../assets/strikes3.png");

    exitButton = new Button("../../assets/goBackButton.png", "../../assets/activeGoBack.png");;
    exitButton->setBoarders(0, 0, 34, 11);
    exitButton->setPos(30, 30, 220, 80);

    note = new GameObject("../../assets/note.png");
    note->setBoarders(0,0,149, 280);
    note->setPos(30, 140, 189, 340);

    endTurnButton = new Button("../../assets/endTurnButton.png", "../../assets/activeEndTurnButton.png");
    endTurnButton->setBoarders(0, 0, 64, 18);
    endTurnButton->setPos(30, 595, 250, 80);

    dropGetButton = new Switch("../../assets/dropGetButton.png", "../../assets/activeDropGetButton.png");
    dropGetButton->setBoarders(0,0,64,20);
    dropGetButton->setPos(30, 500, 250, 80);

    mouse = new Mouse();
    field = new Field();
    deck = new Deck(pull);
    trash = new Trash();
    hand = new Hand(deck, trash);

    currentTurn = new Turn(field, deck, trash, hand, mouse);
}
Party::~Party() {
    delete deck;
    delete trash;
    delete hand;

    for (auto s : strikes) delete s;
    delete currentTurn;
    delete exitButton;
    delete field;
    delete mouse;
}


void Party::Run() {
    StartNewParty();

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    uint32_t frameStart;
    int frameTime;

    while (thisGame->inParty) {
        frameStart = SDL_GetTicks();

        HandleEvents();
        Update();
        Render();

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }
}

void Party::HandleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT : {
                thisGame->inParty = 0;
                thisGame->quit();
                return;
            }
            case SDL_MOUSEBUTTONUP : {
                HandleMouseLeftClick();
            }
            default : break;
        }
    }
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    if (keystates[SDL_SCANCODE_ESCAPE]) {
        thisGame->inParty = 0;
        thisGame->quit();
    }
    if (keystates[SDL_SCANCODE_F12]) thisGame->toggleFullscreen();
    SDL_GetMouseState(&(mouse->cursor.x), &(mouse->cursor.y));
    SDL_GetMouseState(&(mouse->tip.x), &(mouse->tip.y));
}

void Party::HandleMouseLeftClick() {
    if (exitButton->selected) {
        thisGame->inParty = 0;
        thisGame->inMenu = 1;
        return;
    }
    if (endTurnButton->selected) {
        std::cout << "End turn" << '\n';
        if (!(currentTurn->GoodTurn())) {
            std::cout << "Turn Is Bad" << '\n';
            ++badTurns;
        }
        if (hand->Empty() && deck->Empty() && trash->Empty()) {
            std::cout << "YOU WIN!" << '\n';
            thisGame->isWin = 1;
            thisGame->inGameOver = 1;
            thisGame->inParty = 0;
        }
        else if (badTurns > 3) {
            std::cout << "GAME OVER" << '\n';
            thisGame->inGameOver = 1;
            thisGame->inParty = 0;
        }
        delete currentTurn;
        currentTurn = new Turn(field, deck, trash, hand, mouse);
        hand->Fill();
        dropGetButton->Deselect();
        for (Tile *t : field->positions) {
            t->Unclick();
        }
        return;
    }
    if (dropGetButton->checkSelected(mouse)) {
        dropGetButton->Click();
        currentTurn->ToogleWaitForDrop();
        return;
    }
    currentTurn->HandleEvents();
}

void Party::Update() {
    exitButton->Update(mouse);
    dropGetButton->Update(mouse);

    endTurnButton->Update(mouse);
    field->Update(mouse);
    hand->Update(mouse);
    mouse->Update();
}

void Party::Render() {
    SDL_RenderClear(renderer);

    if (badTurns < 4) SDL_RenderCopy(Game::renderer, strikes[badTurns], NULL, &strikesDest);
    dropGetButton->Render();
    note->Render();
    endTurnButton->Render();
    exitButton->Render();

    trash->Render();
    deck->Render();
    field->Render();
    hand->Render();
    mouse->Render();
    SDL_RenderPresent(renderer);
}

void Party::EndDropAction() {
    dropGetButton->Deselect();
}