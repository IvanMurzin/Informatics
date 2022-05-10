#include "Logger.h"
#include "Table.h"

int main() {
    Table *table;
    getTable(&table, 10);
    put(table, getSimpleCompositeKey("key1.1", "key2.1"), "data1");
    put(table, getSimpleCompositeKey("key1.1", "key2.2"), "data2");
    put(table, getSimpleCompositeKey("key1.2", "key2.3"), "data3");
    put(table, getSimpleCompositeKey("key1.2", "key2.3"), "data4");
    printTable(table);
    return 0;
}
