#pragma once

#include <SFML/Graphics.hpp>

class Player final  {
    private:
        sf::RenderWindow *win;
        sf::Sprite sprite;
    public:
        sf::Texture texture;
        int hp, xp, velocity;
        bool left, right, top, bottom;
        Player(sf::RenderWindow *w = nullptr);
        ~Player();
        void upgradePlayer();
        sf::Sprite getPlayer();
        void reInit(sf::RenderWindow *w);
        void followMouse();
        void move(float x, float y);
};
