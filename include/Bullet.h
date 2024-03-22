#ifndef BULLET_H_ 
#define BULLET_H_

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;
class Bullet{
private:
	float x;
	float y;
	float dx;
	float dy;
	float length;
	float ndx;
	float ndy;
	int wordId;
	int index;

public:
	
	Bullet(float x, float y, int id);
	float getX();
	float getY();
	float getDx();
	float getDy();
	float getNdx();
	float getNdy();
	float getLength();
	int getWordId();
	int getIndex();

	void setX(float);
	void setY(float);
	void setDx(float);
	void setDy(float);
	void setNdx(float);
	void setNdy(float);
	void setLength(float);
	void setWordId(int);
	void setIndex(int);

};

#endif /* BULLET_H_ */
