#pragma once

#include <SFML/Graphics.hpp>

class Player final  {
    private:
        sf::RenderWindow *win;
        sf::Sprite sprite;
        int max_hp;
        sf::Text info;

    public:
        sf::Texture texture;
        int hp, xp, velocity;
        bool left, right, top, bottom;
        
        Player(sf::RenderWindow *w = nullptr);
        ~Player();
        
        // functions
        void upgradePlayer();
        inline sf::Sprite getPlayer(){
            return sprite;
        }
        void reInit(sf::RenderWindow *w);
        void followMouse();
        void move(float x, float y);
        sf::Text & player_info(sf::Font &f, sf::RenderWindow *w = nullptr);
};
