#pragma once

#include <iostream>
#include <vector>
#include <map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>


class SoundManager{

    public:

        SoundManager();
        ~SoundManager();

        void add_sound(std::string name, const char* path);
        void play_sound(const std::string which);

    private:

        std::map<std::string, Mix_Chunk*> sound_bank;

        int audio_rate;
        Uint16 audio_format;
        int audio_channels;
        int audio_buffers;

        

};