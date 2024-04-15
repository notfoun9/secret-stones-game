#include <texture_manager/texture_manager.hpp>

[[nodiscard]] SDL_Texture* TextureManager::LoadTexture(const char* texture) {
    SDL_Surface* tmpSurface = IMG_Load(texture);
    SDL_Texture* textureFromSurface = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);

    return textureFromSurface;
}