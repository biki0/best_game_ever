#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "Utils.hpp"
#include "TextureManager.hpp"
#include "Entity.hpp"

class LevelManager{

    public:

        LevelManager();
        ~LevelManager();
        void init(SDL_Renderer* renderer);
        


        void set_level(int arr[TILE_ROW][TILE_COL]);
        void load_textures();
        void load_level();

        void render();


        

        SDL_Renderer* m_renderer;

        int m_level_map[TILE_ROW][TILE_COL];

        std::map<std::string, SDL_Texture*> m_textures;
        std::vector<SDL_Rect> m_texture_rects;

        std::vector<Entity*> m_entities;
        


};

