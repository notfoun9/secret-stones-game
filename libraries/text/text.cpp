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
    SDL_QueryTexture(textTex, nullptr, nullptr, &textRect.w, &textRect.h);
}

void Text::Update() {
    SDL_QueryTexture(textTex, nullptr, nullptr, &textRect.w, &textRect.h);
}

void Text::Render() const {
    SDL_RenderCopy(Game::renderer, textTex, NULL, &textDest);
}

void Text::SetSrc(int x, int y, int w, int h) {
    textRect = {x,y,w,h};
}
void Text::SetDest(int x, int y, int w, int h) {
    textDest = {x, y, w, h};
}