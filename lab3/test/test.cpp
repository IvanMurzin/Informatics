#define CATCH_CONFIG_MAIN

#include "catch.h"
#include "Table.h"
//*
TEST_CASE("test item constructors", "[item]") {
    SECTION("default constructor") {
        Item item = Item();
        CHECK(item.getKey() == 0);
        CHECK(strcmp(item.getData(), "") == 0);
    }SECTION("only key constructor") {
        Item item = Item(123);
        CHECK(item.getKey() == 123);
        CHECK(strcmp(item.getData(), "") == 0);
    }SECTION("constructor") {
        Item item = Item(123, "test");
        CHECK(item.getKey() == 123);
        CHECK(strcmp(item.getData(), "test") == 0);
    }
}

TEST_CASE("test table constructors", "[table]") {
    SECTION("default constructor") {
        Table table = Table();
        CHECK(table.getSize() == 0);
        CHECK(table.getCapacity() == 10);
    }SECTION("constructor with capacity") {
        Table table = Table(120);
        CHECK(table.getSize() == 0);
        CHECK(table.getCapacity() == 120);
    }SECTION("constructor with items") {
        Item items[] = {Item(), Item(123), Item(1), Item(312, "test")};
        Table table = Table(items, 4);
        CHECK(table.getSize() == 4);
        CHECK(table.getCapacity() == 10);
    }SECTION("constructor with items more than default capacity") {
        Item items[] = {Item(0), Item(1), Item(2), Item(3), Item(4), Item(5), Item(6), Item(7), Item(8), Item(9), Item(10), Item(11)};
        Table table = Table(items, 12);
        CHECK(table.getSize() == 12);
        CHECK(table.getCapacity() == 12);
    }SECTION("move constructor") {
        Item items[] = {Item(0), Item(1), Item(2), Item(3), Item(4), Item(5), Item(6), Item(7), Item(8), Item(9), Item(10), Item(11)};
        Table table = Table(items, 12);
        Table newTable = Table(items, 12);
        table = std::move(newTable);
        CHECK(table.getSize() == 12);
        CHECK(table.getCapacity() == 12);
        CHECK(!table.isDataNull());
        CHECK(newTable.getSize() == 0);
        CHECK(newTable.getCapacity() == 0);
        CHECK(newTable.isDataNull());
    }SECTION("copy constructor") {
        Item items[] = {Item(0), Item(1), Item(2), Item(3), Item(0), Item(5), Item(6), Item(15), Item(8), Item(9), Item(9), Item(10), Item(11)};
        Table table = Table(items, 12);
        Table newTable = Table(items, 12);
        table = newTable;
        CHECK(newTable.getSize() == 10);
        CHECK(newTable.getSize() == table.getSize());
        CHECK(newTable.getCapacity() == 12);
        CHECK(newTable.getCapacity() == table.getCapacity());
        CHECK(!newTable.isDataNull());
        CHECK(!table.isDataNull());
    }
}

TEST_CASE("operations", "[table]") {
    Table table = Table();
    table.add(Item(1));
    table.add(Item(2));
    table.add(Item(12));
    table.add(Item(3));
    table.add(Item(9));
    table.add(Item(6));
    table.add(Item(4));
    table.add(Item(5));
    table.add(Item(7));
    table.add(Item(8));
    table.add(Item(10));
    table.add(Item(11));
    std::cout << table << std::endl;
    SECTION("add start") {
        CHECK(table.add(Item(-1)));
        CHECK(!table.add(Item(-1)));
        CHECK(table.getSize() == 13);
        CHECK(table.getItem(12).hasData());
        CHECK(table.getItem(12).getData().getKey() == 12);
        CHECK(!table.getItem(123).hasData());
    }SECTION("iterator") {
        int size = 0;
        int keySum = 0;
        for (const auto &item: table) {
            ++size;
            keySum += item.getKey();
        }
        CHECK(size == 12);
        CHECK(keySum == 78);
    }SECTION("update") {
        CHECK(!table.update(Item(13)));
        CHECK(table.update(Item(12, "test")));
        CHECK(table.getSize() == 12);
        CHECK(!table.getItem(13).hasData());
        CHECK(table.getItem(12).hasData());
        CHECK(strcmp(table.getItem(12).getData().getData(), "test") == 0);
    }SECTION("update") {
        CHECK(!table.update(Item(13)));
        CHECK(table.update(Item(12, "test")));
        CHECK(table.getSize() == 12);
        CHECK(!table[13].hasData());
        CHECK(table[12].hasData());
        CHECK(strcmp(table[12].getData().getData(), "test") == 0);
    }SECTION("remove") {
        table.add(Item(110));
        CHECK(!table.remove(13));
        CHECK(table.remove(12));
        CHECK(!table.remove(12));
        CHECK(table.getSize() == 12);
        CHECK(!table[13].hasData());
        CHECK(!table[12].hasData());
    }
}