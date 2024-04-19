#include <game/game.hpp>
#include <texture_manager/texture_manager.hpp>
#include <game_objects/game_objects.hpp>
#include <states/rules/rules.hpp>
#include <states/menu/menu.hpp>
#include <states/party/party.hpp>
#include <pull/pull.hpp>
#include <conditions/conditions.hpp>
#include <states/gameOver/gameOver.hpp>

Menu* mainMenu;
Rules* rules;
Party* party;
Pull* pull;
GameOver* gameOver;


SDL_Renderer* Game::renderer = nullptr;
Conditions* conditions = new Conditions();

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
        }
        
        isRunning = true;

        mainMenu = new Menu(renderer, window, this);
        rules = new Rules(renderer, window, this);
        pull = new Pull(conditions);
        party = new Party(renderer, window, this, pull);
        gameOver = new GameOver(renderer, window, this);
    }
    else {
        isRunning = false;
    }
}
void Game::handleEvents() {
    while (inMenu) {
        mainMenu->Run();
    }
    while (inRules) {
        rules->Run();
    }
    while (inParty) {
        party->Run();
    }
    while (inGameOver) {
        gameOver->Run();
    }
}

void Game::clean() {
    delete mainMenu;
    SDL_DestroyWindow(window);
    SDL_Quit();
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