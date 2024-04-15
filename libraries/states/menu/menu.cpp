#include <menu/menu.hpp>

Menu::Menu(SDL_Renderer* renderer_, SDL_Window* window_, Game* thisGame_) : renderer(renderer_), window(window_), thisGame(thisGame_) {}
Menu::~Menu() {
    delete button[START];
}


void Menu::Run() {
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    button[START] = new Button("../../assets/menuButton.png");
    button[START]->setBoarders(2, 16, 62, 22); // ~ 3 : 1
    button[START]->setPos(350, 150, 380, 125);

    // button[OPTIONS] = new Button(...)
    // button[EXIT] = new Button(...)

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
            case SDL_MOUSEBUTTONUP : {
                if (event.button.button == SDL_BUTTON_LEFT) {
                    if (button[START]->selected) {
                        std::cout << "BINGOOOOOOO" << std::endl;
                        return;
                    }
                }
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

    SDL_GetMouseState(&(mouse->cursor.x), &(mouse->cursor.y));
    SDL_GetMouseState(&(mouse->tip.x), &(mouse->tip.y));
}

void Menu::Update() {
    counter++;
    button[START]->checkSelected(mouse);
    button[START]->Update();
    mouse->Update();
    std::cout << counter << std::endl;
}

void Menu::Render() {
    SDL_RenderClear(renderer);
    button[START]->Render();
    mouse->Render();
    SDL_RenderPresent(renderer);
}