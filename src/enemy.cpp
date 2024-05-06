#include "enemy.h"
#include "SFML/Graphics/CircleShape.hpp"
#include <iostream>

Enemy::Enemy(sf::RenderWindow *w) {
    if (!w || w == NULL || w == nullptr) {
        this -> body = nullptr;
    } else {
        float width = w->getSize().x / 10;
        float height = w->getSize().y / 10;
        this -> body = new sf::CircleShape(width);
        this->body->setOrigin(this -> body -> getRadius() / 2, this-> body -> getRadius() / 2);     // ustawienie punktu odniesienia
        this->body->setPosition(w->getSize().x / 2 - width / 2, w->getSize().y / 2 - height / 2);    // pozycja
    }
    this -> win = w;
    left = false, right = false, top = false, bottom = false;
    this -> velocity = 500;
}

Enemy::~Enemy() {
    std::cout << "Enemy\t\tdestructor called...\n";
    delete this -> body;
    delete this -> win;
}

sf::CircleShape Enemy::getEnemy() {
    return *this -> body;
}
void Enemy::reInit(sf::RenderWindow *w) {
    std::cout << "re-initializing: ";
    this->~Enemy();
    new(this) Enemy(w);
}
void Enemy::followPlayer() {

}

void Enemy::move(float x, float y) {
    this -> body -> move(x, y);
}
