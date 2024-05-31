#pragma once

#include "axis.h"
#include <SFML/Graphics.hpp>

class Character : public Axis {
    protected:
        sf::Sprite sprite;
        int velocity;
        int hp;
        int max_hp;
        bool isAlive;
        float damage_amount;

    public:
        sf::Texture texture;
        Character(const std::string& textureFile = "../assets/player-placeholder.png");
        virtual ~Character() = default;
        const bool get_alive();
        void setPosition(float x, float y);
        virtual void move(float dx, float dy);
        virtual void render(sf::RenderWindow& window);
        sf::FloatRect getGlobalBounds() const {
            return this->sprite.getGlobalBounds();
        }
        sf::Vector2f getPosition() const;
        sf::Sprite& getSprite();
        int getVelocity() const {
            return velocity;
        }
        void update_pos(int x, int y);
        int getHp() const;
        void takeDamage(int amount);
        void check_alive();
};
