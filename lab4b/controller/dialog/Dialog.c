#include <stdlib.h>
#include <string.h>
#include "Dialog.h"
#include "readline/readline.h"

int _getUnsigned(int *a) {
    int n;
    do {
        n = scanf("%d", a);
        if (n < 0) return 0;
        if (n == 0 || *a < 0) {
            printf("%s\n", "Error! Repeat input");
            scanf("%*[^\n]");
            n = 0;
        }
    } while (n == 0);
    return 1;
}

Key _getKey() {
    unsigned x = 0, y = 0;
    puts("Enter key: --> ");
    puts("Enter x: --> ");
    _getUnsigned(&x);
    puts("Enter y: --> ");
    _getUnsigned(&y);
    Key result = {x, y};
    return result;
}

int dialog(const char *messages[], int messageSize) {
    char *errorMessage = "";
    unsigned actionIndex;
    int n;
    do {
        puts(errorMessage);
        errorMessage = "You are wrong. Repeat, please!";
        for (int i = 0; i < messageSize; ++i) {
            puts(messages[i]);
        }
        puts("Make your choice --> ");
        n = _getUnsigned(&actionIndex);
        if (n == 0) actionIndex = 0;
    } while (actionIndex < 0 || actionIndex >= messageSize);
    return actionIndex;
}

int D_Add(Tree *tree) {
    Key key = _getKey();
    char *data = NULL;
    int n;
    do {
        n = 0;
        data = readline("Enter data --> \n");
        if (*data == '\0') {
            puts("Incorrect input");
            free(data);
            n = 1;
            continue;
        }
    } while (n);
    switch (add(tree, key, data)) {
        case 0:
            puts("Ok");
            return 1;
        case 1:
            puts("Error");
            break;
        case 2:
            puts("Out of borders");
            break;
        case 3:
            puts("Tree overflow");
    }
    return 1;
}

int D_Find(Tree *tree) {
    Key key = _getKey();
    int number = 0;
    puts("Enter positional number --> ");
    _getUnsigned(&number);
    Item *result;
    if (find(tree, key, number, &result)) puts("Not Found");
    else {
        printf("Found: Key={%d.%d} Number=%d Data=%s\n", result->key.x, result->key.y, result->number, result->data);
    }
    return 1;
}

int D_FindMin(Tree *tree) {
    Item *result;
    if (findMin(tree, &result)) puts("Not Found");
    else {
        printf("Found: Key={%d.%d} Number=%d Data=%s\n", result->key.x, result->key.y, result->number, result->data);
    }
    return 1;
}

int D_DeleteByNumber(Tree *tree) {
    Key key = _getKey();
    int number = 0;
    puts("Enter positional number --> ");
    _getUnsigned(&number);
    int deleteResult = delete(tree, key, number);
    if (deleteResult) puts("Not Found");
    else puts("Ok");
    return 1;
}

int D_Delete(Tree *tree) {
    Key key = _getKey();
    int number = getMaxNumber(tree, key);
    printf("Deleting: Key={%d.%d} Number=%d\n", key.x, key.y, number);
    int deleteResult = delete(tree, key, number);
    if (deleteResult) puts("Not Found");
    else puts("Ok");
    return 1;
}

int D_Draw(Tree *tree) {
    createPngGraph(tree, 1);
    puts("Drew");
    return 1;
}

int D_DrawReverse(Tree *tree) {
    createPngGraph(tree, 0);
    puts("Drew");
    return 1;
}

void _addMock(Tree *tree, Key key, const char *str) {
    char *str1 = malloc(sizeof(char) * strlen(str) + 1);
    strcpy(str1, str);
    add(tree, key, str1);
}

int D_Mock(Tree *tree) {
    _addMock(tree, getKey(5, 2), "data1");
    _addMock(tree, getKey(7, 4), "data2");
    _addMock(tree, getKey(4, 1), "data3");
    _addMock(tree, getKey(3, 5), "data4");
    _addMock(tree, getKey(3, 2), "data5");
    _addMock(tree, getKey(6, 2), "data6");
    _addMock(tree, getKey(5, 1), "data7");
    _addMock(tree, getKey(3, 2), "data8");
    _addMock(tree, getKey(1, 6), "data9");
    _addMock(tree, getKey(1, 2), "data10");
    _addMock(tree, getKey(5, 2), "data11");
    _addMock(tree, getKey(7, 4), "data12");
    _addMock(tree, getKey(4, 1), "data13");
    _addMock(tree, getKey(3, 5), "data14");
    _addMock(tree, getKey(3, 2), "data15");
    _addMock(tree, getKey(6, 2), "data16");
    _addMock(tree, getKey(5, 1), "data17");
    _addMock(tree, getKey(3, 2), "data18");
    _addMock(tree, getKey(1, 6), "data19");
    _addMock(tree, getKey(1, 2), "data20");
    puts("Ok");
    return 1;
}
