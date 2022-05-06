#include <stdio.h>
#include "KeySpace1Controller.h"
#include "Logger.h"

int main() {
    KeySpace1 *table = NULL;
    getKeySpase1(&table, 5);
    putToKS1(table, "key1", "data1");
    putToKS1(table, "key2", "data2");
    putToKS1(table, "key3", "data3");
    putToKS1(table, "key2", "data4");
    putToKS1(table, "key2", "data5");
    putToKS1(table, "key1", "data6");
    putToKS1(table, "key2", "data7");
    putToKS1(table, "key2", "data8");
    deleteAllKS1(table, "key2");
    putToKS1(table, "key3", "data6");
    putToKS1(table, "key3", "data7");
    putToKS1(table, "key4", "data8");

    return 0;
}
