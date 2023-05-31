#include "TextureManager.hpp"

TextureManager::TextureManager(){}


SDL_Texture* TextureManager::LoadTexture(SDL_Renderer* p_renderer, const char* p_path){

    SDL_Surface* tempSurface = IMG_Load(p_path);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(p_renderer, tempSurface);
    
    SDL_FreeSurface(tempSurface);
    
    return tex;
}

void TextureManager::RenderTexture(SDL_Renderer* p_renderer, SDL_Texture* p_tex, SDL_Rect p_dest){

    SDL_RenderCopy(p_renderer, p_tex, NULL, &p_dest);

}


