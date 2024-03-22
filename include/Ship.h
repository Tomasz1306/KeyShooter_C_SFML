#ifndef SHIP_H 
#define SHIP_H_

#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
class Ship{
private:

    sf::Texture t_ship;
    sf::Sprite s_ship;;
    int x;
    int y;
public:
    Ship();
    void setX(int x);
    void setY(int y);
    void rotate(int);
    int getX();
    int getY();
    sf::Sprite getSprite();
    sf::Vector2f getScale();
    sf::Transform getTransform();
};




#endif /* WORD_H_ */