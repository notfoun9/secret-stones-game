#include <party/party.hpp>
#include <vector>

Party::Party(SDL_Renderer* renderer_, SDL_Window* window_, Game* thisGame_) : renderer(renderer_), window(window_), thisGame(thisGame_) {
}
Party::~Party() {
    delete field;
    delete mouse;
}


void Party::Run() {
    field = new Field();
    
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
    // field->Update();
    mouse->Update();
}

void Party::Render() {
    SDL_RenderClear(renderer);
    field->Render();
    mouse->Render();
    SDL_RenderPresent(renderer);
}

