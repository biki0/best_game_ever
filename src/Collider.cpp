#include "Collider.hpp"

Collider::Collider(){
    m_rectangle = new SDL_Rect;
    m_rectangle->x = 0;
    m_rectangle->y = 0;
    m_rectangle->w = 0;
    m_rectangle->h = 0;
}

Collider::~Collider(){
    delete m_rectangle;
}

void Collider::set_absolute_position(int x, int y){
    m_rectangle->x = x;
    m_rectangle->y = y;
}

void Collider::set_dimensions(int w, int h){
    m_rectangle->w = w;
    m_rectangle->h = h;
}

SDL_Rect& Collider::get_collider_bounding_box(){
    return *m_rectangle;
}

SDL_bool Collider::is_colliding(Collider& collider){

    if(m_rectangle == nullptr){
        return SDL_FALSE;
    }
    const SDL_Rect* temp = collider.m_rectangle;
    if(temp == nullptr){
        return SDL_FALSE;
    }
    return SDL_HasIntersection(m_rectangle, temp);

}

