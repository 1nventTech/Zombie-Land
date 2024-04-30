#include "Game.h"

int main(void) {
    Game gg;
    while (gg.running()) {
        gg.update();
        gg.listen();
        gg.render();
    }

    return ((int)!true);
}
