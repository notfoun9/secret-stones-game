#pragma once

#include <game/game.hpp>

#ifndef texture_manager_hpp
#define texture_manager_hpp

class TextureManager {
public:
    [[nodiscard]] static SDL_Texture* LoadTexture(const char *fileName);
    static void Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest);
} ;

#endif