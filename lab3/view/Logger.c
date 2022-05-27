#include <stddef.h>
#include <stdio.h>
#include "Logger.h"
#include "Errors.h"
#include "Iterator.h"

// ║ BUSY ║ v   ║ (%s  |  %s|V ) ║ ↓/↑ INDEX ║ VALUE    ║%c
void printHat(int type, const char separator) {
    printf("╔══════╦═════╦═════ KEY SPACE %d ══════════════╗%c", type, separator);
}

void printSeparator(const char separator) {
    printf("╠══════╬═════╬════════════════════╬═══════════╣%c", separator);
}


void printEmptyLine(const char separator) {
    printf("║ ?    ║ v?  ║ (????  |  ????|V?) ║ ????      ║%c", separator);
}

void printFooter(const char separator) {
    printf("╚══════╩═════╩════════════════════╩═══════════╝%c", separator);
}

void printHeader(int type, const char separator) {
    const char *firstKey = type == 1 ? "KEY1" : "KEY2";
    const char *secondKey = type == 1 ? "KEY2" : "KEY1";
    printf("║ BUSY ║ v   ║ (%s  |  %s|V ) ║ VALUE     ║%c", firstKey, secondKey, separator);
}

void printRowKS2(Container container, const char separator) {
    Node *node = container.node;
    Item *item = node->item;
    printf("║ %-4d ║ v%-2d ║ (%-6s|%6s|V%d) ║ %-9s ║%c", container.busy, node->version, item->key.key2.value, item->key.key1.value, item->version, item->data, separator);
    while (hasNextNode(node)) {
        node = nextNode(node);
        item = node->item;
        printf("\n║      ║     ║                    ║           ║ ");
        printf("║ %-4d ║ v%-2d ║ (%-6s|%6s|V%d) ║ %-9s ║%c", container.busy, node->version, item->key.key2.value, item->key.key1.value, item->version, item->data, separator);
    }
}

void printRowKS1(Container container, const char separator) {
    Node *node = container.node;
    Item *item = node->item;
    printf("║ %-4d ║ v%-2d ║ (%-6s|%6s|V%d) ║ %-9s ║%c", container.busy, node->version, item->key.key1.value, item->key.key2.value, item->version, item->data, separator);
    while (hasNextNode(node)) {
        node = nextNode(node);
        item = node->item;
        printf("║      ║     ║                    ║           ║\n");
        printf("║ %-4d ║ v%-2d ║ (%-6s|%6s|V%d) ║ %-9s ║%c", container.busy, node->version, item->key.key1.value, item->key.key2.value, item->version, item->data, separator);
    }
}

int printKS1(KeySpace1 *table, int busyOnly) {  //  ╚ ╔ ╩ ╦ ╠ ═ ╬ ╣ ║ ╗ ╝
    if (table == NULL || table->containers == NULL) throw ERROR_INCORRECT_INPUT;
    printHat(1, '\n');
    printHeader(1, '\n');
    for (int i = 0; i < table->size; ++i) {
        Container container = table->containers[i];
        if (container.busy == 1 || !busyOnly) {
            printSeparator('\n');
            printRowKS1(container, '\n');
        }
    }
    printFooter('\n');
    return 0;
}

int printKS2(KeySpace2 *table, int busyOnly) {
    if (table == NULL || table->containers == NULL) throw ERROR_INCORRECT_INPUT;
    printHat(2, '\n');
    printHeader(2, '\n');
    for (int i = 0; i < table->maxSize; ++i) {
        Container container = table->containers[i];
        if (container.node == NULL) {
            printSeparator('\n');
            printEmptyLine('\n');
        } else if (container.busy == 1 || !busyOnly) {
            printSeparator('\n');
            printRowKS2(container, '\n');
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
        Container container1 = table->keySpace1->containers[i];
        Container container2 = table->keySpace2->containers[i];
        printSeparator(' ');
        printSeparator('\n');
        if (container1.node == NULL) printEmptyLine(' ');
        else printRowKS1(container1, ' ');
        if (container2.node == NULL)printEmptyLine(' ');
        else printRowKS2(container2, ' ');
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

//void printItem(Item *item) {
//    printf("╔══════╦═══════════ Item ══════════════╗\n");
//    printf("║ BUSY ║ (KEY1  |  KEY2|V ) ║ VALUE    ║\n");
//    printf("╠══════╬════════════════════╬══════════╣\n");
//    printf("║ %-4d ║ (%-6s|%6s|V%d) ║ %-8s ║\n",
//           item->busy,
//           item->key.key1.value,
//           item->key.key2.value,
//           item->key.version,
//           item->data);
//    printf("╚══════╩════════════════════╩══════════╝\n");
//
//}
