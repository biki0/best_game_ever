#include "Collision.hpp"

Collision::Collision(){


}


void Collision::player_map_col(Player &player, LevelManager &level, float dt){

    // for(int i=0; i<level.idk.size(); ++i){
    //     if(m_player_pos.y + m_player_rect.h >= level.idk[i].y &&
    //         m_player_pos.y <= level.idk[i].y + level.idk[i].h &&
    //         m_player_pos.x + m_player_rect.w >= level.idk[i].x &&
    //         m_player_pos.x <= level.idk[i].x + level.idk[i].w &&
    //         m_player_vel.y >= 0.f){

    //         m_player_pos.y = level.idk[i].y - m_player_rect.h;
    //         m_in_air = false;
    //                 //std::cout << m_in_air << "\n";
    //         m_player_vel.y = 0.f;

    //     }
    // }
    
    // player.update(dt, level);

    // for(int i=0; i<level.idk.size(); ++i){

    //     if(player.get_pos_y() + player.get_height() >= level.idk[i].y &&
    //        player.get_pos_y() <= level.idk[i].y + level.idk[i].h &&
    //        player.get_pos_x() + player.get_width() >= level.idk[i].x &&
    //        player.get_pos_x() <= level.idk[i].x + level.idk[i].w &&
    //        player.get_vel_y() >= 0.f){

    //         player.set_pos_y(level.idk[i].y - player.get_height());
    //         player.set_in_air(false);
    //         player.set_vel_y(0.f);

    //        }
        
        


    


    //  if(player.get_pos_y() + player.get_height() >= SCREEN_HEIGHT){
    //     player.set_pos_y(SCREEN_HEIGHT - player.get_height());
    //     player.set_vel_y(0.f);
    //     player.set_in_air(false);
    //  }




}

