#pragma once

#include "Item.h"
#include "Resource.h"
#include <iostream>

class Table {
private:
    int capacity;
    int size = 0;
    Item *data = nullptr;

//    int indexOf(int key) const;

    void resize();

    class Iterator {
    private:
        int current = 0;
        Item *data;

    public:
        Iterator(Item *data, int current);

        Item &operator*() const;

        Item *operator->() const;

        Iterator &operator++();

        Iterator operator++(int);

        bool operator!=(const Iterator &right) const;

    };

public:
    Table();

    Table(const Table &other);

    Table(Table &&other);

    explicit Table(int capacity);

    explicit Table(Item *items, int size);

    ~Table();

    int getSize() const;

    Iterator begin() const;

    Iterator end() const;

    Table &operator=(const Table &other);

    Table &operator=(Table &&other);

    friend std::ostream &operator<<(std::ostream &os, const Table &table);

    bool add(const Item &item);

    bool update(const Item &item);

    bool remove(int key);

    int getCapacity() const;

    Resource<Item> operator[](int key) const;

    Resource<Item> getItem(int key) const;

    bool isDataNull() const;
};
