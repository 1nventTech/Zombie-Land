// character.cpp
#include "character.h"

Character::Character(const std::string& textureFile) {
    if (!texture.loadFromFile(textureFile)) {
        exit(EXIT_FAILURE);
    }
    sprite.setTexture(texture);
    // sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    sprite.setScale(5, 5);
    this->sprite.setOrigin(this->texture.getSize().x / 2, this->texture.getSize().y / 2);
    this->sprite.setPosition(1680, 1050); // Position of the player
    velocity = 50;
    // hp = 100;
}

void Character::setPosition(float x, float y) {
    sprite.setPosition(x, y);
    this->update_pos(x, y);
}

void Character::move(float dx, float dy) {
    sprite.move(dx, dy);
    this->update_pos(sprite.getPosition().x, sprite.getPosition().y);
}

void Character::render(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::Vector2f Character::getPosition() const {
    return sprite.getPosition();
}

sf::Sprite& Character::getSprite() {
    return sprite;
}

int Character::getHp() const {
    return hp;
}

void Character::takeDamage(int amount) {
    this -> hp -= amount;
}

void Character::update_pos(int x, int y) {
    this->x = x;
    this->y = y;
}