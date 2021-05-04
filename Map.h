#ifndef MAP_H_
#define MAP_H_

#include "BaseOject.h"
#include "CommonFunc.h"

#define DISTANCE_BETWEEN_PIPE 400

const string TypePipe[9] = {"pics/250.png", "pics/300.png", "pics/350.png", "pics/400.png", "pics/450.png", "pics/500.png", "pics/550.png", "pics/600.png", "pics/650.png"};


class Background : public BaseObject
{
public:
    Background();
    bool loadIMG (string path, SDL_Renderer* renderer);
    void RenderBgr(SDL_Renderer* renderer);
    void Stopmoving(SDL_Renderer* renderer);

private:
    int x_val_;
    int y_val_;

    SDL_Rect src;
};

class Pipe : public BaseObject
{
public:
    Pipe();
    bool loadIMG(string path, SDL_Renderer* renderer);
    void GetPipe(SDL_Renderer* renderer);
    void RenderPipe(SDL_Renderer* renderer);
    void GetPipeAgain(SDL_Renderer* renderer);
    void PipeStop(SDL_Renderer* renderer);

    //SDL_Rect pipe[4];
    int x_pos_;
    int y_pos_;
    int pipe_width;
    int pipe_height;
    int pipe_number;
};

#endif // MAP_H_
