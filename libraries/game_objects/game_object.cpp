#include <game_objects/game_object.hpp>
#include "../../src/inc/SDL2/SDL_image.h"

GameObject::GameObject(const char* textureSheet, int x_, int y_) : xPos(x_), yPos(y_) {
    objTexture = TextureManager::LoadTexture(textureSheet);
}

void GameObject::Update() {
    ++xPos;
    ++yPos; 

    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xPos;
    destRect.y = yPos;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;
}

void GameObject::Render() {
    SDL_RenderCopy(Game::renderer, objTexture, NULL, &destRect);
}