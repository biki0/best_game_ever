#pragma once

#include <iostream>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "Utils.hpp"
#include "TexturedRectangle.hpp"
#include "Collider.hpp"


class Entity{

    public:

        Entity();
        Entity(SDL_Renderer* renderer);
        Entity(SDL_Renderer* renderer, std::string sprite_path);
        ~Entity();

        void add_textured_rectangle_component(std::string sprite_path, int x, int y, int w, int h);
        void add_collider_component();

        TexturedRectangle& get_textured_rectangle();
        Collider& get_collider(size_t index);


        void update();
        void render();

    private:

        TexturedRectangle* m_sprite;
        std::vector<Collider*> m_colliders;

        SDL_Renderer* m_renderer;

};