// character.cpp
#include "character.h"

Character::Character(const std::string& textureFile) {
    if (!texture.loadFromFile(textureFile)) {
        exit(EXIT_FAILURE);
    }
    sprite.setTexture(texture);
    // sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    sprite.setScale(0.3, 0.3);
    this->sprite.setOrigin(this->texture.getSize().x / 2, this->texture.getSize().y / 2);
    this->sprite.setPosition(2020, 1100); // Position of the player
    velocity = 50;
    hp = 40;
    isAlive = true;
}

const bool Character::get_alive() {
    this->damage_amount = 0;
    return this->isAlive;
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
    check_alive();
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

void Character::check_alive() {
    if (this->hp <= 0) {
        isAlive = false;
        this->hp = 0;
        this -> ~Character();
    }
}