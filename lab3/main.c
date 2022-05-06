#include <stdio.h>
#include "KeySpace1Controller.h"

int main() {
    KeySpace1 *table = NULL;
    getKeySpase1(&table, 10);
    putToKS1(table, "key1", "data1");
    putToKS1(table, "key2", "data2");
    putToKS1(table, "key3", "data3");
    putToKS1(table, "key4", "data4");
    putToKS1(table, "key4", "data5");
    putToKS1(table, "key4", "data6");
    putToKS1(table, "key2", "data7");
    putToKS1(table, "key1", "data8");
    putToKS1(table, "key4", "data9");

    selectFromKS1(table, "key4");
    selectFromKS1(table, "key1");
    selectFromKS1(table, "key4");
    return 0;
}
