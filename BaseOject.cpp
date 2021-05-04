#include "BaseOject.h"
#include "Bird.h"

BaseObject:: BaseObject()
{
    p_object_ = NULL;
    rect_.x = 0;
    rect_.y = 0;
    rect_.w = 0;
    rect_.h = 0;
}

BaseObject::~BaseObject()
{
    Free();
}

bool BaseObject::loadIMG(string path, SDL_Renderer* renderer)
{
    SDL_Texture* NewTexture = NULL;
    SDL_Surface* loadSurface = IMG_Load(path.c_str());
    if (loadSurface!=NULL)
    {
        SDL_SetColorKey(loadSurface, SDL_TRUE, SDL_MapRGB(loadSurface->format, COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B));
        NewTexture = SDL_CreateTextureFromSurface(renderer, loadSurface);
        if (NewTexture != NULL)
        {
            rect_.w = loadSurface->w;
            rect_.h = loadSurface->h;
        }
        SDL_FreeSurface(loadSurface);
    }
    p_object_ = NewTexture;
    return p_object_ != NULL;
}

void BaseObject::Render(SDL_Renderer* renderer, const SDL_Rect* clip )
{
    SDL_Rect renderquad = {rect_.x, rect_.y, rect_.w, rect_.h};
    SDL_RenderCopy(renderer, p_object_, NULL, &renderquad);
}

void BaseObject::Free()
{
    if(p_object_ != NULL)
    {
        SDL_DestroyTexture(p_object_);
        p_object_ = NULL;
        rect_.w = 0;
        rect_.h = 0;
    }
}

void HandleEvent()
{
    /*if (SDL_PollEvent(&event) == 0 && player.frame_number_ == 0)
        {
            player.BirdFall();
            cout << "player.frame_number_ = " << player.frame_number_ << endl;
        }
        else
        if (SDL_PollEvent(&event) != 0 )  //
        {
            if  (event.type == SDL_QUIT)
            {
                isQuit = true;
            }
            player.HandleAction(event, renderer);*/
}

/*void BaseObject::RenderBgr(SDL_Renderer* renderer, const SDL_Rect* clip )
{

    rect_.w = 1080;
    rect_.h = 720;
    SDL_Rect renderquad = {rect_.x, rect_.y, rect_.w, rect_.h};
    SDL_RenderCopy(renderer, p_object_, NULL, &renderquad);
}*/
