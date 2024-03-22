#include "Game.h"

Game::Game() {
	this->time = 0;
}

void Game::InitializeGame(){
	this->system.generateWords(1);
}
void Game::gameDraw(RenderWindow &window, float time){
	this->system.drawWords(window, time);
}
void Game::gameUpdate(float deltaTime, float time){
	this->time = time;
	this->system.updatePosition(deltaTime, time);
}
void Game::gameEvent(RenderWindow &window, Event event){
	this->system.systemEvent(window, event);
}

