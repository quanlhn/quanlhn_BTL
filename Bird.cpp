#include "Bird.h"

Bird::Bird()
{
    frame_number_ = 0;
    x_pos = 200;
    y_pos = 200;
    x_val = 0;
    y_val = 0;
    width_frame_ = 0;
    height_frame_ = 0;
    status_ = 0;
    checkFlyingStep_ = 0 ;

}
Bird::~Bird()
{

}

bool Bird::loadIMG(string path, SDL_Renderer* renderer)
{
    bool ret = BaseObject::loadIMG(path, renderer);
    if (ret == true)
    {
        width_frame_ = 150;
        height_frame_ = 150;
    }
    return ret;
}

void Bird::set_clips()
{
    if (width_frame_ > 0 && height_frame_ > 0)
    {
        frame_clip_[0].x = 0;
        frame_clip_[0].y = 0;
        frame_clip_[0].w = width_frame_;
        frame_clip_[0].h = height_frame_;

        frame_clip_[1].x = width_frame_;
        frame_clip_[1].y = 0;
        frame_clip_[1].w = width_frame_;
        frame_clip_[1].h = height_frame_;

        frame_clip_[2].x = width_frame_*2;
        frame_clip_[2].y = 0;
        frame_clip_[2].w = width_frame_;
        frame_clip_[2].h = height_frame_;

        frame_clip_[3].x = width_frame_*3;
        frame_clip_[3].y = 0;
        frame_clip_[3].w = width_frame_;
        frame_clip_[3].h = height_frame_;

        frame_clip_[4].x = width_frame_*4;
        frame_clip_[4].y = 0;
        frame_clip_[4].w = width_frame_;
        frame_clip_[4].h = height_frame_;

        frame_clip_[5].x = width_frame_*5;
        frame_clip_[5].y = 0;
        frame_clip_[5].w = width_frame_;
        frame_clip_[5].h = height_frame_;

        frame_clip_[6].x = width_frame_*6;
        frame_clip_[6].y = 0;
        frame_clip_[6].w = width_frame_;
        frame_clip_[6].h = height_frame_;

        frame_clip_[7].x = width_frame_*7;
        frame_clip_[7].y = 0;
        frame_clip_[7].w = width_frame_;
        frame_clip_[7].h = height_frame_;

        frame_clip_[8].x = width_frame_*8;
        frame_clip_[8].y = 0;
        frame_clip_[8].w = width_frame_;
        frame_clip_[8].h = height_frame_;

        frame_clip_[9].x = width_frame_*9;
        frame_clip_[9].y = 0;
        frame_clip_[9].w = width_frame_;
        frame_clip_[9].h = height_frame_;

        frame_clip_[10].x = width_frame_*10;
        frame_clip_[10].y = 0;
        frame_clip_[10].w = width_frame_;
        frame_clip_[10].h = height_frame_;

        frame_clip_[11].x = width_frame_*11;
        frame_clip_[11].y = 0;
        frame_clip_[11].w = width_frame_;
        frame_clip_[11].h = height_frame_;


    }

}

void Bird::Show(SDL_Renderer* renderer)
{
    /*if (status_ = Fly_up)
    {
        loadIMG("pics//Birds.png", renderer);

    }*/
    if (status_ == Fly_up)
    {
        frame_number_++;
        //cout<< "1";
        if (frame_number_ < 10)
        {
        //x_pos += 5;
        y_pos -= 12;
        if (y_pos < 0) y_pos = 0;
        }
    }
    else frame_number_ = 0;
    if (frame_number_ > 9 )
    {
        frame_number_ = 0;
        status_ = 0;
        checkFlyingStep_ = 0;

    }


    rect_.x = x_pos;
    rect_.y = y_pos;

    // render Bird thứ frame_number_
    SDL_Rect* current_clip = &frame_clip_[frame_number_];
    SDL_Rect renderQuad = {rect_.x, rect_.y, width_frame_, height_frame_};
    SDL_RenderCopy(renderer, p_object_, current_clip, &renderQuad);
    //SDL_Delay(10);
}

void Bird::ShowinPlace(SDL_Renderer* renderer)
{
   if (status_ == Fly_up)
    {
        frame_number_++;
        //cout<< "1";
        if (frame_number_ < 10)
        {
        //x_pos += 5;

        if (y_pos < 0) y_pos = 0;
        }
    }
    else frame_number_ = 0;
    if (frame_number_ > 9 )
    {
        frame_number_ = 0;
        status_ = 0;
        checkFlyingStep_ = 0;

    }


    rect_.x = x_pos;
    rect_.y = y_pos;

    // render Bird thứ frame_number_
    SDL_Rect* current_clip = &frame_clip_[frame_number_];
    SDL_Rect renderQuad = {rect_.x, rect_.y, width_frame_, height_frame_};
    SDL_RenderCopy(renderer, p_object_, current_clip, &renderQuad);
}


void Bird::HandleAction(SDL_Event event, SDL_Renderer* renderer, Audio audio)
{
    if (event.type == SDL_KEYDOWN )

        if (event.key.keysym.sym == SDLK_SPACE )
        {
            status_ = Fly_up;
            audio.PlayChunk();
            checkFlyingStep_ = 1;
            //input_type_.fly_ = 1;
        }

}

void Bird::BirdFall()
{
    x_val = 0;
    y_pos += 5;

    /*if(y_pos <= SCREEN_HEIGHT)
    {
       //x_pos += 20;
        y_pos += 3;
    }*/


}


void Bird::GameOver(SDL_Renderer* renderer)
{
    status_ = 0;
    if (y_pos + width_frame_ < SCREEN_HEIGHT)
    {

        y_pos += 5;
        rect_.x = x_pos;
        rect_.y = y_pos;
        SDL_Rect* src_over1 = &frame_clip_[10];
        SDL_Rect renderQuad = {rect_.x, rect_.y, width_frame_, height_frame_};
        SDL_RenderCopy(renderer, p_object_, src_over1, &renderQuad);
    }
    else
    {
        y_pos = SCREEN_HEIGHT - width_frame_;
        rect_.x = x_pos;
        rect_.y = y_pos;
        SDL_Rect* src_over2 = &frame_clip_[11];
        SDL_Rect renderQuad = {rect_.x, rect_.y, width_frame_, height_frame_};
        SDL_RenderCopy(renderer, p_object_, src_over2, &renderQuad);
    }


}
