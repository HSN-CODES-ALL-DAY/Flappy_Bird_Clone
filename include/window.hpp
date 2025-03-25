#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "bird.hpp"
#include "poles.hpp"


// colitions
class window{
    public:
    window();
    void loop();
    void background();
    void draw();
    void update(double delta_time);
    void keyinput();
    void checkcollisions();
    private:
    bool keep_window_open = true;
    SDL_Renderer *renderimg;
    SDL_Texture *skytexture;
    SDL_Event WINDOW_EVENT;
    SDL_Window *WINDOW;
    bird flappy;
    poles pole;
    poles pole2;
    poles pole3;
    poles pole4;
    // poles pole5;
};