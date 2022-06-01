#include "Dialog.h"

int main() {
    const char *messages[] = {"0. Quit", "1. Add", "2. Find", "3. Delete", "4. Show", "5. Mock data"};
    const int messageSize = sizeof(messages) / sizeof(messages[0]);
    int (*functions[])(BinaryTree *) = {NULL, D_AddBT, D_FindBT, D_DeleteBT, D_ShowBT, D_MockBT};
    BinaryTree *tree = getBinaryTree();
    int actionIndex;
    while ((actionIndex = dialog(messages, messageSize))) {
        if (!functions[actionIndex](tree)) break;
    }
    puts("That's all. Bye!\n");
    destroyBinaryTreeDeep(tree);
    return 0;
}
