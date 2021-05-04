#ifndef BIRD_H_
#define BIRD_H_

#include "CommonFunc.h"
#include "BaseOject.h"
#include "Audio.h"

class Bird : public BaseObject
{
public:
    float x_pos;
    float y_pos;
    int width_frame_;
    int height_frame_;
    float x_val;
    float y_val;
    SDL_Rect frame_clip_[12];
    Input input_type_;
    int status_ ;


    Bird();
    ~Bird();
    int frame_number_;
    int checkFlyingStep_;

    enum FlyType
    {
        Fly_up = 1,
    };
    virtual bool loadIMG (string path, SDL_Renderer* renderer);
    void Show(SDL_Renderer* renderer);
    void HandleAction (SDL_Event event, SDL_Renderer* renderer, Audio audio);
    void set_clips();
    void BirdFall();
    void BirdFly();
    void GameOver(SDL_Renderer* renderer);
    void ShowinPlace(SDL_Renderer* renderer);
    //bool loadFinalPic(SDL_Renderer* renderer);


};


#endif // BIRD_H_
