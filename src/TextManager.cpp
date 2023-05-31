#include "TextManager.hpp"

TextManager::TextManager(){
}

TextManager::~TextManager(){

    TTF_CloseFont(m_font);
    delete m_f_path;

}

void TextManager::set_font_path(const char* path){

    m_f_path = path;
    m_font = TTF_OpenFont(path, 30);

}

void TextManager::load_font(SDL_Renderer* renderer, std::string name, std::string &message, 
                            int font_size, SDL_Color color){

    TTF_Font *temp_font = TTF_OpenFont(m_f_path, font_size);
    if(!temp_font){
        std::cout << "Failed to load font. SDL_ERROR: " << SDL_GetError() << "\n";
    }

    SDL_Surface* surface_message = TTF_RenderText_Solid(temp_font, message.c_str(), color);
    if(!surface_message){
        std::cout << "Failed to load surface. SDL_ERROR: " << SDL_GetError() << "\n";
    }

    SDL_Texture* t_texture = SDL_CreateTextureFromSurface(renderer, surface_message);
    if(!t_texture){
        std::cout << "Failed to load text texture. SDL_ERROR: " << SDL_GetError() << "\n";
    }

    SDL_FreeSurface(surface_message);

    TTF_CloseFont(temp_font);

    m_texture_bank[name] = t_texture;

}

void TextManager::set_text(SDL_Renderer* renderer, std::string name, std::string message, 
                            SDL_Point w_h, SDL_Point x_y, int font_size, SDL_Color color){

    load_font(renderer, name, message, font_size, color);

    SDL_Rect font_rect;
    font_rect.w = w_h.x;
    font_rect.h = w_h.y;
    font_rect.x = x_y.x;
    font_rect.y = x_y.y;

    m_texture_rect_bank[name] = font_rect;

}

void TextManager::update_text(SDL_Renderer* renderer, std::string name, std::string &message, 
                                SDL_Point w_h, SDL_Point x_y, SDL_Color color){

    SDL_DestroyTexture(m_texture_bank[name]);

    SDL_Surface* s_surface = TTF_RenderText_Solid(m_font, message.c_str(), color);
    m_texture_bank[name] = SDL_CreateTextureFromSurface(renderer, s_surface);
    
    m_texture_rect_bank[name].w = w_h.x;
    m_texture_rect_bank[name].h = w_h.y;
    m_texture_rect_bank[name].x = x_y.x;
    m_texture_rect_bank[name].y= x_y.y;

    SDL_FreeSurface(s_surface);

}

SDL_Point TextManager::get_width_height(std::string name){

    return { m_texture_rect_bank[name].w, m_texture_rect_bank[name].h };

}

SDL_Point TextManager::get_position(std::string name){

    return { m_texture_rect_bank[name].x, m_texture_rect_bank[name].y };

}

 void TextManager::render(SDL_Renderer* renderer, std::string name){

    SDL_RenderCopy(renderer, m_texture_bank[name], NULL, &m_texture_rect_bank[name]);

}

