#include "Ship.h"

Ship::Ship(){

    std::cout << "LADOWANIE STTATKU" << std::endl;
    if(!this->t_ship.loadFromFile("src/ship.png",sf::IntRect(10,10,50,50))){
        std::cout << "CANT LOAD SHIP" << std::endl;
    }
    this->x = 30; 
    this->y = 450; 
    this->s_ship.setTexture(this->t_ship);
    this->s_ship.setPosition(this->x, this->y);
    this->s_ship.setScale(3.0f,3.0f);
    this->s_ship.setOrigin(25,25);
    this->s_ship.rotate(90);
}
void Ship::setX(int x){
    this->x = x;
    this->s_ship.setPosition(this->x, this->y);
}
void Ship::setY(int y){
    this->y = y;
    this->s_ship.setPosition(this->x, this->y);
}
int Ship::getX(){
    return this->x;
}
int Ship::getY(){
    return this->y;
}
void Ship::rotate(int angel){
    this->s_ship.setRotation(angel);
    
}
sf::Sprite Ship::getSprite(){
    return this->s_ship;
}
sf::Vector2f Ship::getScale(){
    return this->s_ship.getScale();
}
sf::Transform Ship::getTransform(){
    return this->s_ship.getTransform();
}