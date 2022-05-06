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
    Item *item = NULL;
    int result = selectFirstVersionItemKS1(table, stringKey, &item);
    if (!result) printSelectResultKS1(table, item);
    return result;
}

int deleteAllKS1(KeySpace1 *table, const char *stringKey) {
    int result = removeByKeyValueKS1(table, stringKey);
    if (!result) printKS1(table, 0);
    return result;
}


int deleteByRangeKS1(KeySpace1 *table, const char *floor, const char *selling) {
    Key floorKey = {floor, 0};
    Key sellingKey = {selling, 0};
    int result = removeByKeyRange(table, floorKey, sellingKey);
    if (!result) printKS1(table, 0);
    return result;
}



