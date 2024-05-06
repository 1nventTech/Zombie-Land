#include "game.h"
#include "SFML/System/Clock.hpp"
#include <sys/types.h>

int main(void) {
    sf::Clock clock;
    Game gg;
    while (gg.running()) {
        gg.update();
        gg.listen();
        gg.render();
        gg.dt = clock.restart();
    }

    return ((int)!true);
}
