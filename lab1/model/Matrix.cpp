#include "Matrix.h"
#include "random"

int Matrix::getM() const {
    return m;
}

int Matrix::getN() const {
    return n;
}

void Matrix::addItem(Item &&item) {
    List<Line>::Iterator iterator = data.begin();
    while (iterator != data.end() && (*iterator).getIndex() < item.getY()) {
        ++iterator;
    }
    if (iterator != data.end() && (*iterator).getIndex() == item.getY()) {
        const auto &items = (*iterator).getItems();
        List<Item>::Iterator itemIterator = items.begin();
        while (itemIterator != items.end() && (*itemIterator).getX() < item.getX()) {
            ++itemIterator;
        }
        if (itemIterator != items.end() && (*itemIterator).getX() == item.getX()) return;
        itemIterator.add(std::move(item));
        return;
    }
    iterator.add(Line(std::move(item)));
}

void Matrix::addItem(const Item &item) {
    List<Line>::Iterator iterator = data.begin();
    while (iterator != data.end() && (*iterator).getIndex() < item.getY()) {
        ++iterator;
    }
    if (iterator != data.end() && (*iterator).getIndex() == item.getY()) {
        const auto &items = (*iterator).getItems();
        List<Item>::Iterator itemIterator = items.begin();
        while (itemIterator != items.end() && (*itemIterator).getX() < item.getX()) {
            ++itemIterator;
        }
        if (itemIterator != items.end() && (*itemIterator).getX() == item.getX()) return;
        itemIterator.add(item);
        return;
    }
    iterator.add(Line(item));
}

Matrix::Matrix(int n, int m) : n(n), m(m) {}

const List<Line> &Matrix::getData() const {
    return data;
}

void Matrix::makePalindrome(const Matrix &matrix) {
    n = matrix.getN();
    m = matrix.getM();
    data = List<Line>();
    for (const auto &line: matrix.getData()) {
        for (const auto &item: line.getItems()) {
            if (item.isPalindrome()) addItem(item);
        }
    }
}

