#include <party/party.hpp>
#include <vector>

Party::Party(SDL_Renderer* renderer_, SDL_Window* window_, Game* thisGame_) : renderer(renderer_), window(window_), thisGame(thisGame_) {
    field = new Field();
    exitButton = new Button("../../assets/goBackButton.png", "../../assets/activeGoBack.png");;
    exitButton->setBoarders(0, 0, 34, 11);
    exitButton->setPos(50, 600, 220, 80);

    note = new GameObject("../../assets/note.png");
    note->setBoarders(0,0,149, 280);
    note->setPos(30, 30, 189, 310);
}
Party::~Party() {
    delete exitButton;
    delete field;
    delete mouse;
}


void Party::Run() {
    if (field) {
        field->constructRandomField();
    }
    std::cout << "running" << '\n';
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
                    for (Tile* t : field->positions) {
                        if (SDL_HasIntersection(&(mouse->tip), &(t->destRect))) {
                            t->Flip();
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
}

void Party::Update() {
    exitButton->checkSelected(mouse);
    exitButton->Update();
    field->Update();
    mouse->Update();
}

void Party::Render() {
    SDL_RenderClear(renderer);
    note->Render();

    exitButton->Render();
    field->Render();
    mouse->Render();
    SDL_RenderPresent(renderer);
}

