#pragma once

#include <iostream>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "TextureManager.hpp"

class TexturedRectangle{

    public:

        TexturedRectangle(SDL_Renderer* renderer, std::string sprite_path);
        TexturedRectangle(SDL_Texture* texture);
        ~TexturedRectangle();

        void set_position(int x, int y);
        void set_x_position(int x);
        void set_y_position(int y);
        void set_dimensions(int w, int h);

        int get_x_position();
        int get_y_position();
        int get_width();
        int get_height();

        SDL_Rect& get_rect();
        SDL_Texture* get_texture();

        void update();
        void render(SDL_Renderer* renderer);

    private:

        SDL_Rect m_rectangle;
        SDL_Texture* m_texture;

};