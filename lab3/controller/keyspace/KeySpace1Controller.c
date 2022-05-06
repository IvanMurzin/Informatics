#include <stddef.h>
#include "KeySpace1Controller.h"
#include "Logger.h"
#include "Errors.h"

int putToKS1(KeySpace1 *table, const char *stringKey, const char *stringData) {
    int result = insertIntoKS1(table, stringKey, stringData);
    if (!result) printKS1(table, 0);
    return result;
}

int selectFromKS1(KeySpace1 *table, const char *stringKey) {
    Item1 *item1 = NULL;
    int result = selectFirstVersionItemKS1(table, stringKey, &item1);
    if (!result) printSelectResultKS1(table, item1);
    return result;
}

int deleteAllKS1(KeySpace1 *table, const char *stringKey) {
    int result = removeByKeyValueKS1(table, stringKey);
    if (!result) printKS1(table, 0);
    return result;
}


int deleteByRangeKS1(KeySpace1 *table, const char *floor, const char *selling) {
    Key1 floorKey = {floor, 0};
    Key1 sellingKey = {selling, 0};
    int result = removeByKeyRange(table, floorKey, sellingKey);
    if (!result) printKS1(table, 0);
    return result;
}



