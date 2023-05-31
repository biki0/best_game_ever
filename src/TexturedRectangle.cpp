#include "TexturedRectangle.hpp"


TexturedRectangle::TexturedRectangle(SDL_Renderer* renderer, std::string sprite_path){

    m_texture = TextureManager::LoadTexture(renderer, sprite_path.c_str());

}

TexturedRectangle::TexturedRectangle(SDL_Texture* texture){
    m_texture = texture;
}

TexturedRectangle::~TexturedRectangle(){
    SDL_DestroyTexture(m_texture);
}

void TexturedRectangle::set_position(int x, int y){
    m_rectangle.x = x;
    m_rectangle.y = y;
}

void TexturedRectangle::set_x_position(int x){
    m_rectangle.x = x;
}

void TexturedRectangle::set_y_position(int y){
    m_rectangle.y = y;
}

void TexturedRectangle::set_dimensions(int w, int h){
    m_rectangle.w = w;
    m_rectangle.h = h;
}

int TexturedRectangle::get_x_position(){
    return m_rectangle.x;
}

int TexturedRectangle::get_y_position(){
    return m_rectangle.y;
}

int TexturedRectangle::get_width(){
    return m_rectangle.w;
}

int TexturedRectangle::get_height(){
    return m_rectangle.h;
}

SDL_Rect& TexturedRectangle::get_rect(){
    return m_rectangle;
}

SDL_Texture* TexturedRectangle::get_texture(){
    return m_texture;
}



void TexturedRectangle::update(){

}

void TexturedRectangle::render(SDL_Renderer* renderer){
    SDL_RenderCopy(renderer, m_texture, NULL, &m_rectangle);
}