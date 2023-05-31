#include "Entity.hpp"

Entity::Entity(){
    m_sprite = nullptr;
}

Entity::Entity(SDL_Renderer* renderer){
    m_renderer = renderer;
    m_sprite = nullptr;
}

Entity::Entity(SDL_Renderer* renderer, std::string sprite_path){
    m_renderer = renderer;
    m_sprite = new TexturedRectangle(m_renderer, sprite_path);
    m_colliders.push_back(new Collider());
}

void Entity::add_textured_rectangle_component(std::string sprite_path, int x, int y, int w, int h){
    m_sprite = new TexturedRectangle(m_renderer, sprite_path);
    m_sprite->set_position(x, y);
    m_sprite->set_dimensions(w, h);
}

void Entity::add_collider_component(){
    m_colliders.push_back(new Collider());
}

Entity::~Entity(){

    if(nullptr != m_sprite){
        delete m_sprite;
    }
    for(int i=0; i<m_colliders.size(); ++i){
        delete m_colliders[i];

    }

}

TexturedRectangle& Entity::get_textured_rectangle(){
    return *m_sprite;
}

Collider& Entity::get_collider(size_t index){
    return *m_colliders[index];
}

void Entity::update(){


}

void Entity::render(){

    if(m_sprite != nullptr){
        m_sprite->render(m_renderer);
    }



}