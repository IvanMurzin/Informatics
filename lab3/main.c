#include <stdio.h>
#include "KeySpace1Controller.h"
#include "Logger.h"

int main() {
    KeySpace1 *table = NULL;
    getKeySpase1(&table, 10);
    putToKS1(table, "key1", "data1");
    putToKS1(table, "key2", "data2");
    putToKS1(table, "key3", "data3");
    putToKS1(table, "key2", "data4");
    putToKS1(table, "key2", "data5");
    putToKS1(table, "key1", "data6");
    putToKS1(table, "key2", "data7");
    putToKS1(table, "key2", "data8");
    selectFromKS1(table, "key2");
    Key1 k = {"key2", 2};
    removeByKeyKS1(table, k);
    selectFromKS1(table, "key2");
    k.version = 0;
    removeByKeyKS1(table, k);
    selectFromKS1(table, "key2");
    printKS1(table, 1);
    printKS1(table, 0);
    return 0;
}
