#include "sort.h"

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

typedef struct VotersArray VotersArray;
typedef struct Voter Voter;

void swap(Voter *a, Voter *b) {
    Voter t = *a;
    *a = *b;
    *b = t;
}

int partition(VotersArray *source, int low, int high, int (*compare)(const Voter *, const Voter *)) {
    Voter *pivot = source->data[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (!compare(source->data[j], pivot)) {
            i++;
            swap(source->data[i], source->data[j]);
        }
    }
    swap(source->data[i + 1], source->data[high]);
    return (i + 1);
}

void quickSort(VotersArray *source, int (*compare)(const Voter *, const Voter *)) {
    reverseQuickSort(source, 0, source->size - 1, compare);
}

void reverseQuickSort(VotersArray *source, int low, int high, int (*compare)(const Voter *, const Voter *)) {
    if (low < high) {
        int pi = partition(source, low, high, compare);
        reverseQuickSort(source, low, pi - 1, compare);
        reverseQuickSort(source, pi + 1, high, compare);
    }
}

int
binarySearch(VotersArray *votersArray, Voter *item, int low, int high, int (*compare)(const Voter *, const Voter *)) {
    if (high <= low)
        return (compare(item, votersArray->data[low]) == -1) ? (low + 1) : low;
    int mid = (low + high) / 2;
    if (compare(item, votersArray->data[mid]) == 1)
        return mid + 1;
    if (compare(item, votersArray->data[mid]) == -1)
        return binarySearch(votersArray, item, mid + 1, high, compare);
    return binarySearch(votersArray, item, low, mid - 1, compare);
}

void insertionSort(VotersArray *votersArray, int (*compare)(const Voter *, const Voter *)) {
    int i, loc, j;
    Voter *selected;
    for (i = 1; i < votersArray->size; ++i) {
        j = i - 1;
        selected = votersArray->data[i];
        loc = binarySearch(votersArray, selected, 0, j, compare);
        while (j >= loc) {
            votersArray->data[j + 1] = votersArray->data[j];
            j--;
        }
        votersArray->data[j + 1] = selected;
    }
}

void dualSelectionSort(VotersArray *votersArray, int (*compare)(const Voter *, const Voter *)) {

    for (int j = 0; j < votersArray->size / 2; j++) {
        Voter *min = votersArray->data[j];
        Voter *max = votersArray->data[j];
        Voter *tmp;
        int mini = j, maxi = j;
        for (int i = j; i < votersArray->size - j; i++) {
            if (compare(min, votersArray->data[i]) == -1) {
                min = votersArray->data[i];
                mini = i;
            }
            if (compare(votersArray->data[i], max) == -1) {
                max = votersArray->data[i];
                maxi = i;
            }
        }

        tmp = votersArray->data[j];
        if (j == maxi) {
            maxi = mini;
        }

        votersArray->data[j] = min;
        votersArray->data[mini] = tmp;

        tmp = votersArray->data[votersArray->size - j - 1];
        votersArray->data[votersArray->size - j - 1] = max;
        votersArray->data[maxi] = tmp;
    }
}