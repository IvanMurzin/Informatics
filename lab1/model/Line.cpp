#include "Line.h"

Line::Line(int index) : index(index) {}

Line::Line(Item &&item) : index(item.getY()) {
    items.add(std::move(item));
}

Line::Line(const Item &item) : index(item.getY()) {
    items.add(item);
}

void Line::add(Item &&item) {
    items.add(std::move(item));
}

int Line::getIndex() const {
    return index;
}

Line::Line(Line &&other) {
    this->index = other.index;
    this->items = std::move(other.items);
    other.index = 0;
}

const List<Item> &Line::getItems() const {
    return items;
}

