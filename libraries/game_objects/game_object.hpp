#pragma once

#include <game/game.hpp>
#include <texture_manager/texture_manager.hpp>

class GameObject {
public:
    GameObject() = default;
    GameObject(const char* textureSheet);
    virtual ~GameObject() = default;

    virtual void Update();
    virtual void Render();

    void setBoarders(int x1, int y1, int x2, int y2);
    void setPos(int x1, int y1, int x2, int y2);
protected:

    SDL_Texture* objTexture = nullptr;
    SDL_Rect srcRect;
    SDL_Rect destRect;
} ;

class Mouse;

class Button : public GameObject {
public:
    Button(const char* defaultStateTexture, const char* selectedStateTexture);
    ~Button() = default;

    void Update();
    void checkSelected(Mouse* mouse);
    bool selected = 0;
private:
    SDL_Texture* defaultStateTexture = nullptr;
    SDL_Texture* selectedStateTexture = nullptr;
} ;

class Mouse : public GameObject {
public:
    Mouse();
    ~Mouse() = default;

    void Render() override;

    SDL_Rect cursor;
    SDL_Rect tip;
} ; 