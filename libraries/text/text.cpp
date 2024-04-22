#include<text/text.hpp>
#include<texture_manager/texture_manager.hpp>

Text::Text(std::string fontPath, int fontSize, const SDL_Color color_) :
    color(color_) {
    TTF_Init();
    const char* f = fontPath.data();
    font = TTF_OpenFont(f, fontSize);
    std::cerr << TTF_GetError() << '\n';
    if (!font) {
        std::cerr << "Failed to load font\n";
    }
}

void Text::SetMessage(std::string message_) {
    message = message_;
    auto textSurface = TTF_RenderText_Solid(font, message.c_str(), color);
    textTex = SDL_CreateTextureFromSurface(Game::renderer, textSurface);
}

void Text::Update() {
    SDL_QueryTexture(textTex, nullptr, nullptr, &textDest.w, &textDest.h);
}

void Text::Render() const {
    if (!textTex) std::cerr << "error" << '\n';
    SDL_RenderCopy(Game::renderer, textTex, NULL, &textDest);
}

void Text::SetDest(int x, int y) {
    textDest.x = x;
    textDest.y = y;
}