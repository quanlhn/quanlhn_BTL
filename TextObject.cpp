#include "TextObject.h"

TextObject::TextObject()
{
    text_color.r = 255;
    text_color.g = 255;
    text_color.b = 255;
    texture_ = NULL;
}

TextObject::~TextObject()
{

}

bool TextObject::LoadFromRenderText(TTF_Font* font, SDL_Renderer* renderer)
{
    SDL_Surface* text_surface = TTF_RenderText_Solid(font, str_val_ .c_str(), text_color);
    if (text_surface)
    {
        texture_ = SDL_CreateTextureFromSurface(renderer, text_surface);
        width_ = text_surface->w;
        height_ = text_surface->h;
        SDL_FreeSurface(text_surface);
    }
    return texture_ != NULL;
}

void TextObject::Free()
{
    if (texture_ != NULL)
    {
        SDL_DestroyTexture(texture_);
        texture_ = NULL;
    }
}

void TextObject::SetColor(Uint8 red, Uint8 green, Uint8 blue)
{
    text_color.r = red;
    text_color.g = green;
    text_color.b = blue;
}

void TextObject::SetColor(int type)
{
    if (type == RED_TEXT)
    {
        SDL_Color color = {255, 0, 0};
        text_color = color;
    }
    else if (type == WHITE_TEXT)
    {
        SDL_Color color = {255, 255, 255};
        text_color = color;
    }
    else if (type == BLACK_TEXT)
    {
        SDL_Color color = {0, 0, 0};
        text_color = color;
    }
}

void TextObject::RenderText(SDL_Renderer* renderer, int x_pos, int y_pos, SDL_Rect* src /*= NULL*/,
                            double angle /*= 0.0*/, SDL_Point* center /*= NULL*/, SDL_RendererFlip flip /*= SDL_FLIP_NONE*/)
{
    SDL_Rect renderQuad = {x_pos, y_pos, width_, height_};
    if (src != NULL)
    {
        renderQuad.w = src->w;
        renderQuad.h = src->h;
    }
    SDL_RenderCopyEx(renderer, texture_, src, &renderQuad, angle, center, flip );
}
