#include "Player.hpp"

Player::Player(){

    m_position.x = 32.f;
    m_position.y = 32.f;
    
    m_velocity.x = 0.f;
    m_velocity.y = 300.f;

    m_acceleration.x = 150.f;
    m_acceleration.y = 700.f;

    m_in_air = true;

    m_player_rect = {(int)m_position.x, (int)m_position.y, 32, 32};

}

Player::~Player(){
    delete m_player;
}

void Player::init(SDL_Renderer* renderer){
    m_renderer = renderer;

    m_player_texture = TextureManager::LoadTexture(m_renderer, "assets/player2.png");

    m_player = new Entity(m_renderer);
    m_player->add_textured_rectangle_component("assets/player2.png", 350, 100, 32, 32);
    m_player->add_collider_component();
    

}

Entity* Player::get_player(){
    return m_player;
}

void Player::set_vel_x(float x){
    m_velocity.x = x;
}

void Player::move_right(){
    m_velocity.x += m_acceleration.x;
}

void Player::move_left(){
    m_velocity.x -= m_acceleration.x;
}

void Player::jump(){
    m_velocity.y = -m_acceleration.y;
    m_in_air = true;
}

void Player::set_in_air(bool in_air){ m_in_air = in_air; }
bool Player::get_in_air(){ return m_in_air; }


void Player::update(float dt, LevelManager &level){
    m_velocity.y += M_GRAVITY;

    m_position.x += m_velocity.x * dt;
    m_position.y += m_velocity.y * dt;
    
    m_player->get_textured_rectangle().set_position(m_position.x, m_position.y);

    //floor col
    if(m_player->get_textured_rectangle().get_y_position() + m_player->get_textured_rectangle().get_height() >= SCREEN_HEIGHT){
        //m_player_pos.y = SCREEN_HEIGHT - m_player_rect.h;
        m_player->get_textured_rectangle().set_y_position(SCREEN_HEIGHT - m_player->get_textured_rectangle().get_height());
        m_velocity.y = 0.f;
        m_in_air = false;
        //std::cout << m_in_air << "\n";
    }

    //map collision
    for(int i=0; i<level.m_entities.size(); ++i){
        if(m_player->get_textured_rectangle().get_y_position() + m_player->get_textured_rectangle().get_height() >= level.m_entities[i]->get_textured_rectangle().get_y_position() &&
            m_player->get_textured_rectangle().get_y_position() <= level.m_entities[i]->get_textured_rectangle().get_y_position() + level.m_entities[i]->get_textured_rectangle().get_height() &&
            m_player->get_textured_rectangle().get_x_position() + m_player->get_textured_rectangle().get_width() >= level.m_entities[i]->get_textured_rectangle().get_x_position() &&
            m_player->get_textured_rectangle().get_x_position() <= level.m_entities[i]->get_textured_rectangle().get_x_position() + level.m_entities[i]->get_textured_rectangle().get_width() &&
            m_velocity.y >= 0.f){

            m_player->get_textured_rectangle().set_y_position(level.m_entities[i]->get_textured_rectangle().get_y_position() - m_player->get_textured_rectangle().get_height()+8);
            
            m_in_air = false;
            //std::cout << m_in_air << "\n";
            m_velocity.y = 0.f;

        }
    }

}

void Player::render(){

    //SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    //TextureManager::RenderTexture(m_renderer, m_player_texture, m_player_rect);
    m_player->render();
}



