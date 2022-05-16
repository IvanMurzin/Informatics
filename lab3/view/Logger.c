#include <stddef.h>
#include <stdio.h>
#include "Logger.h"
#include "Errors.h"

void printHat(int type, const char separator) {
    printf("╔══════╦═══════════════ KEY SPACE %d ════════════════════╗%c", type, separator);
}

void printSeparator(const char separator) {
    printf("╠══════╬═════════════════════════╬═══════════╬══════════╣%c", separator);
}


void printEmptyLine(const char separator) {
    printf("║ ?    ║ ???                 ?   ║   ? / ?   ║ ????     ║%c", separator);
}

void printFooter(const char separator) {
    printf("╚══════╩═════════════════════════╩═══════════╩══════════╝%c", separator);
}

void printHeader(int type, const char separator) {
    const char *firstKey = type == 1 ? "KEY1" : "KEY2";
    const char *secondKey = type == 1 ? "KEY2" : "KEY1";
    printf("║ BUSY ║ (%s  |  %s|V ) v    ║ ↓/↑ INDEX ║ VALUE    ║%c", firstKey, secondKey, separator);
}

void printRow(const Item *item, int keyType, int previousIndex, int nextIndex, const char separator) {
    printf("║ %-4d ║ (%-6s|%6s|V%d) v%-3d ║ %3d / %-3d ║ %-8s ║%c",
           item->busy,
           (keyType == 1) ? (item->key.key1.value) : (item->key.key2.value),
           (keyType == 1) ? (item->key.key2.value) : (item->key.key1.value),
           item->key.version,
           (keyType == 1) ? (item->key.key1.version) : (item->key.key2.version),
           nextIndex,
           previousIndex,
           item->data,
           separator);
}

void printRowKS1(const Item *item, const char separator) {
    printRow(item, 1, item->waymarkKS1.previous, item->waymarkKS1.next, separator);
}

void printRowKS2(const Item *item, const char separator) {
    printRow(item, 2, item->waymarkKS2.previous, item->waymarkKS2.next, separator);
}

int printKS1(KeySpace1 *table, int busyOnly) {  //  ╚ ╔ ╩ ╦ ╠ ═ ╬ ╣ ║ ╗ ╝
    if (table == NULL || table->table == NULL) throw ERROR_INCORRECT_INPUT;
    printHat(1, '\n');
    printHeader(1, '\n');
    for (int i = 0; i < table->currentSize; ++i) {
        Item *item = table->table[i];
        if (item->busy || !busyOnly) {
            printSeparator('\n');
            printRowKS1(item, '\n');
        }
    }
    printFooter('\n');
    return 0;
}

int printKS2(KeySpace2 *table, int busyOnly) {
    if (table == NULL || table->table == NULL) throw ERROR_INCORRECT_INPUT;
    printHat(2, '\n');
    printHeader(2, '\n');
    for (int i = 0; i < table->maxSize; ++i) {
        Item *item = table->table[i];
        if (item == NULL) {
            printSeparator('\n');
            printEmptyLine('\n');
        } else if (item->busy || !busyOnly) {
            printSeparator('\n');
            printRowKS2(item, '\n');
        }
    }
    printFooter('\n');
    return 0;
}

int printTable(Table *table) {
    if (table == NULL || table->keySpace1 == NULL || table->keySpace2 == NULL) throw ERROR_INCORRECT_INPUT;
    printHat(1, ' ');
    printHat(2, '\n');
    printHeader(1, ' ');
    printHeader(2, '\n');
    for (int i = 0; i < table->maxSize; ++i) {
        Item *item1 = table->keySpace1->table[i];
        Item *item2 = table->keySpace2->table[i];
        printSeparator(' ');
        printSeparator('\n');
        if (item1 == NULL)printEmptyLine(' ');
        else printRowKS1(item1, ' ');
        if (item2 == NULL)printEmptyLine(' ');
        else printRowKS2(item2, ' ');
        printf("\n");
    }
    printFooter(' ');
    printFooter('\n');
    return 0;
}

void handleResult(int result) {
    switch (result) {
        case ERROR_INCORRECT_INPUT:
            puts("Incorrect input");
            break;
        case ERROR_UNABLE_TO_CREATE_ITEM:
            puts("Unable to create item");
            break;
        case ERROR_TABLE_OVERFLOW:
            puts("Table overflow");
            break;
        case ERROR_NOT_FOUND:
            puts("Element not found");
            break;
        case 0:
            puts("Ok");
            break;
        default:
            printf("Unhandled exception: N%d\n", result);
    }
}

void printItem(Item *item) {
    printf("╔══════╦═══════════ Item ══════════════╗\n");
    printf("║ BUSY ║ (KEY1  |  KEY2|V ) ║ VALUE    ║\n");
    printf("╠══════╬════════════════════╬══════════╣\n");
    printf("║ %-4d ║ (%-6s|%6s|V%d) ║ %-8s ║\n",
           item->busy,
           item->key.key1.value,
           item->key.key2.value,
           item->key.version,
           item->data);
    printf("╚══════╩════════════════════╩══════════╝\n");

}
