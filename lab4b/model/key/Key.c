#include "Key.h"

Key getKey(unsigned int x, unsigned int y) {
    Key result = {x, y};
    return result;
}

Key getHalf(Key key) {
    Key result = {key.x / 2, key.y / 2};
    return result;
}

int getDirection(Key border, Key key) {
    if (key.x < border.x && key.y < border.y) return 0;
    if (key.x > border.x && key.y > border.y) return 1;
    if (key.x > border.x && key.y < border.y) return 2;
    if (key.x < border.x && key.y < border.y) return 3;
    return -1;
}

int equalsKey(Key first, Key second) {
    return first.x == second.x && first.y == second.y;
}
