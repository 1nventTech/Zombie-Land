#include "main_ch.h"
#include <iostream>
#include <cmath>

main_ch::main_ch(sf::RenderWindow *w) {
    if (!w || w == NULL || w == nullptr) {
        this -> body = nullptr;
    } else {
        int width = w->getSize().x / 10;
        int height = w->getSize().y / 10;
        this -> body = new sf::RectangleShape(sf::Vector2f(width, height));
        this->body->setOrigin(this -> body -> getSize().x / 2, this-> body -> getSize().y / 2);     // ustawienie punktu odniesienia
        this->body->setPosition(w->getSize().x / 2 - width /2, w->getSize().y / 2 - height / 2);    // pozycja
    }
    this -> win = w;
    left = false, right = false, top = false, bottom = false;
}

main_ch::~main_ch() {
    std::cout << "main_ch destructor called...\n";
    delete this -> body;
    delete this -> win;
}

sf::RectangleShape main_ch::get_main_ch() {
    return *this -> body;
}
void main_ch::re_init(sf::RenderWindow *w) {
    std::cout << "re-initializing: ";
    this->~main_ch();
    new(this) main_ch(w);
}
void main_ch::upgrade_ch() {

}
void main_ch::follow_mouse() {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*win);

    sf::Vector2f mouseWorldPosition = win->mapPixelToCoords(mousePosition);

    float angle = std::atan2(mouseWorldPosition.y - body->getPosition().y,
                             mouseWorldPosition.x - body->getPosition().x);

    // Convert angle from radians to degrees
    float angleDegrees = angle * 180.0f / M_PI;

    // Rotate the body
    this-> body->setRotation(angleDegrees) ;
}

void main_ch::move(int x, int y) {
    this -> body -> move(x, y);
}
