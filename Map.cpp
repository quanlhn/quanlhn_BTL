#include "Map.h"

Background::Background()
{
    src.x = 0;
    src.y = 0;
    src.w = 0;
    src.h = 0;

}


 bool Background::loadIMG(string path, SDL_Renderer* renderer)
{
    bool ret = BaseObject::loadIMG(path, renderer);
    if (ret == true)
        {
        src.w = rect_.w/3;
        src.h = rect_.h;
        }


}

void Background::RenderBgr(SDL_Renderer* renderer)
{
    SDL_Rect RenderQuad = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_RenderCopy(renderer, p_object_, &src, &RenderQuad);
    if (src.x >= rect_.w - SCREEN_WIDTH)
    {
        src.x = 0;
    }
     else src.x += 2;
    //cout<< src.x<< endl;
}

void Background::Stopmoving(SDL_Renderer* renderer)
{
    SDL_Rect RenderQuad = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_RenderCopy(renderer, p_object_, &src, &RenderQuad);
}

Pipe::Pipe()
{
    x_pos_ = SCREEN_WIDTH;
    y_pos_ = 0;
    pipe_width = 0;
    pipe_height = 0;
}
void Pipe::GetPipe(SDL_Renderer* renderer)
{
    string typepipe;
    int ran = rand() % 9 ;
    //cout<< ran<< endl;
    switch (ran)
    {
    case 0:
        {
            pipe_number = 250;
            typepipe = TypePipe[0];
            break;
        }
    case 1:
        {
            pipe_number = 3000;
            typepipe = TypePipe[1];
            break;
        }
    case 2:
        {
            pipe_number = 350;
            typepipe = TypePipe[2];
            break;
        }
    case 3:
        {
            pipe_number = 400;
            typepipe = TypePipe[3];
            break;
        }
    case 4:
        {
            pipe_number = 450;
            typepipe = TypePipe[4];
            break;
        }
    case 5:
        {
            pipe_number = 500;
            typepipe = TypePipe[5];
            break;
        }
    case 6:
        {
            pipe_number = 550;
            typepipe = TypePipe[6];
            break;
        }
    case 7:
        {
            pipe_number = 600;
            typepipe = TypePipe[7];
            break;
        }
    case 8:
        {
            pipe_number = 650;
            typepipe = TypePipe[8];
            break;
        }
    }
    //cout<< typepipe<< endl;
    loadIMG(typepipe, renderer);

}

bool Pipe::loadIMG( string path, SDL_Renderer* renderer)
{
    bool ret = BaseObject::loadIMG(path, renderer);
    if (ret == true)
    {
        pipe_width = rect_.w;
        pipe_height = rect_.h;
    }
    else cout<< "failed to load IMG"<< endl;
    return ret;
}

void Pipe::RenderPipe(SDL_Renderer* renderer)
{
    SDL_Rect renderQuad = {x_pos_, y_pos_, pipe_width, pipe_height };
    SDL_RenderCopy(renderer,p_object_, NULL, &renderQuad);
    x_pos_ -=5;
}

void Pipe::GetPipeAgain(SDL_Renderer* renderer)
{
    if (x_pos_ < -pipe_width)
    {
        x_pos_ = SCREEN_WIDTH;
        GetPipe(renderer);
    }
}
void Pipe::PipeStop(SDL_Renderer* renderer)
{
    SDL_Rect renderQuad = {x_pos_, y_pos_, pipe_width, pipe_height };
    SDL_RenderCopy(renderer,p_object_, NULL, &renderQuad);
}
//Pipe pipe[5];

