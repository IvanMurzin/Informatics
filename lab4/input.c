#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include "input.h"

#define BUZZ_SIZE 1024

struct Voter {
    const char *fullName;
    const char *stationNumber;
    int age;
};

struct VotersArray {
    Voter **data;
    int size;
};

VotersArray *readFromStdInput() {
    int n;
    printf("Введите количество избирателей: ");
    scanf("%d", &n);
    fflush(stdin);
    while (n < 0 || n > 5) {
        printf("Неверное количество избирателей\n");
        printf("повторите ввод: ");
        scanf("%d", &n);
        fflush(stdin);
    }
    Voter **voters = malloc(sizeof(Voter) * n);
    VotersArray *votersArray = malloc(sizeof(VotersArray));
    for (int i = 0; i < n; ++i) {
        const char *fullName = readline("Введите имя избирателя:");
        const char *stationNumber = readline("Введите номер избирательного участка(вида CCC-DDD): ");
        while (!validateStationNumber(stationNumber)) {
            printf("Номер введен некорректно. \nНомер избирательного участка  - строка длиной 7 символов вида XXX-YYY, где X — это буква, а Y — цифра)\n");
            free(stationNumber);
            stationNumber = readline("Повторите ввод: ");
        }
        char *age;
        age = readline("Введите возраст избирателя: ");
        int t = validateAge(age);
        fflush(stdin);
        while (!t) {
            printf("Возраст введен некорректно.\nВозраст избирателя должен быть от 18 до 100 лет\n");
            printf("повторите ввод: ");
            free(age);
            age = readline("");
            t = validateAge(age);
            fflush(stdin);
        }
        free(age);
        Voter *voter = (Voter *) malloc(sizeof(Voter));
        voter->fullName = fullName;
        voter->stationNumber = stationNumber;
        voter->age = t;
        voters[i] = voter;
    }
    votersArray->data = voters;
    votersArray->size = n;
    return votersArray;
}

VotersArray *generateData(int n) {
    srand(time(NULL));
    Voter **voters = malloc(sizeof(Voter) * n);
    VotersArray *votersArray = malloc(sizeof(VotersArray));
    for (int i = 0; i < n; ++i) {
        Voter *voter = (Voter *) malloc(sizeof(Voter));
        char fullName[7] = {rand() % 20 + 'a', rand() % 20 + 'a', rand() % 20 + 'a', rand() % 20 + 'a',
                            rand() % 20 + 'a', rand() % 20 + 'a', '\0'};

        voter->fullName = malloc(sizeof(char) * strlen(fullName) + 1);
        stpcpy(voter->fullName, fullName);

        char stationNumber[8] = {rand() % 20 + 'a', rand() % 20 + 'a', rand() % 20 + 'a', '-',
                                 rand() % 10 + '0', rand() % 10 + '0', rand() % 10 + '0', '\0'};;

        voter->stationNumber = malloc(sizeof(char) * strlen(stationNumber) + 1);
        stpcpy(voter->stationNumber, stationNumber);

        voter->age = rand() % 70 + 18;
        voters[i] = voter;
    }
    votersArray->data = voters;
    votersArray->size = n;
    return votersArray;
}

VotersArray *readFromFile(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Такого файла не существует\n");
        return NULL;
    }
    int n;
    fscanf(file, "%d", &n);
    char trash;
    fscanf(file, "%c", &trash);
    Voter **voters = malloc(sizeof(Voter) * n);
    VotersArray *votersArray = malloc(sizeof(VotersArray));
    if (n < 0) {
        free(voters);
        free(votersArray);
        return NULL;
    }
    int size = 0;
    for (int i = 0; i < n; ++i) {
        char buff[BUZZ_SIZE];
        if (!fgets(buff, BUZZ_SIZE, file)) return NULL;
        Voter *voter = fromString(buff);
        if (voter != NULL) {
            size++;
            voters[i] = voter;
        }
    }
    votersArray->data = voters;
    votersArray->size = size;
    return votersArray;
}
