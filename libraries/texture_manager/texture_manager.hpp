#pragma once

#include <game/game.hpp>

#ifndef texture_manager_hpp
#define texture_manager_hpp

class TextureManager {
public:
    [[nodiscard]] static SDL_Texture* LoadTexture(const char *fileName);
} ;

#endif