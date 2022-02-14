#include <stdio.h>
#include <readline/readline.h>
#include <stdlib.h>
#include "Voter.h"
#include "input.h"
#include "output.h"
#include "sort.h"

struct Voter {
    const char *fullName;
    const char *stationNumber;
    int age;
};

struct VotersArray {
    Voter **data;
    int size;
};

int comp(const Voter *first, const Voter *second) {
    if (first->age == second->age) return 1;
    if (first->age > second->age) return -1;
    return 0; // first->age < second->age
}

int comp1(const Voter *first, const Voter *second) {
    if (first->fullName[0] == second->fullName[0]) return 1;
    if (first->fullName[0] > second->fullName[0]) return 1;
    return 0;
}

int main() {
//    int n = -1;
//    char c;
//    printf("Введите:\n"
//           "1 - чтобы считать данные из стандартного ввода\n"
//           "2 - чтобы считать данные из файла\n"
//           "3 - чтобы сгенерировать данные\n"
//           "0 - для выхода из программы\n");
//    scanf("%s", &c);
//    n = c - '0';
//    while (n < 0 || n > 3) {
//        printf("Неправильно, повторите ввод: ");
//        scanf("%s", &c);
//        n = c - '0';
//    }
//    fflush(stdin);
//    char *filePath;
//    VotersArray *votersArray;
//    int votersCount;
//    switch (n) {
//        case 0:
//            return 0;
//        case 1:
//            votersArray = readFromStdInput();
//            break;
//        case 2:
//            while (votersArray == NULL) {
//                filePath = readline("Введите путь до файла: ");
//                votersArray = readFromFile(filePath);
//            }
//            break;
//        case 3:
//            printf("Введите количество избирателей: ");
//            scanf("%d", &votersCount);
//            while (votersCount < 0 || votersCount > 10) {
//                printf("Неверное количество избирателей\n");
//                printf("повторите ввод: ");
//                scanf("%d", &votersCount);
//                fflush(stdin);
//            }
//            votersArray = generateData(votersCount);
//            break;
//    }
//    printf("\nВаши данные:\n");
//    const char *str;
//    for (int i = 0; i < votersArray->size; ++i) {
//        str = toString(votersArray->data[i]);
//        printf("%s\n", str);
//        str = NULL;
//    }
//
//    printf("Введите:\n"
//           "1 - чтобы отсортировать данные быстрой сортировкой\n"
//           "2 - чтобы отсортировать данные сортировкой вставками с бинарным поиском\n"
//           "3 - чтобы отсортировать данные данные двухсторонней сортировкой выбором\n"
//           "0 - для выхода из программы\n");
//
//    scanf("%s", &c);
//    n = c - '0';
//    while (n < 0 || n > 3) {
//        printf("Неправильно, повторите ввод: ");
//        scanf("%s", &c);
//        n = c - '0';
//    }
//    switch (n) {
//        case 0:
//            destroyArray(votersArray);
//            return 0;
//        case 1:
//            quickSort(votersArray, comp1);
//            break;
//        case 2:
//            insertionSort(votersArray, comp);
//            break;
//        case 3:
//            dualSelectionSort(votersArray, comp);
//            break;
//    }
//    printf("\nВаши данные:\n");
//    for (int i = 0; i < votersArray->size; ++i) {
//        char *str = toString(votersArray->data[i]);
//        printf("%s\n", toString(votersArray->data[i]));
//        free(str);
//    }
//
//    printf("Записать данные в файл?\n"
//           "1 - зaписать данные в файл\n"
//           "0 - для выхода из программы\n");
//
//    scanf("%s", &c);
//    n = c - '0';
//    while (n < 0 || n > 1) {
//        printf("Неправильно, повторите ввод: ");
//        scanf("%s", &c);
//        n = c - '0';
//    }
//    if (n == 0) {
//        destroyArray(votersArray);
//        return 0;
//    }
//    int result = 0;
//    while (!result) {
//        filePath = readline("Введите путь до файла: ");
//        result = writeToFile(filePath, votersArray);
//        if (result != 0) printf("Успешно");
//        else printf("Что-то пошло не так, повторите ввод: ");
//    }
//    destroyArray(votersArray);
//    return 0;
    struct VotersArray *votersArray = generateData(5);
    destroyArray(votersArray);
//    const char *a = readline("");
//    free(a);
}

// /Users/ivanmurzin/Projects/CLionProjects/lab4/file1.txt
