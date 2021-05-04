#ifndef COMMON_FUNCTION_H
#define COMMON_FUNCTION_H

//#include <window.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

using namespace std;

static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;
static SDL_Event event ;

const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 720;
const int SCREEN_BPP = 32;

const int COLOR_KEY_R = 227;
const int COLOR_KEY_G = 227;
const int COLOR_KEY_B = 227;

#define TILE_SIZE 64
#define MAP_MAX_X 400
#define MAP_MAX_Y 10



typedef struct Input
{
        int up_;
        int down_;
        int fly_ = 0;
};

typedef struct Map
{
    int start_x_;
    int start_y_;

    int max_x_;
    int max_y_;

    int tile[MAP_MAX_X][MAP_MAX_Y];
    char* file_name_;


};


#endif // COMMON_FUNCTION_H
