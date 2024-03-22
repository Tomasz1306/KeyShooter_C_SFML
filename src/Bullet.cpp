#include "Bullet.h"

Bullet::Bullet(float x, float y, int id){
	
	this->x = x;
	this->y = y;
	this->dx = 0;
	this->dy = 0;
	this->ndx = 0;		
	this->ndy = 0;
	this->wordId = id;
}	

float Bullet::getX(){
	return this->x;
}
float Bullet::getY(){
	return this->y;
}
float Bullet::getDx(){
	return this->dx;
}
float Bullet::getDy(){
	return this->dy;
}
float Bullet::getNdx(){
	return this->ndx;
}
float Bullet::getNdy(){
	return this->dy;
}
float Bullet::getLength(){
	return this->length;
}
int Bullet::getWordId(){
	return this->wordId;	
}
int Bullet::getIndex(){
	return this->index;
}
void Bullet::setIndex(int index){
	this->index = index;
}
void Bullet::setX(float x){
	this->x = x;
}
void Bullet::setY(float y){
	this->y = y;
}
void Bullet::setDx(float dx){
	this->dx = dx;
}
void Bullet::setDy(float dy){
	this->dy = dy;
}
void Bullet::setNdx(float ndx){
	this->ndx = ndx;
}
void Bullet::setNdy(float ndy){
	this->ndy = ndy;
}
void Bullet::setLength(float len){
	this->length = len;
}
void Bullet::setWordId(int id){
	this->wordId = id;
}

