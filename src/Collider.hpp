#pragma once

#include <iostream>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

class Collider{

    public:
        Collider();
        ~Collider();

        void set_absolute_position(int x, int y);
        void set_dimensions(int w, int h);

        SDL_Rect& get_collider_bounding_box();
        SDL_bool is_colliding(Collider& collider);

        

    private:
        SDL_Rect* m_rectangle;


};