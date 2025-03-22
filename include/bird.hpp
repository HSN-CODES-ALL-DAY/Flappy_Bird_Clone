#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <Math.h>

class bird{
    public:
    // Vector2f &i;
    bird(SDL_Renderer* __renderbird);
    ~bird() = default;
    void draw();
    void update(double delta_time);
    void jump();
    int getx();
    int gety();
    SDL_Rect rect();
    private:
    SDL_Renderer *renderimg;
    SDL_Texture *birdtexture;
    SDL_Rect     m_position;
    double  accel=0;
    double       m_x;
    double       m_y;
};