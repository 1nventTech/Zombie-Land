#include "enemy.h"
#include <iostream>
#include <cmath>

Enemy::Enemy() : Character("../assets/zombie.png"), canAttack(true) {
    this->velocity = std::abs(velocity);
    this->target = nullptr;
    this->speed = 0.4f;
    this->damage_amount = 10;
}

void Enemy::update() {
    if (target) {
        follow();
        check_collision();
    }
}

void Enemy::set_target(Character& player) {
    target = &player;
}

void Enemy::follow() {
    sf::Vector2f enemyPos = this->getPosition();
    sf::Vector2f targetPos = target->getPosition();

    sf::Vector2f direction = targetPos - enemyPos;

    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0) {
        direction.x /= length;
        direction.y /= length;
    }

    this->move(direction.x * speed, direction.y * speed);
}

void Enemy::damage() {
    if (canAttack) {
        target->takeDamage(this->damage_amount);
        lastAttackTime = std::chrono::steady_clock::now();
        canAttack = false;
    }
}

void Enemy::resetAttackCooldown() {
    auto currentTime = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - lastAttackTime).count();
    if (elapsedTime >= 2) {
        canAttack = true;
    }
}

Enemy::~Enemy() {
    std::cout << "Enemy\t\tdestructor called...\n";
}

void Enemy::check_collision() {
    sf::FloatRect enemyBounds = this->getGlobalBounds();
    sf::FloatRect playerBounds = target->getGlobalBounds();

    if (enemyBounds.intersects(playerBounds)) {
        damage();
    }
}
