#include "Explosion.h"

void Explosion::setX(int x){
    this->x = x;
}
void Explosion::setY(int y){
    this->y = y;
}
void Explosion::setIndex(int index){
    this->index = index;
}
void Explosion::setId(int id){
    this->id = id;
}
int Explosion::getX(){
    return this->x;
}
int Explosion::getId(){
    return this->id;
}
int Explosion::getY(){
    return this->y;
}
int Explosion::getIndex(){
    return this->index;
}