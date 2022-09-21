#pragma once

class  Item {
private:
    int x;
    int y;
    int data;

public:
    Item(int x, int y, int data);

    int getX() const;

    int getY() const;

    int getData() const;

    bool isPalindrome() const;

    Item &operator=(Item &&other) {
        this->x = other.x;
        this->y = other.y;
        this->data = other.data;
        other.x = 0;
        other.y = 0;
        other.data = 0;
        return *this;
    }

    Item(Item &&other) {
        this->x = other.x;
        this->y = other.y;
        this->data = other.data;
        other.x = 0;
        other.y = 0;
        other.data = 0;
    }

    Item(const Item &other) {
        this->x = other.x;
        this->y = other.y;
        this->data = other.data;
    }
};