#include <menu/menu.hpp>

Menu::Menu(SDL_Renderer* renderer_, SDL_Window* window_, Game* thisGame_) : renderer(renderer_), window(window_), thisGame(thisGame_) {}
Menu::~Menu() {
    delete button[START];
    delete button[RULES];
    delete button[EXIT];
    delete mouse;
}


void Menu::Run() {
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    button[START] = new Button("../../assets/menuButton.png", "../../assets/activeStartButton.png");
    button[START]->setBoarders(2, 16, 62, 22); // ~ 3 : 1
    button[START]->setPos(350, 150, 380, 125);

    button[RULES] = new Button("../../assets/rulesButton.png", "../../assets/activeRulesButton.png");
    button[RULES]->setBoarders(0, 0, 60, 22);
    button[RULES]->setPos(350, 300, 380, 125);

    button[EXIT] = new Button("../../assets/exitButton.png", "../../assets/activeExitButton.png");
    button[EXIT]->setBoarders(0, 0, 116, 44);
    button[EXIT]->setPos(350, 450, 380, 125);

    uint32_t frameStart;
    int frameTime;

    while (thisGame->inMenu) {
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

void Menu::HandleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT : {
                thisGame->inMenu = 0;
                thisGame->quit();
                return;
            }
            case SDL_MOUSEBUTTONUP : {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    if (button[START]->selected) {
                        std::cout << "startParty" << std::endl;
                        thisGame->inMenu = 0;
                        thisGame->inParty = 1;
                        return;
                    }
                    if (button[RULES]->selected) {
                        std::cout << "open rules" << std::endl;
                        thisGame->inMenu = 0;
                        thisGame->inRules = 1;
                        return;
                    }
                    if (button[EXIT]->selected) {
                        thisGame->inMenu = 0;
                        thisGame->quit();
                        std::cout << "exit!" << std::endl;
                        return;
                    }
                }
            }
            default : break;
        }
    }

    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    if (keystates[SDL_SCANCODE_ESCAPE]) {
        thisGame->inMenu = 0;
        thisGame->quit();
    }
    if (keystates[SDL_SCANCODE_F12]) thisGame->toggleFullscreen();

    SDL_GetMouseState(&(mouse->cursor.x), &(mouse->cursor.y));
    SDL_GetMouseState(&(mouse->tip.x), &(mouse->tip.y));
}

void Menu::Update() {
    for (Button* but : button) {
        but->checkSelected(mouse);
        but->Update();
    }
    mouse->Update();
}

void Menu::Render() {
    SDL_RenderClear(renderer);
    for (Button* but : button) {
        but->Render();
    }
    mouse->Render();
    SDL_RenderPresent(renderer);
}