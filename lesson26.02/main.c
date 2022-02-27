#include <stdio.h>

void removeZeros(int a[], int length) {
    int s = 0;
    for (int i = 0; i < length; ++i) {
        a[s] = a[i];
        if (a[i] != 0) s++;
    }
} // 1 2 0 3 4

void removeSmiles(char string[], int length) {
    int s = 0;
    int i = 0;
    while (i < length - 1) {
        string[s] = string[i];
        if (!(string[i] == ':' && string[i + 1] == ')')) {
            s++;
            if (i == 0) {
                ++i;
                continue;
            }
        } else {
            i++;
            while (string[s - 1] == ':' && string[i + 1] == ')') {
                s--;
                i++;
            }
        }
        ++i;
    }
    if (i < length) {
        string[s] = string[length - 1];
        string[s + 1] = '\0';
    } else
        string[s] = '\0';
}


// :)
int main() {
    char string[] = "::))0:::::)))):))123:::)))21:)::))):)"; //:)1:)11:)11:):)1:):)3 21
    removeSmiles(string, 35);
    printf("%s", string);
    return 0;
}


