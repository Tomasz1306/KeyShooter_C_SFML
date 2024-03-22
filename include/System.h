#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <cstdlib>
#include "Word.h"
#include "Random.h"
#include "Bullet.h"
#include "Explosion.h"
#include "Images.h"
#include "Ship.h"
#include "Coin.h"
#include <cmath>
using namespace std;
using namespace sf;

class System{
private:
	list<Word> wordR; //Words ready
	list<Word> wordB; //Words in Board
	Images g_image;
	list<Bullet> bullets;
	list<Explosion> g_explosion;
	list<Coin> g_coin;
	Coin static_coin;	
	Ship g_ship;
	
	Word activeWord;
	int level;

	Text text;
	Font font;

	int active;
	Clock clock_global;
	Clock clock_level;
	Time elapsed_global;
	Time elapsed_level;
	string wyrazy[100];
	int money{0};
public:

	System();
	void addWord();
	Word getWord(int id);
	int getSize();
	void generateWords(int level);
	void drawWords(RenderWindow &window, float time);
	void updatePosition(float deltaTime, float time);
	void systemEvent(RenderWindow &window, Event event);
	void setActive(int x);
	void shoot(char key);
	void addWordsToBoard();
	void newAddWordsToBoard();

	int getActive();
};



#endif /* SYSTEM_H_ */
