#include "List.h"

int main() {
//    while (1) {
        List *list = getStringList();
        duplicateWords(list);
        printList(list);
        destroy(list);
//    }
    return 0;
}

