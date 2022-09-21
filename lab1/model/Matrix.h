#pragma once

#include <iostream>
#include "List.h"
#include "Item.h"
#include "Line.h"

class Matrix {
private:
    int m = 0;
    int n = 0;
    List<Line> data;

public:
    const List<Line> &getData() const;

    Matrix() = default;

    Matrix(int n, int m);

    int getM() const;

    int getN() const;

    void addItem(Item &&item);

    void addItem(const Item &item);

    void makePalindrome(const Matrix &matrix);

};