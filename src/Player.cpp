#include "Player.h"

Player::Player() {


}

void Player::setHealth(int health){
	this->health = health;
}
void Player::setScore(int score){
	this->score = score;
}
void Player::setNick(string nick){
	this->nick = nick;
}

int Player::getHealth(){
	return this->health;
}
int Player::getScore(){
	return this->score;
}
