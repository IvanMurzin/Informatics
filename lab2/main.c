#include <stdlib.h>
#include "Game.h"
#include "Stack.h"

int main() {
    Game *game = getGame();
    game->start();
    free(game);
    return 0;
}
