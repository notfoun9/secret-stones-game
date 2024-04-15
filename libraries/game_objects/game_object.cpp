#include <game_objects/game_object.hpp>
#include "../../src/inc/SDL2/SDL_image.h"

GameObject::GameObject(const char* textureSheet) {
    objTexture = TextureManager::LoadTexture(textureSheet);
}

void GameObject::Update() {
}

void Button::Update() {
    if (selected) {
        objTexture = selectedStateTexture;
    }
    else {
        objTexture = defaultStateTexture;
    }
}

void GameObject::Render() {
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

Button::Button (const char* defaultTexture, const char* selectedTexture) {
    defaultStateTexture = TextureManager::LoadTexture(defaultTexture);
    selectedStateTexture = TextureManager::LoadTexture(selectedTexture);
}

void GameObject::setPos(int x1, int y1, int x2, int y2) {
    destRect.x = x1;
    destRect.y = y1;
    destRect.w = x2;
    destRect.h = y2;
}

void GameObject::setBoarders(int x1, int y1, int x2, int y2) {
    srcRect.x = x1;
    srcRect.y = y1;
    srcRect.w = x2;
    srcRect.h = y2;
}

Mouse::Mouse() {
    objTexture = TextureManager::LoadTexture("../../assets/mouses.png");
    setBoarders(7, 12, 28, 32);
    tip = {0, 0, 2, 2};
    cursor = {0, 0, 50, 50};
} 

void Mouse::Render() {
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &cursor);
}

void Button::checkSelected(Mouse* mouse) {
    if (SDL_HasIntersection(&(mouse->tip), &destRect)) {
        selected = true;
    }
    else {
        selected = false;
    }
}
