#include "myreadline.h"
#include <stdio.h>
#include "mystring.h"
char *readline(const char *str) {
    printf("%s", str);
    char buf[81];
    char *res = NULL;
    scanf("%80[^\n]", buf);
    int len = (int) strlen(buf);
    res = (char *) malloc((len + 1) * sizeof(char));
    memcpy(res, buf, len);
    res[len + 1] = '\0';
    return res;
}
