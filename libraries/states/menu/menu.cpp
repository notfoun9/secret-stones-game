#include <menu/menu.hpp>

Menu::Menu(SDL_Renderer* renderer_, SDL_Window* window_, Game* thisGame_) : renderer(renderer_), window(window_), thisGame(thisGame_) {}

void Menu::Run() {
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    uint32_t frameStart;
    int frameTime;

    while (inMenu) {
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
                inMenu = 0;
                thisGame->quit();
                return;
            }
            default : break;
        }
    }
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    if (keystates[SDL_SCANCODE_ESCAPE]) {
        inMenu = 0;
        thisGame->quit();
    }
    if (keystates[SDL_SCANCODE_F12]) thisGame->toggleFullscreen();
}

void Menu::Update() {
    counter++;
    std::cout << counter << std::endl;
}

void Menu::Render() {
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}