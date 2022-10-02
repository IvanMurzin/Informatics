#include <cstring>
#include "Item.h"


Item::Item(int key) : key(key) {}

Item::Item(int key, const char *data) : key(key) {
    strcpy(this->data, data);
}

int Item::getKey() const {
    return key;
}

const char *Item::getData() const {
    return data;
}

