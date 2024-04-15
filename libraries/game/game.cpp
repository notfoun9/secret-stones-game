#include <game/game.hpp>
#include <texture_manager/texture_manager.hpp>
#include <game_objects/game_object.hpp>
#include <states/menu/menu.hpp>

Menu* mainMenu;

SDL_Renderer* Game::renderer = nullptr;

Game::Game() {
}
Game::~Game() {
}

void Game::init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen) {
    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created!" << std::endl;
        }
        isRunning = true;
        mainMenu = new Menu(renderer, window, this);
    }
    else {
        isRunning = false;
    }
}
// TextureManager::LoadTexture("../../assets/player.png", renderer);

void Game::handleEvents() {
    while (inMenu) {
        mainMenu->Run();
    }
    // while (inParty) {

    // }
}

void Game::update() {
    std::cout << "Out of state!" << std::endl;
}

void Game::render() {
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    delete mainMenu;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned!" << std::endl;
}

bool Game::running() {
    return isRunning;
}

void Game::toggleFullscreen() {
    fullscreen_ = !fullscreen_;
    (fullscreen_) ? SDL_SetWindowFullscreen(window, 1) : SDL_SetWindowFullscreen(window, 0);
}

void Game::quit() {
    inMenu = 0;
    isRunning = 0;
}