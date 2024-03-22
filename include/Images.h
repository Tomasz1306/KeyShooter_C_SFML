#ifndef IMAGES_H
#define IMAGES_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Images{ 
private:
    std::vector<sf::Texture> bullets;
    std::vector<sf::Texture> coins;
    std::vector<sf::Texture> explosion;
    std::vector<sf::Texture> gold_coin;
    std::vector<sf::Texture> silver_coin;
    std::vector<sf::Texture> red_coin;
    std::vector<sf::Texture> green_coin;

public:
    Images();

    sf::Texture &getExplosionTexture(int index);
    sf::Texture &getBulletTexture(int index);
    sf::Texture &getGoldCoin(int);
    sf::Texture &getSilverCoin(int);
    sf::Texture &getRedCoin(int);
    sf::Texture &getGreenCoin(int);
};




#endif