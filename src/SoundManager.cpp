#include "SoundManager.hpp"

SoundManager::SoundManager(){

    SDL_Init(SDL_INIT_AUDIO);

    audio_rate = 22050;
    audio_format = AUDIO_S16SYS;
    audio_channels = 2;
    audio_buffers = 4096;

    if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0){
        std::cout << "Failed to init audio. SDL_ERROR: " << SDL_GetError() << "\n";
    }

}

SoundManager::~SoundManager(){

    SDL_Quit();

}

void SoundManager::add_sound(std::string name, const char* path){

    Mix_Chunk* temp_chuck = Mix_LoadWAV(path);

    if(temp_chuck != nullptr){
        sound_bank[name] = temp_chuck;
    }
    else{
        std::cout << "Failed to add sound. SDL_ERROR: " << SDL_GetError() << "\n";
    }
    
}

void SoundManager::play_sound(const std::string which){

    Mix_PlayChannel(-1, sound_bank[which], 0);

}