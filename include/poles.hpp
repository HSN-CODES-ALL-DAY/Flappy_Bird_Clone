#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class poles{
    public:
    poles(SDL_Renderer* __renderpoles);
    ~poles() = default;
    void draw();
    void update(double delta_time);
    int getx();
    int gety();
    SDL_Rect rect();
    SDL_Rect rect2();
    private:
    SDL_Renderer *renderimage;
    SDL_Texture *polestexture;
    SDL_Rect     m_position;
    SDL_Rect     m_position_2;
    double       m_x;
    double       m_y;

};