#include <stdio.h>
#include "KeySpace1.h"


void printTable(KeySpace1 *table) {
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
    KeySpace1 *table;
    getKS1(&table, 5);
    insertIntoKS1(table, getMockItem("1.1", "2.1", "data1"));
    insertIntoKS1(table, getMockItem("1.2", "2.1", "data2"));
    insertIntoKS1(table, getMockItem("1.3", "2.1", "data3"));
    insertIntoKS1(table, getMockItem("1.2", "2.1", "data4"));
    insertIntoKS1(table, getMockItem("1.2", "2.1", "data5"));
    insertIntoKS1(table, getMockItem("1.3", "2.1", "data6"));
    insertIntoKS1(table, getMockItem("1.4", "2.1", "data7"));
    insertIntoKS1(table, getMockItem("1.5", "2.1", "data8"));
    insertIntoKS1(table, getMockItem("1.6", "2.1", "data9"));
    insertIntoKS1(table, getMockItem("1.7", "2.1", "data10"));
    printTable(table);
    removeByKeyRange(table, getMockKey("1.2"), getMockKey("1.4"));
    printTable(table);
    insertIntoKS1(table, getMockItem("1.1", "2.1", "data11"));
    insertIntoKS1(table, getMockItem("1.2", "2.1", "data12"));
    insertIntoKS1(table, getMockItem("1.3", "2.1", "data13"));
    printTable(table);
    insertIntoKS1(table, getMockItem("1.1", "2.1", "data14"));
    insertIntoKS1(table, getMockItem("1.2", "2.1", "data15"));
    insertIntoKS1(table, getMockItem("1.3", "2.1", "data16"));
    insertIntoKS1(table, getMockItem("1.1", "2.1", "data17"));
    insertIntoKS1(table, getMockItem("1.2", "2.1", "data18"));
    insertIntoKS1(table, getMockItem("1.3", "2.1", "data19"));
    printTable(table);
    destroyKS1(table);
    return 0;
}
