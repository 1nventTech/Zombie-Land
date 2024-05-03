#include "./hearders/LOOP.h"

int main(void) {
    LOOP game;
    while (game.running()) {
        game.update();
        game.listen();
        game.render();
    }

    return ((int)!true);
}
