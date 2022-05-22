#include <stdio.h>
#include "KeySpace2.h"
#include "KeySpace1.h"


void printTable1(KeySpace1 *table) {
    for (int i = 0; i < 5; ++i) {
        Node *node = table->containers[i].node;
        printf("busy: %d, NULL: %d   ", table->containers[i].busy, node == NULL);
        while (node != NULL) {
            printf("node.data: %s  ", node->item->data);
            node = node->next;
        }
        printf("\n");
    }
    printf("\n");
}
void printTable2(KeySpace2 *table) {
    for (int i = 0; i < 5; ++i) {
        Node *node = table->containers[i].node;
        printf("busy: %d, NULL: %d   ", table->containers[i].busy, node == NULL);
        while (node != NULL) {
            printf("node.data: %s  ", node->item->data);
            node = node->next;
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
//    const char *messages[] = {"0. Quit", "1. Add", "2. Find", "3. Find by key1", "4. Find by key2", "5. Delete","6. Delete by key1","7. Delete by key2", "8. Show", "9. Mock data"};
//    const int messageSize = sizeof(messages) / sizeof(messages[0]);
//    int (*functions[])(Table *) = {NULL, D_Add, D_Find, D_FindByKey1, D_FindByKey2, D_Delete,D_DeleteByKey1,D_DeleteByKey2, D_Show, D_Mock};
//    Table *table;
//    getTable(&table, 10);
//    int actionIndex;
//    while ((actionIndex = dialog(messages, messageSize))) {
//        if (!functions[actionIndex](table)) break;
//    }
//    printf("That's all. Bye!\n");
//    destroyTable(table);
    KeySpace1 *table1;
    KeySpace2 *table2;
    getKS1(&table1, 5);
    getKS2(&table2, 5);
    insertIntoKS1(table1, getMockItem("1.1", "2.1", "data1"));
    insertIntoKS1(table1, getMockItem("1.2", "2.2", "data2"));
    insertIntoKS2(table2, getMockItem("1.1", "2.1", "data1"));
    insertIntoKS2(table2, getMockItem("1.2", "2.2", "data2"));
    printTable1(table1);
    printTable2(table2);
    removeByKeyKS1(table1, getMockKey("1.1"));
    printTable1(table1);
    printTable2(table2);
    return 0;
}
