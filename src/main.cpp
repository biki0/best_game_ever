#include <iostream>

#ifdef __EMSCRIPTEN__
    #include <emscripten.h>
#endif

#include "Game.hpp"



void main_loop(void){
    
    Game game;
    game.run();

}

int main(int argc, char *argv[]){
   /* 
    #ifdef __EMSCRIPTEN__
            emscripten_set_main_loop(main_loop, 0, 1);
    #endif

    #ifndef __EMSCRIPTEN__
            main_loop;
    #endif
    */    

    //note: mingw32-make to compile
    Game game;
    game.run();
    
    return 0;
}
