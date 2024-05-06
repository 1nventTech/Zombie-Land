#include "enemy.h"
#include <cstdio>
#include <iostream>
#include <string>

Enemy::Enemy(sf::RenderWindow *w, float x, float y, std::string txt){
    if (!(!w || w == NULL || w == nullptr)) {
        this -> texture.loadFromFile(txt);
        this -> sprite.setTexture(this->texture);
        this -> sprite.setScale(5,5);
        this -> sprite.setOrigin(this->texture.getSize().x / 2, this->texture.getSize().y / 2);

        float width = this->sprite.getGlobalBounds().getSize().x;
        float height = this->sprite.getGlobalBounds().getSize().y;

        this -> sprite.setPosition(x / 2 - width / 2, y / 2 - height / 2);    // pozycja
    }
    this -> win = w;
    left = false, right = false, top = false, bottom = false;
    this -> velocity = 500;
}

Enemy::~Enemy() {
    std::cout << "Enemy\t\tdestructor called...\n";
    delete this -> win;
}

sf::Sprite Enemy::getEnemy() {
    return this->sprite;
}
void Enemy::reInit(sf::RenderWindow *w) {
    std::cout << "re-initializing: ";
    this->~Enemy();
    new(this) Enemy(w);
}
void Enemy::followPlayer() {

}

void Enemy::move(float x, float y) {
    this -> sprite.move(x, y);
}
