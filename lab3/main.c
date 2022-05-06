#include <stdio.h>
#include "KeySpaceController.h"
#include "Logger.h"

int main() {
    KeySpace2 *table = NULL;
    getKS2(&table, 10);
    putToKS2(table, "key1", "data1");
    putToKS2(table, "key2", "data2");
    putToKS2(table, "key3", "data3");
    putToKS2(table, "key4", "data4");
    putToKS2(table, "key5", "data5");
    putToKS2(table, "key1", "data6");
    putToKS2(table, "key2", "data7");
    putToKS2(table, "key4", "data8");
    putToKS2(table, "key3", "data9");
    putToKS2(table, "key5", "data10");
    deleteAllKS2(table, "key3");
    putToKS2(table, "key1", "data1");
    putToKS2(table, "key2", "data2");
    putToKS2(table, "key3", "data3");
    putToKS2(table, "key4", "data4");
    putToKS2(table, "key5", "data5");
    putToKS2(table, "key1", "data6");
    putToKS2(table, "key2", "data7");
    putToKS2(table, "key4", "data8");
    putToKS2(table, "key3", "data9");
    putToKS2(table, "key5", "data10");
    destroyKS2(table);
    return 0;
}
