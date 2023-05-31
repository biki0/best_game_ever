#pragma once

#include <iostream>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "Utils.hpp"
#include "Player.hpp"
#include "LevelManager.hpp"
#include "Collision.hpp"
#include "TextManager.hpp"
#include "SoundManager.hpp"



class Game{

    public:

        Game();
        ~Game();

        
        void run();


    private:

        void handle_events();
        void update(float dt);
        void render();

        void init_var();
        void init_win();
        void init_font();

        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
        SDL_Event m_event;

        Player m_player;

        LevelManager m_level_1;

        TextManager m_menu_text;


        const int m_window_width = 1600;
        const int m_window_height = 640;
        bool m_is_running;

        
};