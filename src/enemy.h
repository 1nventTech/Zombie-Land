#pragma once

#include "character.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>

class Enemy final : public Character {
    private:
        Character * target;
        float speed;
        bool canAttack;
        std::chrono::steady_clock::time_point lastAttackTime;
        // float damage_amount;
    public:
        bool xp_taken;
        // sf::FloatRect getGlobalBounds() const {
        //     return this->sprite.getGlobalBounds();
        // }
        Enemy();
        ~Enemy() override;
        void set_target(Character & player);
        void follow();
        void damage();
        void update();
        void check_collision();
        void resetAttackCooldown();
};