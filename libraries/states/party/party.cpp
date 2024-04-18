#include <party/party.hpp>
#include <vector>

void Party::StartNewParty() {
    field->constructRandomField();
    delete pull;
    delete deck;
    delete trash;
    delete hand;
    delete currentTurn;
    delete mouse;
    delete dropGetButton;
    {
     dropGetButton = new Switch("../../assets/dropGetButton.png", "../../assets/activeDropGetButton.png");
    dropGetButton->setBoarders(0,0,64,20);
    dropGetButton->setPos(780, 400, 250, 80);
    }
    pull = new Pull;
    deck = new Deck(pull);
    trash = new Trash();
    hand = new Hand(deck, trash);
    mouse = new Mouse();

    currentTurn = new Turn(field, deck, trash, hand, mouse);
    badTurns = 0;
    
}

Party::Party(SDL_Renderer* renderer_, SDL_Window* window_, Game* thisGame_) : renderer(renderer_), window(window_), thisGame(thisGame_) {
    exitButton = new Button("../../assets/goBackButton.png", "../../assets/activeGoBack.png");;
    exitButton->setBoarders(0, 0, 34, 11);
    exitButton->setPos(30, 30, 220, 80);

    note = new GameObject("../../assets/note.png");
    note->setBoarders(0,0,149, 280);
    note->setPos(30, 140, 189, 310);

    endTurnButton = new Button("../../assets/endTurnButton.png", "../../assets/activeEndTurnButton.png");
    endTurnButton->setBoarders(0, 0, 64, 18);
    endTurnButton->setPos(30, 595, 250, 80);

    dropGetButton = new Switch("../../assets/dropGetButton.png", "../../assets/activeDropGetButton.png");
    dropGetButton->setBoarders(0,0,64,20);
    dropGetButton->setPos(780, 400, 250, 80);

    field = new Field();
    pull = new Pull;
    deck = new Deck(pull);
    trash = new Trash();
    hand = new Hand(deck, trash);

    currentTurn = new Turn(field, deck, trash, hand, mouse);
}
Party::~Party() {
    delete pull;
    delete deck;
    delete trash;
    delete hand;

    delete currentTurn;
    delete exitButton;
    delete field;
    delete mouse;
}


void Party::Run() {
    std::cout << "run forest" << '\n';
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
                if (event.button.button == SDL_BUTTON_LEFT) {
                    if (exitButton->selected) {
                        std::cout << "to menu from party" << std::endl;
                        thisGame->inParty = 0;
                        thisGame->inMenu = 1;
                        return;
                    }
                    if (endTurnButton->selected) {
                        std::cout << "End turn" << '\n';
                        if (!currentTurn->GoodTurn()) {
                            ++badTurns;
                        }
                        delete currentTurn;
                        if (badTurns > 4) {
                            std::cout << "GAME OVER" << '\n';
                        }
                        currentTurn = new Turn(field, deck, trash, hand, mouse);
                        hand->Fill();
                        dropGetButton->Deselect();
                        return;
                    }
                    if (dropGetButton->checkSelected(mouse)) {
                        dropGetButton->Click();
                        currentTurn->ToogleWaitForDrop();
                        return;
                    }
                    hand->CheckClicks();
                    for (Tile* t : field->positions) {
                        if (t->selected) {
                            t->Flip();
                            return;
                        }
                    }
                }
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

    currentTurn->HandleEvents();
}

void Party::Update() {
    exitButton->Update(mouse);
    currentTurn->Update();
    dropGetButton->Update(mouse);

    endTurnButton->Update(mouse);
    field->Update(mouse);
    hand->Update(mouse);
    mouse->Update();
}

void Party::Render() {
    SDL_RenderClear(renderer);
    dropGetButton->Render();
    note->Render();
    endTurnButton->Render();
    exitButton->Render();

    field->Render();
    hand->Render();
    mouse->Render();
    SDL_RenderPresent(renderer);
}

