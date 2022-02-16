#include <stdlib.h>
#include <printf.h>
#include "DynamicArray.h"

int main() {
    DynamicArray *a = getDynamicArray();
    for (int i = 0; i < 10; ++i) {
        add(a, i );
    }
    printArray(a);
    return 0;
}
