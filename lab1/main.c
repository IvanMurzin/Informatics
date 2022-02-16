#include <stdlib.h>
#include <printf.h>
#include "models/DynamicArray.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>

struct Integer {
    int *data;
};
typedef struct Integer Integer;


char *toString(Integer *integer) {
    if (!integer) return "";
    char *a = malloc(sizeof(char) * 20);
    sprintf(a, "I{d=%d};", *integer->data);
    return a;
}


int main() {
    Integer **integers = malloc(sizeof(Integer) * 20);
    for (int i = 0; i < 10; ++i) {
        integers[i] = malloc(sizeof(Integer));
        integers[i]->data = malloc(sizeof(int));
        *integers[i]->data = i;
    }






    StructInfo *info = getStructInfo(sizeof(Integer), toString);
    DynamicArray *a = getDynamicArray(info);
    for (int i = 0; i < 5; ++i) add(a, integers[i]);
    printArray(a);
    for (int i = 5; i < 10; ++i) addFirst(a, integers[i]);
    printArray(a);
    return 0;
}
