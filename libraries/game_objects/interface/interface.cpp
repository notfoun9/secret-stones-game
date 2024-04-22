
#include <interface/interface.hpp>

GameObject::GameObject(const char* textureSheet) {
    objTexture = TextureManager::LoadTexture(textureSheet);
}
GameObject::~GameObject() {
    SDL_DestroyTexture(objTexture);
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
void GameObject::Render() {
    TextureManager::Draw(objTexture, srcRect, destRect);
}
void GameObject::Update() {}
SDL_Texture* GameObject::GetTexture() {
    return objTexture;
}


Button::Button (const char* defaultTexture, const char* selectedTexture) : 
    defaultStateTexture(TextureManager::LoadTexture(defaultTexture)), 
    selectedStateTexture(TextureManager::LoadTexture(selectedTexture)) {}
Button::~Button() {
    SDL_DestroyTexture(defaultStateTexture);
    SDL_DestroyTexture(selectedStateTexture);
}
void Button::Update(Mouse* mouse) {
    checkSelected(mouse);
    if (selected) {
        objTexture = selectedStateTexture;
    }
    else {
        objTexture = defaultStateTexture;
    }
}
void Button::checkSelected(Mouse* mouse) {
    if (SDL_HasIntersection(&(mouse->tip), &destRect)) {
        selected = true;
    }
    else {
        selected = false;
    }
}

Switch::Switch(const char* defaultStateTexture_, const char* selectedStateTexture) :
    defaultStateTexture(TextureManager::LoadTexture(defaultStateTexture_)),
    activeStateTexture(TextureManager::LoadTexture(selectedStateTexture)) {}
Switch::~Switch() {
    SDL_DestroyTexture(defaultStateTexture);
    SDL_DestroyTexture(activeStateTexture);
}

bool Switch::checkSelected(Mouse* mouse) {
    if (SDL_HasIntersection(&(mouse->tip), &destRect)) return true;
    return false;
}
void Switch::Update(Mouse* mouse) {
    if (active) {
        objTexture = activeStateTexture;
    }
    else {
        objTexture = defaultStateTexture;
    }
} 
void Switch::Click() {
    active = !active;
}
void Switch::Deselect() {
    active = 0;
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
