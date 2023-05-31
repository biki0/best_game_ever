#pragma once

#include <iostream>
#include <string>
#include <map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class TextManager{

    public:
        
        TextManager();
        ~TextManager();

        void set_font_path(const char* path);

        void set_text(SDL_Renderer* renderer, std::string name, std::string message, 
                        SDL_Point w_h, SDL_Point x_y, int font_size, SDL_Color color);

        void update_text(SDL_Renderer* renderer, std::string name, std::string &message, 
                            SDL_Point w_h, SDL_Point x_y, SDL_Color color);
        
        SDL_Point get_width_height(std::string name);
        SDL_Point get_position(std::string name);

        void render(SDL_Renderer* renderer, std::string name);

    private:

        void load_font(SDL_Renderer* renderer, std::string name, std::string &message,
                        int font_size, SDL_Color color);

        const char* m_f_path;
        TTF_Font* m_font;

        std::map<std::string, SDL_Texture*> m_texture_bank;
        std::map<std::string, SDL_Rect> m_texture_rect_bank;

};