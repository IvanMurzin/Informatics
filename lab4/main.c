#include "Dialog.h"
#include "test/test.h"

int main() {
//    const char *messages[] = {"0. Quit", "1. Add", "2. Find", "3. Delete", "4. Show", "5. Mock data", "6. Get tree from file"};
//    const int messageSize = sizeof(messages) / sizeof(messages[0]);
//    int (*functions[])(BinaryTree *) = {NULL, D_AddBT, D_FindBT, D_DeleteBT, D_ShowBT, D_MockBT};
//    BinaryTree *tree = getBinaryTree();
//    int actionIndex;
//    while ((actionIndex = dialog(messages, messageSize))) {
//        if (actionIndex == 6) {0
//            if (!D_GetFromFile(&tree)) break;
//        } else if (!functions[actionIndex](tree)) break;
//    }
//    puts("That's all. Bye!\n");
//    destroyBinaryTreeDeep(tree);
    for (int i = 10000; i < 1000000; i += 10000) {
        int time = deleteInRandomFilledTree(i);
        printf("%d %d \n", i, time);
    }

    return 0;
}
