#include <bird.hpp>


bird::bird(SDL_Renderer* __renderbird):renderimg(__renderbird){
    birdtexture = IMG_LoadTexture(renderimg,"gfx/characters/FLAPPY_2.png");

    m_position.x = 500;
    m_position.y = 500;   
    m_position.w = 75;
    m_position.h = 75;
    
    m_x = 200.0;
    m_y = 100.0;
}

void bird::update(double delta_time){
    
    Uint8 const *keys = SDL_GetKeyboardState(nullptr);
    // m_x=m_x+(20*delta_time);
    // m_y+=1;
    
    if(m_y<=700)
    m_y+=(accel*(20*delta_time));

    m_position.x = (int)m_x;
    m_position.y = (int)m_y;
    accel+=0.10;
    

}

SDL_Rect bird::rect(){
    return m_position;
}
int bird::getx(){
    return m_x;
}

int bird::gety(){
    return m_y;
}

void bird::jump(){
    
    accel=-5;
}

void bird::draw(){
    SDL_RenderCopyEx(renderimg, birdtexture, NULL, &m_position, 0.0, NULL, SDL_FLIP_NONE);
}
