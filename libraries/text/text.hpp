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

    void SetSrc(int x, int y, int w, int h);
    void SetDest(int x, int y, int w, int h);
private:
    SDL_Texture* textTex = nullptr;
    SDL_Rect textRect;
    SDL_Rect textDest;
    std::string message;
    SDL_Color color;

    TTF_Font* font;
} ;
