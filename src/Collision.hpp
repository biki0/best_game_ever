#pragma once

#include <iostream>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "Utils.hpp"
#include "Player.hpp"
#include "LevelManager.hpp"

class Collision{

    public:
        
        Collision();

        void player_map_col(Player &player, LevelManager &level, float dt);


    private:





};