#include <gameOver/gameOver.hpp>

GameOver::GameOver(SDL_Renderer* renderer_, SDL_Window* window_, Game* thisGame_) : renderer(renderer_), window(window_), thisGame(thisGame_) {
    goToMenu = new Button("../../assets/toMenu.png", "../../assets/toMenuSelected.png");
    goToMenu->setBoarders(0, 0, 40, 12);
    goToMenu->setPos(360, 580, 360, 108);
}
GameOver::~GameOver() {
    delete goToMenu;
    delete mouse;
    delete back;
}


void GameOver::Run() {
    delete back;
    if (!(thisGame->isWin)) {
        back = new GameObject("../../assets/gameOver.png");
        back->setBoarders(0,0,1080,720);
    }
    else {
        back = new GameObject("../../assets/win.png");
        back->setBoarders(0,0,216,144);
    }
    back->setPos(0,0,1080,720);

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    uint32_t frameStart;
    int frameTime;

    while (thisGame->inGameOver) {
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

void GameOver::HandleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT : {
                thisGame->inGameOver = 0;
                thisGame->quit();
                return;
            }
            case SDL_MOUSEBUTTONUP : {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    if (goToMenu->selected) {
                        thisGame->inGameOver = 0;
                        thisGame->inMenu = 1;
                        thisGame->isWin = 0;
                        std::cout << "goToMenu!" << std::endl;
                        return;
                    }
                }
            }
            default : break;
        }
    }

    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    if (keystates[SDL_SCANCODE_ESCAPE]) {
        thisGame->inGameOver = 0;
        thisGame->quit();
    }
    if (keystates[SDL_SCANCODE_F12]) thisGame->toggleFullscreen();

    SDL_GetMouseState(&(mouse->cursor.x), &(mouse->cursor.y));
    SDL_GetMouseState(&(mouse->tip.x), &(mouse->tip.y));
}

void GameOver::Update() {
    goToMenu->Update(mouse);
    mouse->Update();
}

void GameOver::Render() {
    SDL_RenderClear(renderer);

    back->Render();
    goToMenu->Render();
    mouse->Render();
    SDL_RenderPresent(renderer);
}

