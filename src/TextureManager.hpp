#pragma once

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class TextureManager{

    public:

        TextureManager();

        static SDL_Texture* LoadTexture(SDL_Renderer* p_renderer, const char* p_path);
        static void RenderTexture(SDL_Renderer* p_renderer, SDL_Texture* p_tex, SDL_Rect p_dest);




};




