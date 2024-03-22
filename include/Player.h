#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>

using namespace std;

class Player {
private:
	int health;
	int score;
	string nick;

public:
	Player();

	void setHealth(int health);
	void setScore(int score);
	void setNick(string nick);

	int getHealth();
	int getScore();
	string getNick();
};

#endif /* PLAYER_H_ */
