#include <rules/rules.hpp>

Rules::Rules(SDL_Renderer* renderer_, SDL_Window* window_, Game* thisGame_) : renderer(renderer_), window(window_), thisGame(thisGame_) {
    goBack = new Button("../../assets/toMenu.png", "../../assets/toMenuSelected.png");
    goBack->setBoarders(0, 0, 40, 12);
    goBack->setPos(360, 580, 360, 108);

    rules = new GameObject("../../assets/rules.png");
    rules->setBoarders(0, 0, 1440, 270);
    rules->setPos(20, 50, 1060, 400);
}
Rules::~Rules() {
    delete goBack;
    delete mouse;
    delete rules;
}


void Rules::Run() {
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    uint32_t frameStart;
    int frameTime;

    while (thisGame->inRules) {
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

void Rules::HandleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT : {
                thisGame->inRules = 0;
                thisGame->quit();
                return;
            }
            case SDL_MOUSEBUTTONUP : {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    if (goBack->selected) {
                        thisGame->inRules = 0;
                        thisGame->inMenu = 1;
                        std::cout << "goToMEnu!" << std::endl;
                        return;
                    }
                }
            }
            default : break;
        }
    }

    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    if (keystates[SDL_SCANCODE_ESCAPE]) {
        thisGame->inRules = 0;
        thisGame->quit();
    }
    if (keystates[SDL_SCANCODE_F12]) thisGame->toggleFullscreen();

    SDL_GetMouseState(&(mouse->cursor.x), &(mouse->cursor.y));
    SDL_GetMouseState(&(mouse->tip.x), &(mouse->tip.y));
}

void Rules::Update() {
    goBack->Update(mouse);
    mouse->Update();
}

void Rules::Render() {
    SDL_RenderClear(renderer);
    rules->Render();

    goBack->Render();
    mouse->Render();
    SDL_RenderPresent(renderer);
}

