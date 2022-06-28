#include <stdlib.h>
#include <time.h>
#include "Dialog.h"
#include "test/test.h"

void timing() {
    srand(time(NULL));
    for (int size = 100; size < 10000; size += 100) {
        int time = 0;
        for (int i = 0; i < 100; ++i) {
            Tree *tree = getTree(getKey(1000000, 1000000), 10);
            for (int j = 0; j < size; ++j) add(tree, getKey(rand() % 1000, rand() % 1000), malloc(10));
            time += insertQ(tree);
        }
        printf(",%d\n", time / 100);
    }
}

void mainDialog() {
    const char *messages[] = {"0. Quit", "1. Add", "2. Find", "3. Find min", "4. Delete by number", "5. Delete", "6. Draw", "7. Draw Reverse", "8. Mock data"};
    const int messageSize = sizeof(messages) / sizeof(messages[0]);
    int (*functions[])(Tree *) = {NULL, D_Add, D_Find, D_FindMin, D_DeleteByNumber, D_Delete, D_Draw, D_DrawReverse, D_Mock};
    Tree *tree = getTree(getKey(7, 7), 3);
    int actionIndex;
    while ((actionIndex = dialog(messages, messageSize))) {
        if (!functions[actionIndex](tree)) break;
        else if (actionIndex != 7) D_Draw(tree);
    }
    puts("That's all. Bye!\n");
    destroyQTree(tree);
}

int main() {
    mainDialog();
//    timing();
    return 0;
}
