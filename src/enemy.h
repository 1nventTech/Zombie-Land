#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Enemy final  {
    private:
        sf::RenderWindow *win;
        sf::Sprite sprite;
    public:
        sf::Texture texture;
        int hp, xp, velocity;
        bool left, right, top, bottom;
        Enemy(sf::RenderWindow *w = nullptr, float x=0, float y=0, std::string txt = "../assets/player-placeholder.png");
        ~Enemy();
        sf::Sprite getEnemy();
        void reInit(sf::RenderWindow *w);
        void followPlayer();
        void move(float x, float y);
};
