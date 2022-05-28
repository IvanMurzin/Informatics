#include <stdlib.h>
#include "Dialog.h"
#include "readline/readline.h"
#include "Iterator.h"

int getInt(int *a) {
    int n;
    do {
        n = scanf("%d", a);
        if (n < 0) return 0;
        if (n == 0) {
            printf("%s\n", "Error! Repeat input");
            scanf("%*[^\n]");
        }
    } while (n == 0);
    return 1;
}

CompositeKey readCompositeKey() {
    char *key1 = NULL;
    char *key2 = NULL;
    int n;
    do {
        n = 0;
        puts("Enter first key: -->");
        key1 = readline("");
        if (*key1 == '\0') {
            puts("Incorrect input");
            free(key1);
            n = 1;
            continue;
        }
        puts("Enter second key: -->");
        key2 = readline("");
        if (*key2 == '\0') {
            puts("Incorrect input");
            free(key1);
            free(key2);
            n = 1;
            continue;
        }
    } while (n);
    return getCompositeKey(key1, key2);
}

int dialog(const char *messages[], int messageSize) {
    char *errorMessage = "";
    int actionIndex;
    int n;
    do {
        puts(errorMessage);
        errorMessage = "You are wrong. Repeat, please!";
        for (int i = 0; i < messageSize; ++i) {
            puts(messages[i]);
        }
        puts("Make your choice --> ");
        n = getInt(&actionIndex);
        if (n == 0) actionIndex = 0;
    } while (actionIndex < 0 || actionIndex >= messageSize);
    return actionIndex;
}

int D_Add(Table *table) {
    char *info = NULL;
    CompositeKey key = readCompositeKey();
    puts("Enter info:");
    info = readline("");
    if (*info == '\0') {
        puts("Incorrect input");
        free(info);
        free((char *) key.key1.value);
        free((char *) key.key2.value);
        return 1;
    }
    Item *item = NULL;
    if (getItem(&item, key, info)) return 0;
    int putResult = put(table, item);
    if (putResult) destroyItem(item);
    handleResult(putResult);
    return 1;
}

int D_Find(Table *table) {
    CompositeKey key = readCompositeKey();
    Item *item;
    int findResult = find(table, key, &item);
    handleResult(findResult);
    if (!findResult) printItems(item);
    free((char *) key.key1.value);
    free((char *) key.key2.value);
    return 1;
}

void destroyItems(Item *item) {
    Item *tmp;
    while (hasNext(item)) {
        tmp = item;
        item = next(item);
        destroyItem(tmp);
    }
    destroyItem(item);
}

int D_FindByKey1(Table *table) {
    char *key1 = NULL;
    puts("Enter first key: -->");
    key1 = readline("");
    Item *item;
    int findResult = findByKey1(table, getKey(key1), &item);
    handleResult(findResult);
    if (!findResult) {
        printItems(item);
        destroyItems(item);
    }
    free(key1);
    return 1;
}

int D_FindByKey2(Table *table) {
    char *key2 = NULL;
    puts("Enter second key: -->");
    key2 = readline("");
    Item *item;
    int findResult = findByKey2(table, getKey(key2), &item);
    handleResult(findResult);
    if (!findResult) {
        printItems(item);
        destroyItems(item);
    }
    free(key2);
    return 1;
}


int D_Delete(Table *table) {
    CompositeKey key = readCompositeKey();
    int deleteResult = deleteAll(table, key);
    handleResult(deleteResult);
    destroyKey(key.key1);
    destroyKey(key.key2);
    return 1;
}


int D_DeleteByKey1(Table *table) {
    char *key1 = NULL;
    puts("Enter first key: -->");
    key1 = readline("");
    int deleteResult = deleteByKey1(table, getKey(key1));
    handleResult(deleteResult);
    free(key1);
    return 1;
}


int D_DeleteByKey2(Table *table) {
    char *key2 = NULL;
    puts("Enter second key: -->");
    key2 = readline("");
    int deleteResult = deleteByKey2(table, getKey(key2));
    handleResult(deleteResult);
    free(key2);
    return 1;
}


int D_DeleteByRangeKey1(Table *table) {
    char *floor = NULL;
    char *selling = NULL;
    puts("Enter floor key1: -->");
    floor = readline("");
    puts("Enter selling key1: -->");
    selling = readline("");
    int deleteResult = deleteByRangeKey1(table, getKey(floor), getKey(selling));
    handleResult(deleteResult);
    free(floor);
    free(selling);
    return 1;
}


int D_Show(Table *table) {
    printTable(table);
    return 1;
}

int D_Mock(Table *table) {
    Item *item = getMockItem("1.1", "2.1", "data1");
    if (put(table, item)) destroyItem(item);
    item = getMockItem("1.2", "2.2", "data2");
    if (put(table, item)) destroyItem(item);
    item = getMockItem("1.3", "2.2", "data3");
    if (put(table, item)) destroyItem(item);
    item = getMockItem("1.1", "2.3", "data4");
    if (put(table, item)) destroyItem(item);
    item = getMockItem("1.4", "2.4", "data5");
    if (put(table, item)) destroyItem(item);
    item = getMockItem("1.1", "2.1", "data6");
    if (put(table, item)) destroyItem(item);
    item = getMockItem("1.2", "2.1", "data7");
    if (put(table, item)) destroyItem(item);
    return 1;
}