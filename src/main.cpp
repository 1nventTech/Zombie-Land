#include "Game.h"

int main(void) {
    Game gg;
    // sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);
    while (gg.running()) {
        gg.update();
        gg.render();
    }

    return ((int)!true);
}
