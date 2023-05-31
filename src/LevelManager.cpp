#include "LevelManager.hpp"

int lvl1[TILE_ROW][TILE_COL] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,2,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,2,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

LevelManager::LevelManager(){
    
    set_level(lvl1);

}

LevelManager::~LevelManager(){

    for(int i=0; i<m_entities.size(); ++i){
        delete m_entities[i];
    }

    for(auto const &ent1 : m_textures){
        SDL_DestroyTexture(ent1.second);
    }
    

}

void LevelManager::init(SDL_Renderer* renderer){
    m_renderer = renderer;
    load_textures();
    load_level();
}


void LevelManager::load_textures(){

    m_textures["grass"] = TextureManager::LoadTexture(m_renderer, "assets/grass.png");


}

void LevelManager::set_level(int arr[20][50]){

    for(int x=0; x<TILE_ROW; ++x){
        for(int y=0; y<TILE_COL; ++y){
                m_level_map[x][y] = lvl1[x][y];
                if(m_level_map[x][y] != 0){
                    //length = length + 1;
                }
        }
    }
    //m_entities.resize(length);
    std::cout << "Level loaded" << "\n";

}

void LevelManager::load_level(){
    int tile_id = 0;
    
    for(int x = 0; x < TILE_ROW; ++x){
        for(int y = 0; y < TILE_COL; ++y){        

            tile_id = m_level_map[x][y];
            
            Vector_2d pos;
            pos.x = y * 32;
            pos.y = x * 32;
            
            switch(tile_id) {
                
                case 0: {
                    break;
                }
                case 1: {

                    Entity* grass_entity = new Entity(m_renderer);
                    grass_entity->add_textured_rectangle_component("assets/grass.png", pos.x, pos.y, 32, 32);
                    grass_entity->add_collider_component();
                    grass_entity->get_collider(0).set_absolute_position(pos.x, pos.y);
                    grass_entity->get_collider(0).set_dimensions(32, 32);
                    m_entities.push_back(grass_entity);
                    std::cout << "CALLED" << "\n";
                    
                    break;
                }
                default: {
                    break;
                }
                
            }
                
        }
    }    
}

void LevelManager::render(){

    
    
    for(int i=0; i<m_entities.size(); ++i){

        m_entities[i]->render();

    }

    // int tile_id = 0;


    // for(int x = 0; x < TILE_ROW; ++x){
    //     for(int y = 0; y < TILE_COL; ++y){        

    //         tile_id = m_level_map[x][y];

    //         SDL_Rect temp_rect;
    //         temp_rect.w = 32;
    //         temp_rect.h = 32;
    //         temp_rect.x = y * 32;
    //         temp_rect.y = x * 32;

    //         Vector_2d pos;
    //         pos.x = y*32;
    //         pos.y = x*32;
            
    //         switch(tile_id) {
                
    //             case 0: {
    //                 break;
    //             }
    //             case 1: {

    //                 m_texture_rects.push_back(temp_rect);
    //                 //m_entities.push_back(Entity(m_textures["grass"], pos, 32, 32));
    //                 TextureManager::RenderTexture(m_renderer, m_textures["grass"], temp_rect);
                    
    //                 break;
    //             }
    //             default: {
    //                 break;
    //             }
                
    //         }
                
    //     }
    // }

    //std::cout << idk[10].y<< "XD\n";

}