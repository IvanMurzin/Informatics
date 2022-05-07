#include <stddef.h>
#include <stdio.h>
#include "Logger.h"
#include "Errors.h"
#include "IteratorKS.h"

void printRow(const Item *item, int previousIndex, int nextIndex) {
    printf("╠══════╬══════════════════════════════════════╬══════════════════════╣\n");
    printf("║ %-4d ║ %-9s v%-5d %-3d/ %-14d ║ %-20s ║\n",
           item->busy,
           item->key.value,
           item->key.version,
           nextIndex,
           previousIndex,
           item->data);
}

void printRowKS1(const Item *item) {
    printRow(item, item->previousIndexKS1, item->nextIndexKS1);
}

void printRowKS2(const Item *item) {
    printRow(item, item->previousIndexKS2, item->nextIndexKS2);
}

void printHeader() {
    printf("║ BUSY ║ KEY       V      NEXT/PREVIOUS INDEX ║ VALUE                ║\n");
}

void printEmptyLine() {
    printf("╠══════╬══════════════════════════════════════╬══════════════════════╣\n");
    printf("║ NULL ║ NULL      NULL   NULL/NULL     NULL  ║ NULL                 ║\n");
}

void printFooter() {
    printf("╚══════╩══════════════════════════════════════╩══════════════════════╝\n");

}

int printKS1(KeySpace1 *table, int busyOnly) {  //  ╚ ╔ ╩ ╦ ╠ ═ ╬ ╣ ║ ╗ ╝
    if (table == NULL || table->table == NULL) throw ERROR_INCORRECT_INPUT;
    printf("╔══════╦═══════════════════ KEY SPACE 1 ═════════════════════════════╗\n");
    printHeader();
    for (int i = 0; i < table->currentSize; ++i) {
        Item *item = table->table[i];
        if (item->busy || !busyOnly) printRowKS1(item);
    }
    printFooter();
    return 0;
}

int printKS2(KeySpace2 *table, int busyOnly) {
    if (table == NULL || table->table == NULL) throw ERROR_INCORRECT_INPUT;
    printf("╔══════╦═══════════════════ KEY SPACE 2 ═════════════════════════════╗\n");
    printHeader();
    for (int i = 0; i < table->maxSize; ++i) {
        Item *item = table->table[i];
        if (item == NULL) printEmptyLine();
        else if (item->busy || !busyOnly) printRowKS2(item);
    }
    printFooter();
    return 0;
}

int printSelectResultKS1(KeySpace1 *table, const Item *item) {
    if (item == NULL || item->key.value == NULL || item->data == NULL) throw ERROR_INCORRECT_INPUT;
    printf("╔══════╦══════════════════ SELECT RESULT ════════════════════════════╗\n");
    printHeader();
    do {
        printRowKS1(item);
        item = nextItem1(table, item);
    } while ((hasNextItem1(item)));
    printRowKS1(item);
    printFooter();
    return 0;
}

int printSelectResultKS2(KeySpace2 *table, const Item *item) {
    if (item == NULL || item->key.value == NULL || item->data == NULL) throw ERROR_INCORRECT_INPUT;
    printf("╔══════╦══════════════════ SELECT RESULT ════════════════════════════╗\n");
    printHeader();
    do {
        printRowKS2(item);
        item = nextItem2(table, item);
    } while ((hasNextItem2(item)));
    printRowKS2(item);
    printFooter();
    return 0;
}