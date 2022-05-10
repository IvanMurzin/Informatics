#include <stddef.h>
#include <stdio.h>
#include "Logger.h"
#include "Errors.h"
#include "IteratorKS.h"


void printSeparator(const char separator) {
    printf("╠══════╬═══════════════╬═══════════╬══════════════════════╣%c", separator);
}

void printRow(const Item *item, Key key, int previousIndex, int nextIndex, const char separator) {
    printf("║ %-4d ║ %-8s v%-3d ║ %3d / %-3d ║ %-20s ║%c",
           item->busy,
           key.value,
           key.version,
           nextIndex,
           previousIndex,
           item->data,
           separator);
}

void printRowKS1(const Item *item, const char separator) {
    printRow(item, item->key1, item->previousIndexKS1, item->nextIndexKS1, separator);
}

void printRowKS2(const Item *item, const char separator) {
    printRow(item, item->key2, item->previousIndexKS2, item->nextIndexKS2, separator);
}

void printHeader(const char separator) {
    printf("║ BUSY ║ KEY       V   ║ ↓/↑ INDEX ║ VALUE                ║%c", separator);
}

void printEmptyLine(const char separator) {
    printf("║ ?    ║ ???       ?   ║   ? / ?   ║ ????                 ║%c", separator);
}

void printFooter(const char separator) {
    printf("╚══════╩═══════════════╩═══════════╩══════════════════════╝%c", separator);

}

int printKS1(KeySpace1 *table, int busyOnly) {  //  ╚ ╔ ╩ ╦ ╠ ═ ╬ ╣ ║ ╗ ╝
    if (table == NULL || table->table == NULL) throw ERROR_INCORRECT_INPUT;
    printf("╔══════╦═══════════════ KEY SPACE 1 ══════════════════════╗\n");
    printHeader('\n');
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
    printf("╔══════╦═══════════════ KEY SPACE 2 ══════════════════════╗\n");
    printHeader('\n');
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

//int printSelectResultKS1(KeySpace1 *table, const Item *item) {
//    if (item == NULL || item->key1.value == NULL || item->data == NULL) throw ERROR_INCORRECT_INPUT;
//    printf("╔══════╦══════════════════ SELECT RESULT ════════════════════════════╗\n");
//    printHeader('\n');
//    do {
//        printRowKS1(item, '\n');
//        item = nextItem1(table, item);
//    } while ((hasNextItem1(item)));
//    printRowKS1(item, '\n');
//    printFooter('\n');
//    return 0;
//}
//
//int printSelectResultKS2(KeySpace2 *table, const Item *item) {
//    if (item == NULL || item->key2.value == NULL || item->data == NULL) throw ERROR_INCORRECT_INPUT;
//    printf("╔══════╦══════════════════ SELECT RESULT ════════════════════════════╗\n");
//    printHeader('\n');
//    do {
//        printRowKS2(item, '\n');
//        item = nextItem2(table, item);
//    } while ((hasNextItem2(item)));
//    printRowKS2(item, '\n');
//    printFooter('\n');
//    return 0;
//}

int printTable(Table *table) {
    if (table == NULL || table->keySpace1 == NULL || table->keySpace2 == NULL) throw ERROR_INCORRECT_INPUT;
    printf("╔══════╦═══════════════ KEY SPACE 1 ══════════════════════╗ ╔══════╦═══════════════ KEY SPACE 2 ══════════════════════╗\n");
    printHeader(' ');
    printHeader('\n');
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
