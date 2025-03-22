#include "poles.hpp"
#include <cstdlib>

poles::poles(SDL_Renderer* __renderpole):renderimage(__renderpole){
    polestexture = IMG_LoadTexture(renderimage,"gfx/background/POLE.png");
    // srand(std::time(0));

    m_position.x = 500;
    m_position.y = 500;   
    m_position.w = 100;
    m_position.h = 500;
    
    m_x = 1000.0;
    m_y = 500.0;


    // m_position_2.x = m_position.x;
    // m_position_2.y = m_position.y+m_position.w+100;   
    // m_position_2.w = m_position.w;
    // m_position_2.h = m_position.h;

    m_position_2.x = m_position.x;
    m_position_2.y = m_position.y - 700;   
    m_position_2.w = m_position.w;
    m_position_2.h = m_position.h;

}
SDL_Rect poles::rect(){
    return m_position;
}

SDL_Rect poles::rect2(){
    return m_position_2;
}


void poles::update(double delta_time){
    
    // Uint8 const *keys = SDL_GetKeyboardState(nullptr);
    m_x=m_x-(20*delta_time);
    // m_y+=1;

    // case SDL_MOUSEBUTTONDOWN:
    // m_y-=1;

    m_position.x = (int)m_x;
    m_position_2.x = (int)m_x;
    m_position.y = (int)m_y;
    m_position_2.y = (int)m_y-700;
    if (m_x <= -100){
        m_y=(rand() % 700)+300;
        m_x=1250;
    }

}

int poles::getx(){
return m_x;

}

int poles::gety(){
    return m_y;

}

void poles::draw(){
    SDL_RenderCopyEx(renderimage, polestexture, NULL, &m_position, 0.0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(renderimage, polestexture, NULL, &m_position_2, 0.0, NULL, SDL_FLIP_NONE);
}
