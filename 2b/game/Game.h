#ifndef GAME_H
#define GAME_H

typedef struct Game {
    void (*start)();
} Game;

Game *getGame();

#endif
