#include "player.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>

// Player::Player(sf::RenderWindow *w) {
//     this -> max_hp = 100;
//     if (!(!w || w == NULL || w == nullptr)) {
//         this -> texture.loadFromFile("../assets/player-placeholder.png");
//         this -> sprite.setTexture(this->texture);
//         this -> sprite.setScale(5,5);
//         this -> sprite.setOrigin(this->texture.getSize().x / 2, this->texture.getSize().y / 2);

//         float width = this->sprite.getGlobalBounds().getSize().x;
//         float height = this->sprite.getGlobalBounds().getSize().y;

//         this -> sprite.setPosition(1680 , 1050 );    // pozycja
//     }
    
//     this -> win = w;
//     left = false, right = false, top = false, bottom = false;
//     this -> velocity = 500;
//     this -> hp = max_hp;
// }

Player::Player(sf::RenderWindow* w) {
    this->max_hp = 100;
    this->hp = max_hp;
    this->xp = 50; // Initialize xp or other member variables

    if (w) {
        // this->texture.loadFromFile("../assets/player-placeholder.png");
        // this->sprite.setTexture(this->texture);
        // this->sprite.setScale(5, 5);
        // this->sprite.setOrigin(this->texture.getSize().x / 2, this->texture.getSize().y / 2);
        // this->sprite.setPosition(1680, 1050); // Position of the player
    }
    this -> sprite.setPosition(1680 , 1050);
    this->update_pos(this->sprite.getPosition().x, this->sprite.getPosition().y);

    left = false, right = false, top = false, bottom = false;
    this->win = w;
    this->velocity = 500;
}

Player::~Player() {
    std::cout << "Player\t\tdestructor called...\n";
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
        this -> sprite.setScale(5,-5);
    }else{
        this -> sprite.setScale(5,5);
    }
    // Rotate the body
    this-> sprite.setRotation(angleDegrees) ;
}

void Player::move(float x, float y) {
    this -> sprite.move(x, y);
    this->update_pos(sprite.getPosition().x, sprite.getPosition().y);
}

sf::Text & Player::player_info(sf::Font &f, sf::RenderWindow *w) {
    // system("clear");
    // int x = sprite.getPosition().x;
    // int y = sprite.getPosition().y;
    // std::cout << "Xp: " << this->xp << '\n';
    // std::cout << "Hp: " << this->hp << '\n';
    // std::cout << "x: " << x << " y: " << y << std::endl;
    info.setFont(f);
    info.setCharacterSize(52);
    info.setFillColor(sf::Color::Red);
    info.setString("Hp: " + std::to_string(this->hp) + '\n' + "Xp: " + std::to_string(this->xp) + '\n');
    sf::Vector2f player_pos = sprite.getPosition();
    info.setPosition(player_pos.x - (w->getSize().x / 2), player_pos.y - (w->getSize().y / 2) - 10);
    return info;
}

sf::Text & Player::pos_info(sf::Font &f, sf::RenderWindow *w) {
    p_info.setFont(f);
    p_info.setCharacterSize(48);
    p_info.setFillColor(sf::Color::Black);
    p_info.setString("X: " + std::to_string(this->x) + '\n' + "Y: " + std::to_string(this->y) + '\n');
    sf::Vector2f player_pos = sprite.getPosition();
    p_info.setPosition(player_pos.x - (w->getSize().x / 2), player_pos.y + (w->getSize().y / 3) - 10);
    return p_info;
}