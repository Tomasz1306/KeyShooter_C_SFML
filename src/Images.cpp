#include "Images.h"

Images::Images(){

    std::string nazwa;
    sf::Texture texture;
    for(int i = 0; i <= 81; i++){
        if(i < 10){
            nazwa = "rsc/PNG/frame000" + std::to_string(i) + ".png";
            if(!texture.loadFromFile(nazwa,sf::IntRect(0,0,150,150))){
                std::cout << "CANT LOAD FILE: " << nazwa << std::endl;
            }
            this->explosion.push_back(texture);
        }else{
            nazwa = "rsc/PNG/frame00" + std::to_string(i) + ".png";
            if(!texture.loadFromFile(nazwa, sf::IntRect(0,0,150,150))){
                std::cout << "CANT LOAD FILE: " << nazwa << std::endl;
            }
            this->explosion.push_back(texture);
        }
    }
    nazwa = "rsc/COIN/gold.png";
    for(int i = 0; i < 24; i++){
        if(!texture.loadFromFile(nazwa,sf::IntRect(i * 16,0,8,8))){
            std::cout << "CANT LOAD FILE: " << nazwa << std::endl;
        }
        this->gold_coin.push_back(texture);
    }
    
    nazwa = "rsc/bullet.png";
    if(!texture.loadFromFile(nazwa,sf::IntRect(0,0,36,18))){
        std::cout << "CANT LOAD FILE: " << nazwa << std::endl;
        }
        this->bullets.push_back(texture);
    std::cout << "NUMBER OF IMAGES OF EXPLOSION: " << this->explosion.size();
}
sf::Texture &Images::getExplosionTexture(int index){
    if(index > this->explosion.size() - 1){
        return this->explosion[0];
    }
    return this->explosion[index];
}
sf::Texture &Images::getBulletTexture(int index){
    if(index > this->bullets.size() - 1){
        return this->bullets[0];
    }
    return this->bullets[index];
}
sf::Texture &Images::getGoldCoin(int index){
    if(index > this->gold_coin.size() - 1){
        return this->gold_coin[0];
    }
    return this->gold_coin[index];    
}
sf::Texture &Images::getSilverCoin(int index){
    if(index > this->silver_coin.size() - 1){
        return this->silver_coin[0];
    }
    return this->silver_coin[index];    
}
sf::Texture &Images::getRedCoin(int index){
    if(index > this->red_coin.size() - 1){
        return this->red_coin[0];
    }
    return this->red_coin[index];    
}
sf::Texture &Images::getGreenCoin(int index){
    if(index > this->green_coin.size() - 1){
        return this->green_coin[0];
    }
    return this->green_coin[index];    
}