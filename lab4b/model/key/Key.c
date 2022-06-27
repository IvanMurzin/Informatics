#include "Key.h"

Key getKey(unsigned int x, unsigned int y) {
    Key result = {x, y};
    return result;
}

Key getHalf(Key key) {
    Key result = {key.x / 2 + key.x % 2, key.y / 2 + key.y % 2};
    return result;
}

int outOfBorder(Key start, Key end, Key key) {
    if (start.x <= key.x && start.y <= key.y) {
        if (end.x >= key.x && end.y >= key.y) {
            return 0;
        }
    }
    return 1;
}

int getDirection(Key start, Key end, Key key) {
    Key border = getBorder(start, end);
    if (key.x <= border.x && key.y <= border.y) return 0;
    if (key.x >= border.x && key.y <= border.y) return 1;
    if (key.x <= border.x && key.y >= border.y) return 2;
    if (key.x >= border.x && key.y >= border.y) return 3;
    return -1;
}

Key getNewStartBorder(Key start, Key end, int direction) {
    Key result;
    switch (direction) {
        case 0:
            result = start;
            break;
        case 1:
            result.x = (start.x + end.x) / 2 + 1;
            result.y = start.y;
            break;
        case 2:
            result.x = start.x;
            result.y = (start.y + end.y) / 2 + 1;
            break;
        case 3:
            result.x = (start.x + end.x) / 2 + 1;
            result.y = (start.y + end.y) / 2 + 1;
            break;
    }
    return result;
}

Key getNewEndBorder(Key start, Key end, int direction) {
    Key result;
    switch (direction) {
        case 0:
            result.x = (start.x + end.x) / 2;
            result.y = (start.y + end.y) / 2;
            break;
        case 1:
            result.x = end.x;
            result.y = (start.y + end.y) / 2;
            break;
        case 2:
            result.x = (start.x + end.x) / 2;
            result.y = end.y;
            break;
        case 3:
            result = end;
            break;
    }
    return result;
}

int equalsKey(Key first, Key second) {
    return first.x == second.x && first.y == second.y;
}

int greaterKey(Key src, Key key) {
    return src.x < key.x || src.y < key.y;
}

int gte(Key left, Key right) {
    if (left.x < right.x) return 0;
    if (left.x == right.x && left.y < right.y) return 0;
    return 1;
}

Key getBorder(Key start, Key end) {
    Key result = {(start.x + end.x) / 2, (start.y + end.y) / 2};
    return result;
}
