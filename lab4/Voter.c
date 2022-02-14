#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Voter.h"

struct Voter {
    const char *fullName;
    const char *stationNumber;
    int age;
};
typedef struct Voter Voter;


struct VotersArray {
    Voter **data;
    int size;
};

typedef struct VotersArray VotersArray;

const char *toString(Voter *voter) {
    char *str = malloc(sizeof(Voter) + strlen("ФИО: , Номер избирательного участка: , Возраст: \n") + 1);
    strcat(str, "ФИО: ");
    strcat(str, voter->fullName);
    strcat(str, ", Номер избирательного участка: ");
    strcat(str, voter->stationNumber);
    strcat(str, ", Возраст: ");
    char c[3] = {voter->age / 10 + '0', voter->age % 10 + '0', '\0'};
    strcat(str, c);
    return str;
}

Voter *fromString(const char *str) {
    int n = strlen(str);
    if (str[n - 1] == '\n') n -= 1;
    Voter *voter = malloc(sizeof(Voter));
    int i = 8;
    char buff[1024];
    while (str[i] != ',' && i < n) {
        buff[i - 8] = str[i];
        ++i;
    }
    buff[i - 8] = '\0';
    voter->fullName = malloc(sizeof(char) * strlen(buff));
    strcpy(voter->fullName, buff);
    i += 58;
    int j = i;
    while (str[j] != ',' && j < n) {
        buff[j - i] = str[j];
        ++j;
    }
    buff[j - i] = '\0';
    if (!validateStationNumber(buff)) {
        destroy(voter);
        return NULL;
    }
    voter->stationNumber = malloc(sizeof(char) * strlen(buff));
    strcpy(voter->stationNumber, buff);
    int d = ((int) (str[n - 2] - '0')) * 10;
    int o = ((int) (str[n - 1] - '0')) * 1;
            if ((d+o)<18 || (d+o)>100) {

		destroy(voter);
        return NULL;
    }
    voter->age = d + o;
    return voter;
}

int validateStationNumber(const char *number) {
    int n = (int) strlen(number);
    if (n != 7) return 0;
    if (number[3] != '-') return 0;
    for (int i = 0; i < 3; ++i)
        if (!isalpha((number[i])))return 0;
    for (int i = 4; i < 7; ++i)
        if (!isdigit(number[i])) return 0;
    return 1;
}

void destroy(Voter *voter) {
    free(voter->fullName);
    free(voter->stationNumber);
    free(voter);
}

void destroyArray(VotersArray *votersArray) {
    for (int i = 0; i < votersArray->size; ++i)
        destroy(votersArray->data[i]);
    free(votersArray->data);
    free(votersArray);
}


int validateAge(char *age) {
    if (strlen(age) != 2) return 0;
    if (!(isdigit(age[0]) && isdigit(age[1]))) return 0;
    int newAge = (age[0] - '0') * 10 + (age[1] - '0');
    if (newAge >= 18 && newAge <= 100) return newAge;
    return 0;
}


int insert(VotersArray *source, Voter *element, int index) {
    if (index < 0 || index >= source->size) return 0;
    int n = (source->size + 1);
    Voter **data = malloc(sizeof(Voter) * n);
    int i = 0;
    while (i < n) {
        if (i < index) data[i] = source->data[i];
        else if (i == index) data[i] = element;
        else data[i] = source->data[i - 1];
        ++i;
    }
    free(source->data);
    source->data = data;
    source->size = n;
    return 1;
}

int delete(VotersArray *source, int index) {
    if (index < 0 || index >= source->size) return 0;
    int n = (source->size - 1);
    Voter **data = malloc(sizeof(Voter) * n);
    int i = 0;
    while (i < n) {
        if (i < index) data[i] = source->data[i];
        else data[i] = source->data[i + 1];
        ++i;
    }
    free(source->data);
    source->data = data;
    source->size = n;
    return 1;
}

int deleteMany(VotersArray *source, int index, int count) {
    if (index < 0 || index >= source->size) return 0;
    if (count < 0 || index + count >= source->size) return 0;
    for (int i = index; i < index + count; ++i)
        if (!delete(source, index)) return 0;
    return 1;
}
