#pragma once

#include <SFML/Graphics.hpp>
#include "character.h"

class Player final : public Character {
    private:
        sf::RenderWindow *win;
        int max_hp;
        sf::Text info;
        sf::Text p_info;
        int xp;

    public:
        bool left, right, top, bottom;
            
        Player(sf::RenderWindow *w = nullptr);
        ~Player();
            
        // Functions
        void upgradePlayer();
        inline sf::Sprite getPlayer(){
            return sprite;
        }
        void reInit(sf::RenderWindow *w);
        void followMouse();
        void move(float x, float y);
        sf::Text & player_info(sf::Font &f, sf::RenderWindow *w = nullptr);
        sf::Text & pos_info(sf::Font &f, sf::RenderWindow *w = nullptr);
};
