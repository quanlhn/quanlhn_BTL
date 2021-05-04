#ifndef TEXT_OBJECT_H_
#define TEXT_OBJECT_H_

#include "CommonFunc.h"

class TextObject
{
public:
    TextObject();
    ~TextObject();
    enum TextColor
    {
        RED_TEXT = 0,
        WHITE_TEXT = 1,
        BLACK_TEXT = 2,
    };

    bool LoadFromRenderText(TTF_Font* font, SDL_Renderer* renderer);
    void Free();
    void SetColor(Uint8 red, Uint8 green, Uint8 blue);
    void SetColor(int type);
    void RenderText(SDL_Renderer* renderer, int x_pos, int y_pos, SDL_Rect* src = NULL,
                    double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
    int GetWidth() const {return width_;}
    int GetHeight() const {return height_;}
    void SetText (const string& text) {str_val_ = text;}
    string GetText() const {return str_val_;}
private:
    string str_val_;
    SDL_Color text_color;
    SDL_Texture* texture_;
    int width_;
    int height_;

};


#endif // TEXT_OBJECT_H_
