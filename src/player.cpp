#include "player.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>

Player::Player(sf::RenderWindow *w) {
    if (!(!w || w == NULL || w == nullptr)) {
        this -> texture.loadFromFile("../assets/player-placeholder.png");
        this -> sprite.setTexture(this->texture);
        this -> sprite.setScale(5,5);
        this -> sprite.setOrigin(this->texture.getSize().x / 2, this->texture.getSize().y / 2);

        float width = this->sprite.getGlobalBounds().getSize().x;
        float height = this->sprite.getGlobalBounds().getSize().y;

        this -> sprite.setPosition(0 , 0 );    // pozycja
    }
    this -> win = w;
    left = false, right = false, top = false, bottom = false;
    this -> velocity = 500;
}

Player::~Player() {
    std::cout << "Player\t\tdestructor called...\n";
    delete this -> win;
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
    if (mouseWorldPosition.x <= sprite.getPosition().x + sprite.getTexture()->getSize().x / 2){
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
