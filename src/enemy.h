#pragma once

#include "SFML/Graphics/CircleShape.hpp"
#include <SFML/Graphics.hpp>

class Enemy final  {
    private:
        sf::CircleShape *body;
        sf::RenderWindow *win;
    public:
        int velocity;
        bool left, right, top, bottom;
        Enemy(sf::RenderWindow *w = nullptr);
        ~Enemy();
        sf::CircleShape getEnemy();
        void reInit(sf::RenderWindow *w);
        void followPlayer();
        void move(float x, float y);
};
