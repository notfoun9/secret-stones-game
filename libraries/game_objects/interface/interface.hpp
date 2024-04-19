#pragma once 

#include <game/game.hpp>
#include <texture_manager/texture_manager.hpp>

class Mouse;

class GameObject {
public:
    GameObject() = default;
    GameObject(const char* textureSheet);
    virtual ~GameObject();

    virtual void Update();
    virtual void Render();

    virtual void setBoarders(int x1, int y1, int x2, int y2);
    void setPos(int x1, int y1, int x2, int y2);
    SDL_Texture* GetTexture();
    SDL_Rect srcRect;
    SDL_Rect destRect;
protected:
    SDL_Texture* objTexture = nullptr;
} ;

class Button : public GameObject {
public:
    Button() = default;
    Button(const char* defaultStateTexture, const char* selectedStateTexture);
    virtual ~Button();

    virtual void Update(Mouse* mouse);
    void checkSelected(Mouse* mouse);
    bool selected = 0;
protected:
    SDL_Texture* defaultStateTexture = nullptr;
    SDL_Texture* selectedStateTexture = nullptr;
} ;

class Switch : public GameObject {
public:
    Switch(const char* defaultStateTexture, const char* selectedStateTexture);
    ~Switch();

    bool checkSelected(Mouse* mouse);
    void Deselect();
    virtual void Update(Mouse* mouse);
    void Click();
private:
    bool active = 0;

    SDL_Texture* defaultStateTexture = nullptr;
    SDL_Texture* activeStateTexture = nullptr;
} ;

class Mouse : public GameObject {
public:
    Mouse();
    ~Mouse() = default;

    void Render();

    SDL_Rect cursor;
    SDL_Rect tip;
} ; 