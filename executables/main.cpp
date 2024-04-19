// Yeah, here we go for the hundredth time
// Hand grenade pins in every line

#include <game/game.hpp>


Game* game = nullptr;

int main() {

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    uint32_t frameStart;
    int frameTime;

    game = new Game();
    game->init("Secret Stones", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, false);
    SDL_ShowCursor(false);
    while (game->running()) {
        std::cout << "cycle" << '\n';
        frameStart = SDL_GetTicks();

        game->handleEvents();

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();

    return 0;
}