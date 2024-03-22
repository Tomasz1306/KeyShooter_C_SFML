#ifndef GAME_H_
#define GAME_H_

#include <iomanip>
#include "System.h"

class Game {
private:
	float time;
	System system;

public:
	Game();

	void InitializeGame();
	void gameUpdate(float deltaTime, float time);
	void gameDraw(RenderWindow &window, float time);
	void gameEvent(RenderWindow &window, Event event);

};

#endif /* GAME_H_ */
