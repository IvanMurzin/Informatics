#pragma once
#define SIZE 1000

class Item {
private:
    int key = 0;
    char data[SIZE] = "";

public:
    Item() = default;

    explicit Item(int key);

    Item(int key, const char *data);

    int getKey() const;

    const char *getData() const;

};