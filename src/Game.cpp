#include "Game.hpp"

Game::Game(){

    init_var();
    init_win();
    init_font();

    m_level_1.init(m_renderer);
    m_player.init(m_renderer);


}

Game::~Game(){

    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    TTF_Quit();
    SDL_Quit();

}

void Game::init_var(){
    
    m_is_running = true;


}

void Game::init_win(){

    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "SDL_Init FAILED. SDL_ERROR: " << SDL_GetError() << "\n";
    }

    if(TTF_Init() == -1){
        std::cout << "Failed to init. Error: " << SDL_GetError() << "\n";
    }

    m_window = SDL_CreateWindow("Best Game Ever", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if(m_window == NULL){
        std::cout << "window failed to init. Error: " << SDL_GetError() << "\n";
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

}

void Game::init_font(){

    m_menu_text.set_font_path("assets/PixelSplitter-Bold.ttf");
    m_menu_text.set_text(m_renderer, "game_name", "Best Game Ever", {700, 52},
                         {m_window_width/2 - 350, m_window_height/2 - 52}, 50, {255, 255, 255});



}

void Game::run(){

    float m_current_time = 0.f;
    float m_previous_time = 0.f;
    float m_dt = 0.f;

    while(m_is_running){

        m_current_time = SDL_GetTicks();
        m_dt = (m_current_time - m_previous_time) / 1000;
        m_previous_time = m_current_time;

        handle_events();
        update(m_dt);
        render();
    }

}

void Game::handle_events(){

    while(SDL_PollEvent(&m_event)){
        if(m_event.type == SDL_QUIT){
            m_is_running = false;
        }
        if(m_event.type == SDL_KEYDOWN && m_event.key.keysym.sym == SDLK_ESCAPE){
            m_is_running = false;
        }
    }

    const Uint8 * key_states = SDL_GetKeyboardState(NULL);

    m_player.set_vel_x(0.f);
    if(key_states[SDL_SCANCODE_D]){
        m_player.move_right();
    }
    if(key_states[SDL_SCANCODE_A]){
        m_player.move_left();
    }
    if(key_states[SDL_SCANCODE_X]){
        m_player.get_player()->get_textured_rectangle().set_position(500, 300);
    }
    if(key_states[SDL_SCANCODE_W] || key_states[SDL_SCANCODE_SPACE]){
        m_player.jump();
        m_player.set_in_air(true);
        //m_player.set_in_air(true);
        std::cout << m_player.get_in_air() << "\n";
    }


    
}

void Game::update(float dt){


    m_player.update(dt, m_level_1);

    //m_collision.player_map_col(m_player, m_level_1, dt);

}

void Game::render(){

    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);
 
    //m_menu_text.render(m_renderer, "game_name");



    m_level_1.render();

    m_player.render();



    SDL_RenderPresent(m_renderer);
    
}








