//#include <stdlib.h>
//#include <string.h>
//#include "Dialog.h"
//#include "readline/readline.h"
//
//int _getUnsigned(int *a) {
//    int n;
//    do {
//        n = scanf("%d", a);
//        if (n < 0) return 0;
//        if (n == 0 || *a < 0) {
//            printf("%s\n", "Error! Repeat input");
//            scanf("%*[^\n]");
//            n = 0;
//        }
//    } while (n == 0);
//    return 1;
//}
//
//int _getDrawMode() {
//    char *res = readline("Enter Draw Mode -->\n");
//    DrawMode result = DEFAULT;
//    if (strcmp(res, "PARENT") == 0) result = PARENT;
//    else if (strcmp(res, "FLASHED") == 0) result = FLASHED;
//    else if (strcmp(res, "FLASHED_ONLY") == 0) result = FLASHED_ONLY;
//    else puts("set to DEFAULT");
//    free(res);
//    return result;
//}
//
//int dialog(const char *messages[], int messageSize) {
//    char *errorMessage = "";
//    unsigned actionIndex;
//    int n;
//    do {
//        puts(errorMessage);
//        errorMessage = "You are wrong. Repeat, please!";
//        for (int i = 0; i < messageSize; ++i) {
//            puts(messages[i]);
//        }
//        puts("Make your choice --> ");
//        n = _getUnsigned(&actionIndex);
//        if (n == 0) actionIndex = 0;
//    } while (actionIndex < 0 || actionIndex >= messageSize);
//    return actionIndex;
//}
//
//int D_AddBT(BinaryTree *tree) {
//    unsigned key = 0;
//    puts("Enter key: --> ");
//    _getUnsigned(&key);
//    char *data = NULL;
//    int n;
//    do {
//        n = 0;
//        data = readline("Enter data --> \n");
//        if (*data == '\0') {
//            puts("Incorrect input");
//            free(data);
//            n = 1;
//            continue;
//        }
//    } while (n);
//    addBT(tree, key, data);
//    puts("Ok");
//    return 1;
//}
//
//int D_FindBT(BinaryTree *tree) {
//    unsigned key = 0;
//    puts("Enter key: -->");
//    _getUnsigned(&key);
//    BNode **result;
//    int size = 0;
//    int findResult = findBT(tree, key, &result, &size);
//    if (findResult) puts("Not Found");
//    else {
//        for (int i = 0; i < size; ++i) {
//            printf("%d.%d :  %s\n", result[i]->key, result[i]->generation, result[i]->data);
//        }
//        free(result);
//    }
//    return 1;
//}
//
//int D_DeleteBT(BinaryTree *tree) {
//    unsigned key = 0;
//    puts("Enter key: -->");
//    _getUnsigned(&key);
//    int deleteResult = deleteBT(tree, key);
//    if (deleteResult) puts("Not Found");
//    else puts("Ok");
//    return 1;
//}
//
//int D_ShowBT(BinaryTree *tree) {
//    DrawMode mode = _getDrawMode();
//    unsigned key = 0;
//    puts("Enter key: -->");
//    int n = scanf("%d", &key);
//    if (n < 0) return 0;
//    if (n == 0 || key < 0) {
//        scanf("%*[^\n]");
//        printNLR_BT(tree, mode);
//    } else {
//        printBoundNLR_BT(tree, key, mode);
//    }
//    puts("Ok");
//    return 1;
//}
//
//void _addMock(BinaryTree *tree, unsigned key, const char *str) {
//    char *str1 = malloc(sizeof(char) * strlen(str) + 1);
//    strcpy(str1, str);
//    addBT(tree, key, str1);
//}
//
//int D_MockBT(BinaryTree *tree) {
//    _addMock(tree, 5, "data1");
//    _addMock(tree, 7, "data2");
//    _addMock(tree, 4, "data3");
//    _addMock(tree, 3, "data4");
//    _addMock(tree, 8, "data5");
//    _addMock(tree, 6, "data6");
//    _addMock(tree, 5, "data7");
//    _addMock(tree, 3, "data8");
//    _addMock(tree, 8, "data9");
//    _addMock(tree, 1, "data10");
//    puts("Ok");
//    return 1;
//}
//
//int D_GetFromFile(BinaryTree **tree) {
//    char *fileName = readline("Enter File path -->\n");
//    BinaryTree *newTree = getBinaryTreeFromFile(fileName);
//    free(fileName);
//    if (newTree == NULL) {
//        puts("Error reading from file");
//        return 0;
//    }
//    destroyBinaryTreeDeep(*tree);
//    *tree = newTree;
//    puts("Ok");
//    return 1;
//}