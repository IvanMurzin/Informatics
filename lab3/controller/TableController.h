#pragma once

#include "Table.h"
#include "Scanner.h"

class TableController {
private:
    Table table;
    Scanner in = Scanner(std::cin);

    Item readItem() const;

public:
    TableController();

    void addItem();

    void printTable();

    void findItem() const;

    void updateItem();

    void removeItem();

    void selectWhereMore() const;

};