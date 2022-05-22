#include <stdio.h>
#include "KeySpace2.h"


void printTable(KeySpace2 *table) {
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
    KeySpace2 *table;
    getKS2(&table, 5);
    insertIntoKS2(table, getMockItem("1.1", "2.1", "data1"));
    insertIntoKS2(table, getMockItem("1.2", "2.2", "data2"));
    insertIntoKS2(table, getMockItem("1.3", "2.3", "data3"));
    insertIntoKS2(table, getMockItem("1.2", "2.4", "data4"));
    insertIntoKS2(table, getMockItem("1.2", "2.5", "data5"));
    insertIntoKS2(table, getMockItem("1.3", "2.1", "data6"));
    insertIntoKS2(table, getMockItem("1.4", "2.7", "data7"));
    insertIntoKS2(table, getMockItem("1.5", "2.2", "data8"));
    insertIntoKS2(table, getMockItem("1.6", "2.9", "data9"));
    insertIntoKS2(table, getMockItem("1.7", "2.1", "data10"));
    printTable(table);
    removeByKeyKS2(table, getMockKey("2.1"));
    removeByKeyKS2(table, getMockKey("2.3"));
    printTable(table);
    insertIntoKS2(table, getMockItem("1.1", "2.1", "data11"));
    insertIntoKS2(table, getMockItem("1.2", "2.2", "data12"));
    insertIntoKS2(table, getMockItem("1.3", "2.11", "data13"));
    printTable(table);
    insertIntoKS2(table, getMockItem("1.1", "2.10", "data14"));
    insertIntoKS2(table, getMockItem("1.2", "2.4", "data15"));
    insertIntoKS2(table, getMockItem("1.3", "2.7", "data16"));
    insertIntoKS2(table, getMockItem("1.1", "2.8", "data17"));
    insertIntoKS2(table, getMockItem("1.2", "2.9", "data18"));
    insertIntoKS2(table, getMockItem("1.3", "2.0", "data19"));
    printTable(table);
    destroyKS2(table);
    return 0;
}
