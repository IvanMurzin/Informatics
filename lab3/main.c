#include <stdio.h>
#include "Dialog.h"


int main() {
    const char *messages[] = {"0. Quit", "1. Add", "2. Find", "3. Find by key1", "4. Find by key2", "5. Delete",/*"6. Delete by key1","7. Delete by key2",*/ "6. Show", "7. Mock data"};
    const int messageSize = sizeof(messages) / sizeof(messages[0]);
    int (*functions[])(Table *) = {NULL, D_Add, D_Find, D_FindByKey1, D_FindByKey2, D_Delete,/*D_DeleteByKey1,D_DeleteByKey2,*/ D_Show, D_Mock};
    Table *table;
    getTable(&table, 3);
    int actionIndex;
    while ((actionIndex = dialog(messages, messageSize))) {
        if (!functions[actionIndex](table)) break;
    }
    printf("That's all. Bye!\n");
//    D_Mock(table);
//    D_Show(table);
//    CompositeKey k = getKeyCopy(getCompositeKey("1.3", "2.2"));
//    deleteAll(table, k);
//    destroyKey(k.key1);
//    destroyKey(k.key2);
//    D_Show(table);
//     k = getKeyCopy(getCompositeKey("1.2", "2.2"));
//    deleteAll(table, k);
//    destroyKey(k.key1);
//    destroyKey(k.key2);
//    D_Show(table);
//     k = getKeyCopy(getCompositeKey("1.2", "2.2"));
//    deleteAll(table, k);
//    destroyKey(k.key1);
//    destroyKey(k.key2);
//    D_Show(table);
    destroyTable(table);
    return 0;
}
