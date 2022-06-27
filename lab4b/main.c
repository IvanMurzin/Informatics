#include <stdlib.h>
#include <time.h>
#include "Dialog.h"
#include "test/test.h"

int main() {
    Tree *tree = getTree(getKey(7, 7), 8);
    add(tree, getKey(1, 2), "kek");
    add(tree, getKey(1, 1), "kek");
    add(tree, getKey(2, 3), "kek");
    add(tree, getKey(2, 1), "kek");
    add(tree, getKey(1, 5), "kek");
    add(tree, getKey(1, 1), "kek");
    add(tree, getKey(1, 3), "kek");
    add(tree, getKey(1, 1), "kek");
    add(tree, getKey(1, 1), "kek");
    add(tree, getKey(5, 5), "kek");
    add(tree, getKey(1, 5), "kek");
    add(tree, getKey(5, 1), "kek");
    add(tree, getKey(4, 4), "kek");
    add(tree, getKey(4, 5), "kek");
    add(tree, getKey(5, 5), "kek");
    add(tree, getKey(5, 5), "kek");
    add(tree, getKey(5, 5), "kek");
    add(tree, getKey(5, 5), "kek");
    add(tree, getKey(5, 5), "kek");
    add(tree, getKey(5, 5), "kek");
    add(tree, getKey(4, 4), "kek");
    add(tree, getKey(4, 4), "kek");
    add(tree, getKey(4, 4), "kek");
    add(tree, getKey(4, 5), "kek");
    add(tree, getKey(5, 4), "kek");
    add(tree, getKey(5, 5), "kek");
    add(tree, getKey(1, 2), "kek");
    add(tree, getKey(1, 1), "kek");
    add(tree, getKey(1, 2), "kek");
    add(tree, getKey(1, 3), "kek");
    add(tree, getKey(2, 3), "kek");
    add(tree, getKey(3, 3), "kek");
    add(tree, getKey(1, 1), "kek");
    add(tree, getKey(0, 0), "kek");
    add(tree, getKey(0, 0), "kek");
    add(tree, getKey(1, 0), "kek");
    createPngGraph(tree);
    destroyQTree(tree);
//    const char *messages[] = {"0. Quit", "1. Add", "2. Find", "3. Delete", "4. Show", "5. Mock data", "6. Get tree from file"};
//    const int messageSize = sizeof(messages) / sizeof(messages[0]);
//    int (*functions[])(BinaryTree *) = {NULL, D_AddBT, D_FindBT, D_DeleteBT, D_ShowBT, D_MockBT};
//    BinaryTree *tree = getBinaryTree();
//    int actionIndex;
//    while ((actionIndex = dialog(messages, messageSize))) {
//        if (actionIndex == 6) {
//            if (!D_GetFromFile(&tree)) break;
//        } else if (!functions[actionIndex](tree)) break;
//    }
//    puts("That's all. Bye!\n");
//    destroyBinaryTreeDeep(tree);
//    srand(time(NULL));
//
//    for (int size = 1000; size < 100000; size += 1000) {
//        int time = 0;
//        for (int i = 0; i < 100; ++i) {
//            BinaryTree *tree = getBinaryTree();
//            for (int j = 0; j < size; ++j) addBT(tree, rand(), "data");
//            time += find(tree);
//        }
//        printf(",%d\n", time / 100);
//    }
    return 0;
}
