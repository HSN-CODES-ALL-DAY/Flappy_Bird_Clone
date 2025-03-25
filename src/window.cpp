#include "window.hpp"
#include <iostream>



window::window():
flappy(nullptr),
pole(nullptr,100),
pole2(nullptr,100),
pole3(nullptr,100),
pole4(nullptr,100)

{
    bool keep_window_open = true;
    if (SDL_Init(SDL_INIT_VIDEO) > 0) {
        std::cerr << "SDL FAILED TO LOAD \n";
        std::cerr << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }
    if (!IMG_Init(IMG_INIT_PNG)) {
        std::cerr << "IMG_Init Has failed \n";
        std::cerr << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }
    SDL_Window *WINDOW = SDL_CreateWindow("TITLE",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,1280,800,SDL_WINDOW_RESIZABLE);
    if (!WINDOW) {
        std::cerr << "Failed to create window\n";
        std::cerr << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }

    renderimg = SDL_CreateRenderer(WINDOW, -1, SDL_RENDERER_ACCELERATED);
    if (!renderimg) {
        std::cerr << "Failed to CreateRender \n";
        std::cerr << "SDL2 Error: " << SDL_GetError() << "\n";
    }
    flappy={renderimg};
    pole={renderimg,1000};
    pole2={renderimg,650};
    pole3={renderimg,300};
    pole4={renderimg,10};
    // pole5={renderimg,400};
}

void window::loop(){
    
    while (keep_window_open) {
        while (SDL_PollEvent(&WINDOW_EVENT) > 0) {
            keyinput();
            switch (WINDOW_EVENT.type) {
                case SDL_QUIT:
                    keep_window_open = false;
                    break;
            }
        }
        update(1.0/60.0);
        draw();
    }

}
void window::update(double delta_time){
    flappy.update(delta_time);
    pole.update(delta_time);

    pole2.update(delta_time);
    pole3.update(delta_time);
    pole4.update(delta_time);
    checkcollisions();
}

void window::checkcollisions(){
    if(SDL_HasIntersection(&flappy.rect(), &pole.rect())||SDL_HasIntersection(&flappy.rect(), &pole.rect2())){
        keep_window_open=false;
    }
    if(SDL_HasIntersection(&flappy.rect(), &pole2.rect())||SDL_HasIntersection(&flappy.rect(), &pole2.rect2())){
        keep_window_open=false;
    }
    if(SDL_HasIntersection(&flappy.rect(), &pole3.rect())||SDL_HasIntersection(&flappy.rect(), &pole3.rect2())){
        keep_window_open=false;
    }
    if(SDL_HasIntersection(&flappy.rect(), &pole4.rect())||SDL_HasIntersection(&flappy.rect(), &pole4.rect2())){
        keep_window_open=false;
    }
}

void window::background(){
    skytexture = IMG_LoadTexture(renderimg,"gfx/background/sky2.png");
    SDL_RenderCopy(renderimg,skytexture,NULL,NULL);
}

void window::keyinput(){
    switch (WINDOW_EVENT.type) {
        case SDL_MOUSEBUTTONDOWN:
            flappy.jump();
            break;
        case SDL_SCANCODE_SPACE:
            flappy.jump();
            break;
    }
}



void window::draw() { 
    SDL_RenderClear(renderimg);
    background();
    flappy.draw();
    pole.draw();
    pole2.draw();
    pole3.draw();
    pole4.draw();
    SDL_RenderPresent(renderimg);
    SDL_DestroyTexture(skytexture);
}