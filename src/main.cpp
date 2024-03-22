#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "Game.h"
using namespace std;
using namespace sf;
int main() {
	RenderWindow window(VideoMode(1800, 800), "sfml");


	Game game;
	game.InitializeGame();

	cout << "Udalo sie zainicjalizowac gre" << endl;
	Clock clock,clock2;
	Time elapsed, elapsed2;


	window.setFramerateLimit(120);
	while (window.isOpen()) {
		Event event;

		elapsed = clock.restart();
		float deltaTime = elapsed.asSeconds();

		elapsed2 = clock2.getElapsedTime();
		window.clear();
		//cout << "ELAPSED: " << elapsed2.asSeconds() << " DELTA TIME: " << deltaTime << endl;
		game.gameEvent(window, event);
		game.gameUpdate(deltaTime, elapsed2.asSeconds());
		game.gameDraw(window, elapsed2.asSeconds());
		window.display();
	}
	return 0;
}
