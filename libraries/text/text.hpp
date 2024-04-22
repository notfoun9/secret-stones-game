#pragma once 

#include<game/game.hpp>
#include "../../src/inc/SDL2/SDL_ttf.h"

class Text {
public:
    Text(std::string fontPath, int fontSize, const SDL_Color color);
    ~Text() = default;
    void SetMessage(std::string message);
    void Render() const;
    void Update();

    void SetDest(int x, int y);
private:
    SDL_Texture* textTex = nullptr;
    SDL_Rect textDest;
    std::string message;
    SDL_Color color;

    TTF_Font* font;
} ;
