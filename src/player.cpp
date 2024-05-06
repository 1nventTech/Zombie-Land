#include "player.h"
#include <cstdio>
#include <iostream>
#include <cmath>

Player::Player(sf::RenderWindow *w) {
    if (!w || w == NULL || w == nullptr) {
        this -> body = nullptr;
    } else {
        float width = w->getSize().x / 10;
        float height = w->getSize().y / 10;
        this -> sprite.setPosition(w->getSize().x / 2 - width /2, w->getSize().y / 2 - height / 2);    // pozycja
        this -> texture.loadFromFile("../assets/player-placeholder.png");
        this -> sprite.setTexture(this->texture);
        this -> sprite.setScale(5,5);
        this -> sprite.setOrigin(this->texture.getSize().x / 2, this->texture.getSize().y / 2);
    }
    this -> win = w;
    left = false, right = false, top = false, bottom = false;
    this -> velocity = 500;
}

Player::~Player() {
    std::cout << "Player\t\tdestructor called...\n";
    delete this -> body;
    delete this -> win;
}

sf::Sprite Player::getPlayer() {
    return this->sprite;
}
void Player::reInit(sf::RenderWindow *w) {
    std::cout << "re-initializing: ";
    this->~Player();
    new(this) Player(w);
}
void Player::upgradePlayer() {

}
void Player::followMouse() {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*win);

    sf::Vector2f mouseWorldPosition = win->mapPixelToCoords(mousePosition);

    float angle = std::atan2(mouseWorldPosition.y - sprite.getPosition().y,
                             mouseWorldPosition.x - sprite.getPosition().x);

    // Convert angle from radians to degrees
    float angleDegrees = angle * 180.0f / M_PI;
    if (mousePosition.x <= sprite.getGlobalBounds().getPosition().x + sprite.getGlobalBounds().getSize().x / 2){
        this->sprite.setScale(5,-5);
    }else{
        this->sprite.setScale(5,5);
    }
    // Rotate the body
    this-> sprite.setRotation(angleDegrees) ;
}

void Player::move(float x, float y) {
    this -> sprite.move(x, y);
}
