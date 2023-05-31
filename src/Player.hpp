#pragma once

#include <iostream>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "Utils.hpp"
#include "Entity.hpp"
#include "LevelManager.hpp"
#include "TextureManager.hpp"


class Player{

    public:

        Player();
        ~Player();
        void init(SDL_Renderer* renderer);

        void set_vel_x(float x);
        void move_left();
        void move_right();
        void jump();
        void set_in_air(bool in_air);
        bool get_in_air();


        Entity* get_player();

        void update(float dt, LevelManager &level);
        void render();

    private:

        SDL_Renderer* m_renderer;

        Entity* m_player;

        Vector_2d m_position;
        Vector_2d m_velocity;
        Vector_2d m_acceleration;
        SDL_Rect m_player_rect;

        const int M_GRAVITY = 9;
        bool m_in_air;
 
        SDL_Texture* m_player_texture;


};