#include "Item.h"

Item::Item(int x, int y, int data) : x(x), y(y), data(data) {}

int Item::getX() const {
    return x;
}

int Item::getY() const {
    return y;
}

int Item::getData() const {
    return data;
}

bool Item::isPalindrome() const {
    int dataCopy = data;
    int digit;
    int revert = 0;
    do {
        digit = dataCopy % 10;
        revert = (revert * 10) + digit;
        dataCopy = dataCopy / 10;
    } while (dataCopy != 0);
    return data == revert;
}
