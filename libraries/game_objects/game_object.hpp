#pragma once

#include <game/game.hpp>
#include <texture_manager/texture_manager.hpp>

class GameObject {
public:
    GameObject(const char* textureSheet, int x, int y);
    ~GameObject() = default;

    void Update();
    void Render();

private:
    int xPos;
    int yPos;

    SDL_Texture* objTexture;
    SDL_Rect srcRect;
    SDL_Rect destRect;
} ;