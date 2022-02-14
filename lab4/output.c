#include <stdio.h>
#include <stdlib.h>
#include "output.h"

struct Voter {
    const char *fullName;
    const char *stationNumber;
    int age;
};

typedef struct Voter Voter;
typedef struct VotersArray VotersArray;

struct VotersArray {
    Voter **data;
    int size;
};


int writeToFile(const char *fileName, VotersArray *votersArray) {
    FILE *file = fopen(fileName, "a+");
    if (file == NULL) return 0;
    fprintf(file, "%d\n", votersArray->size);
    for (int i = 0; i < votersArray->size; ++i) {
        char *str = toString(votersArray->data[i]);
        fprintf(file, "%s\n", str);
        free(str);
    }
    return 1;
}