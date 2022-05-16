#include <stdlib.h>
#include "Dialog.h"
#include "readline/readline.h"

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
    return getSimpleCompositeKey(key1, key2);
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
        free(key.key1.value);
        free(key.key2.value);
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
    if (!findResult) printItem(item);
    free(key.key1.value);
    free(key.key2.value);
    return 1;
}

int D_FindByKey1(Table *table) {
    char *key1 = NULL;
    puts("Enter first key: -->");
    key1 = readline("");
    KeySpace1 *keySpace1;
    int findResult = findByKey1(table, getSimpleKey(key1), &keySpace1);
    handleResult(findResult);
    if (!findResult) {
        printKS1(keySpace1, 0);
        destroyKS1(keySpace1);
    }
    free(key1);
    return 1;
}

int D_FindByKey2(Table *table) {
    char *key2 = NULL;
    puts("Enter second key: -->");
    key2 = readline("");
    KeySpace2 *keySpace2;
    int findResult = findByKey2(table, getSimpleKey(key2), &keySpace2);
    handleResult(findResult);
    if (!findResult) {
        printKS2(keySpace2, 0);
        destroyKS2(keySpace2);
    }
    free(key2);
    return 1;
}


int D_Delete(Table *table) {
    CompositeKey key = readCompositeKey();
    int deleteResult = deleteAll(table, key);
    handleResult(deleteResult);
    free(key.key1.value);
    free(key.key2.value);
    return 1;
}


int D_DeleteByKey1(Table *table) {
    char *key1 = NULL;
    puts("Enter first key: -->");
    key1 = readline("");
    int deleteResult = deleteByKey1(table, getSimpleKey(key1));
    handleResult(deleteResult);
    free(key1);
    return 1;
}


int D_DeleteByKey2(Table *table) {
    char *key2 = NULL;
    puts("Enter second key: -->");
    key2 = readline("");
    int deleteResult = deleteByKey2(table, getSimpleKey(key2));
    handleResult(deleteResult);
    free(key2);
    return 1;
}

int D_Show(Table *table) {
    printTable(table);
    return 1;
}

int D_Mock(Table *table) {
    Item *item = getMockItem("1.1", "2.1", "data1");
    puts("1");
    if (put(table, item)) destroyItem(item);
    item = getMockItem("1.2", "2.2", "data2");
    puts("2");
    if (put(table, item)) destroyItem(item);
    item = getMockItem("1.3", "2.2", "data3");
    puts("3");
    if (put(table, item)) destroyItem(item);
    item = getMockItem("1.1", "2.3", "data4");
    puts("4");
    printTable(table);
    if (put(table, item)) destroyItem(item);
    item = getMockItem("1.4", "2.4", "data5");
    printTable(table);
    puts("5");
    if (put(table, item)) destroyItem(item);
    printTable(table);
    item = getMockItem("1.1", "2.1", "data6");
    puts("6");
    if (put(table, item)) destroyItem(item);
    item = getMockItem("1.2", "2.1", "data7");
    puts("7");
    if (put(table, item)) destroyItem(item);
    puts("9");
    return 1;
}