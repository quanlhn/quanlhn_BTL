#ifndef BASE_OBJECT_H
#define BASE_OBJECT_H

#include "CommonFunc.h"
#include <string>
using namespace std;

class BaseObject
{
public:
    BaseObject();
    ~BaseObject();
    void setRect(const int&x, const int& y) {rect_.x = x, rect_.y = y;}
    SDL_Rect GetRect() const {return rect_;}
    SDL_Texture* GetObject() const {return p_object_;}

    bool loadIMG (string path, SDL_Renderer* renderer);
    void Render(SDL_Renderer* renderer, const SDL_Rect* clip = NULL );
    void Free();
    void RenderBgr(SDL_Renderer* renderer, const SDL_Rect* clip );


    SDL_Texture* p_object_;
    SDL_Rect rect_;
};

void HandleEvent();

#endif // BASE_OBJECT_H
