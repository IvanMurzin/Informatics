#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "readline/readline.h"
#include "ctype.h"
#include "string.h"


int main() {
    char *start = readline("");
    clock_t timeStart = clock();
    int len = (int) strlen(start);
    char *end = start + len;
    int tempNum = 0;
    int result = 0;
    int ten = 1;
    while (end != start) {
        char ch = *end;
        --end;
        if (isdigit(ch)) {
            tempNum += (ch - '0') * ten;
            ten *= 10;
			printf("%c", ch);
        } else {
            if (ch == '+') result += tempNum;
            if (ch == '-') result -= tempNum;
			else continue;
            tempNum = 0;
            ten = 1;
        }
    }
    if (*start == '+')result += tempNum;
    else if (*start == '-')result -= tempNum;
    else result += tempNum + (*end - '0') * ten;
    printf("%s = %d\n", start, result);
    free(start);
    clock_t timeEnd = clock();
    printf("Время работы программы: %ld\n", timeEnd - timeStart);
    return 0;
}
