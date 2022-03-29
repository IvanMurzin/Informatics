#include <stdlib.h>
#include "GameController.h"

Game *game;

void startGame() {
    start(game);
}

GameController *getGameController() {
    GameController *gameController = malloc(sizeof(GameController));
    gameController->start = &startGame;
    game = getGame();
    return gameController;
}
