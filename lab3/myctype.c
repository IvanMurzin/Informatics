#include "myctype.h"
#include <stdio.h>
int isdigit1(char ch) {
    //printf("%c %d\n", ch, ch-'0');
    printf("%d \n", ((ch>= 48) && (ch <= 57))	);
	return ((ch>= 48) && (ch <= 57));
}
