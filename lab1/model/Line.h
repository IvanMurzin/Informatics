#pragma once

#include "List.h"
#include "Item.h"

class Line {
private:
    int index;
    List<Item> items;
public:
    explicit Line(int index);

    explicit Line() = default;

    explicit Line(Item &&item);

    explicit Line(const Item &item);

    explicit Line(Line &&other);

    void add(Item &&item);

    int getIndex() const;

    const List<Item> &getItems() const;

};