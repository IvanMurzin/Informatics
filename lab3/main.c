#include <stdio.h>
#include "Dialog.h"


int main() {
    const char *messages[] = {"0. Quit", "1. Add", "2. Find", "3. Find by key1", "4. Find by key2", "5. Delete", "6. Delete by key1", "7. Delete by key2", "8. Delete by range key1", "9. Show", "10. Mock data", "11. Collect garbage"};
    const int messageSize = sizeof(messages) / sizeof(messages[0]);
    int (*functions[])(Table *) = {NULL, D_Add, D_Find, D_FindByKey1, D_FindByKey2, D_Delete, D_DeleteByKey1, D_DeleteByKey2, D_DeleteByRangeKey1, D_Show, D_Mock, D_CollectGarbage};
    Table *table;
    getTable(&table, 3);
    int actionIndex;
    while ((actionIndex = dialog(messages, messageSize))) {
        if (!functions[actionIndex](table)) break;
    }
    printf("That's all. Bye!\n");
    destroyTable(table);
    return 0;
}
// сделать наглядную сборку мусора
// и не автоматическую
