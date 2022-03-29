#include "../../model/game/Game.h"
typedef struct GameController {
    void (*start)();
} GameController;

GameController *getGameController();
