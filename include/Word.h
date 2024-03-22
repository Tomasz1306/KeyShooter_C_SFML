#ifndef WORD_H_
#define WORD_H_


#include <list>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Word{
public:
	//list<char> word;
	list<Text> word;

	int id;
	float x;
	float y;

	float speed;
	int spawnDelay;
	float delay;
	bool inBoard;
	bool active;
	bool ready;
	int health;
	int size;

	RectangleShape rect;
	RectangleShape rect2;

public:
	Word();
	Word(string str, int id);
	Word(string str, float x, float y, int id);

	void setX(float);
	void setY(float);
	void setHealth(int);
	void setId(int);
	void setSpeed(float);
	void setSpawnDelay(int);
	void setDelay(float);
	void setInBoard(bool);
	void setActive(bool);
	void setRectPos(int, int);
	bool copy(Word &w);
	void setReady(bool);
	int destroyChar(char x); //1 if word exist and 0 if this is last char in word

	int getHealth();
	float getX();
	float getY();
	int getId();
	float getSpeed();
	int getSpawnDelay();
	float getDelay();
	bool getInBoard();
	bool getActive();
	bool getReady();
	RectangleShape getRect();
	RectangleShape getHealtRect();
	int getHealtX();
	int getHealtY();


	Text getCharText(int index);
	char getChar(int index);
	char getFirst();

	void addWord(string);

	int getSize();
	string getWord();

};

#endif /* WORD_H_ */
