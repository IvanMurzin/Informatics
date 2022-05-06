#include <stddef.h>
#include <stdio.h>
#include "Logger.h"
#include "Errors.h"
#include "IteratorKS1.h"

void printRowKS1(const Item1 *item) {
    printf("╠══════╬══════════════════════════════════════╬══════════════════════╣\n");
    printf("║ %-4d ║ %-9s v%-5d %-3d/ %-14d ║ %-20s ║\n",
           item->busy,
           item->key.value,
           item->key.version,
           item->nextIndex,
           item->previousIndex,
           item->data);
}

void printHeaderKS1() {
    printf("║ BUSY ║ KEY1      V      NEXT/PREVIOUS INDEX ║ VALUE                ║\n");
}

void printFooter() {
    printf("╚══════╩══════════════════════════════════════╩══════════════════════╝\n");

}

int printKS1(KeySpace1 *table, int busyOnly) {  //  ╚ ╔ ╩ ╦ ╠ ═ ╬ ╣ ║ ╗ ╝
    if (table == NULL || table->table == NULL) throw ERROR_INCORRECT_INPUT;
    printf("╔══════╦═══════════════════ KEY SPACE 1 ═════════════════════════════╗\n");
    printHeaderKS1();
    for (int i = 0; i < table->currentSize; ++i) {
        Item1 *item = table->table[i];
        if (item->busy || !busyOnly) printRowKS1(item);
    }
    printFooter();
    return 0;
}


int printSelectResultKS1(KeySpace1 *table, const Item1 *item) {
    if (item == NULL || item->key.value == NULL || item->data == NULL) throw ERROR_INCORRECT_INPUT;
    printf("╔══════╦══════════════════ SELECT RESULT ════════════════════════════╗\n");
    printHeaderKS1();
    do {
        printRowKS1(item);
        item = nextItem1(table, item);
    } while ((hasNextItem1(item)));
    printRowKS1(item);
    printFooter();
    return 0;
}