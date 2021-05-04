#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "CommonFunc.h"
#include "BaseOject.h"
#include "Bird.h"
#include "Map.h"
#include "TextObject.h"
#include "Audio.h"

using namespace std;

//BaseObject bgr;
Background bgr;
TTF_Font* font = NULL;
Audio audio;
int Score = 0;
//Pipe pipe;

bool Init()
{
    bool success = true;
    int ret = SDL_Init(SDL_INIT_VIDEO);
    if (ret < 0) return false;
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    window = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                               SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if (window == NULL) success = false;
    else
    {
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer == NULL) success = false;
        else
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) && imgFlags))
                success = false;
        }
        if (TTF_Init() == -1)
        {
            success = false;
        }
        font = TTF_OpenFont("font/ManhattanRegular.ttf", 12);
        if (font == NULL)
        {
            //cout<< TTF_GetError()<< endl;
            //success = false;
        }
    }
    return success;
}

/*bool loadBackground()
{
    //bgr.rect_.x = 1080;
    bool ret = bgr.loadIMG("pics/background.png", renderer);
    if (ret == false) return false;

    return true;
}*/

void close()
{
    //bgr.Free();
    Mix_CloseAudio();
    SDL_DestroyRenderer(renderer);
    renderer = NULL ;
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

}

SDL_Texture* p;
bool loadPressSpace(string path, SDL_Renderer* renderer)
{
    SDL_Texture* NewTexture = NULL;
    SDL_Surface* loadSurface = IMG_Load(path.c_str());
    if (loadSurface!=NULL)
    {
        SDL_SetColorKey(loadSurface, SDL_TRUE, SDL_MapRGB(loadSurface->format, COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B));
        NewTexture = SDL_CreateTextureFromSurface(renderer, loadSurface);
        SDL_FreeSurface(loadSurface);
    }
    p = NewTexture;
    return p != NULL;
}

void SetPipes(Pipe pipe[], int n)
{
    for (int i = 0; i<n; i++)
    {
        pipe[i+1].x_pos_=pipe[i].x_pos_+ DISTANCE_BETWEEN_PIPE;
    }
}

void GetPipes(Pipe pipe[], int n, SDL_Renderer* renderer)
{
    for (int i = 0; i < n; i++)
    {
        pipe[i].GetPipe(renderer);
    }
}

void GetPipesAgain(Pipe pipe[], int n, SDL_Renderer* renderer)
{
    for (int i = 0; i < n; i++)
    {
        pipe[i].GetPipeAgain(renderer);
    }
}

void RenderPipes(Pipe pipe[], int n, SDL_Renderer* renderer)
{
    for (int i = 0; i < n; i++)
    {
        pipe[i].RenderPipe(renderer);
    }
}

void RenderPipesStop(Pipe pipe[], int n, SDL_Renderer* renderer)
{
    for (int i = 0; i < n; i++)
    {
        pipe[i].PipeStop(renderer);
    }
}

int main(int argc, char* argv[] )
{
    if (Init() == false) return -1;
    //if (loadBackground() == false) return -1;

    //GameMap game_map;
    //game_map.loadMap("map/map01.dat");
    //game_map.loadTiles(renderer);

    Bird player;
    player.loadIMG("pics//Birds.png", renderer);
    player.set_clips();
    bgr.loadIMG("pics/background.png", renderer);

    /*BaseObject start;
    start.loadIMG("pics//pressSpace.png", renderer);*/
    BaseObject over;
    over.loadIMG("pics/pressEnter.png", renderer);
    loadPressSpace("pics//pressSpace.png", renderer);

    audio.InitAudio();
    audio.LoadChunk("audio/flapping.wav");
    audio.LoadMusic("audio/background.mp3");

    Pipe pipe[3];
    SetPipes(pipe, 3);
    GetPipes(pipe, 3, renderer);
    Pipe* mainpipe = &pipe[0];
    //cout<< mainpipe.pipe_height<< " " << mainpipe.pipe_number << endl;

    /*TextObject startText;
    startText.SetColor(TextObject::BLACK_TEXT);
    startText.SetText("Press Spacebar to start and fly");
    startText.LoadFromRenderText(font, renderer);

    TextObject endText;
    endText.SetColor(TextObject::BLACK_TEXT);
    endText.SetText("Press Enter to play again");
    endText.LoadFromRenderText(font, renderer);*/

    bool isGameOver = false;
    bool isGameStart = false;

    bool isQuit = false;
    /*while (!isGameStart)
    {
        bgr.Stopmoving(renderer);
        player.status_ = 1;
        //player.Show(renderer);
        player.ShowinPlace(renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(50);
        if (SDL_PollEvent(&event) != 0)
                {
                    if (event.type == SDL_KEYDOWN)
                    {
                        if (event.key.keysym.sym == SDLK_SPACE)
                        {
                            isGameStart = true;
                        }
                    }
                }
        //if (isGameStart == false) cout<< -1<< endl; else cout<< 1<< endl;
    }*/
    while (!isQuit)
    {
        audio.PlayMusic();
        if (isGameOver == true)
        {
            if (SDL_PollEvent(&event) != 0)
                {
                    if (event.type == SDL_KEYDOWN)
                    {
                        if (event.key.keysym.sym == SDLK_KP_ENTER)
                        {
                            isGameOver = false;
                            player.y_pos = 200;
                            pipe[0].x_pos_ = SCREEN_WIDTH;
                            SetPipes(pipe, 3);
                            mainpipe = &pipe[0];
                            isGameStart = false;
                        }
                    }
                }

        }
        while (!isGameStart && !isQuit)
            {
                bgr.Stopmoving(renderer);
                //start.Render(renderer, NULL);
                SDL_RenderCopy(renderer, p, NULL, NULL);
                player.status_ = 1;
                //player.Show(renderer);
                player.ShowinPlace(renderer);

                //startText.RenderText(renderer, 200, SCREEN_HEIGHT - 200);
                SDL_RenderPresent(renderer);
                SDL_Delay(50);
                if (SDL_PollEvent(&event) != 0)
                        {
                            if (event.type == SDL_KEYDOWN)
                            {
                                if (event.key.keysym.sym == SDLK_SPACE)
                                {
                                    isGameStart = true;
                                }
                            }
                        }
                //if (isGameStart == false) cout<< -1<< endl; else cout<< 1<< endl;
            }
            if (SDL_PollEvent(&event) != 0 )  //
            {
                if  (event.type == SDL_QUIT)
                {
                    isQuit = true;
                }
                player.HandleAction(event, renderer, audio);

            }

         if (player.x_pos + 150 > mainpipe->x_pos_ + 180)
        {
            if (mainpipe = &pipe[0]) mainpipe = &pipe[1];
            else if (mainpipe = &pipe[1]) mainpipe = &pipe[2];
            else if (mainpipe = &pipe[2]) mainpipe = &pipe[0];
        }
        if ((player.x_pos + 150 >=mainpipe->x_pos_)&&
            (player.y_pos + 75 <= mainpipe->pipe_number - 250 ||
             player.y_pos + 75 >= mainpipe->pipe_number  ))
        {
            isGameOver = true;
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        //player.Render(renderer, NULL);
//        game_map.drawMap(renderer);
        player.BirdFall();
        if (player.y_pos + player.width_frame_ > SCREEN_HEIGHT)
        {
            isGameOver = true;
        }
        if (isGameOver == false)
        {
            bgr.RenderBgr(renderer);

            GetPipesAgain(pipe, 3, renderer);
            RenderPipes(pipe, 3, renderer);

            player.Show(renderer);

        }
        else
        {
            bgr.Stopmoving(renderer);
            RenderPipesStop(pipe, 3, renderer);
            player.GameOver(renderer);
            over.Render(renderer, NULL);
        }
        //cout << "player.frame_number_ = " << player.frame_number_ << endl;

        SDL_RenderPresent(renderer);
        SDL_Delay(35);

    }
    close();
    return 0;
}
