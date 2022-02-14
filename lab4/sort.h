#include <stddef.h>
#include "Voter.h"

void swap(struct Voter *a, struct Voter *b);

void quickSort(struct VotersArray *base, int (*compare)(const struct Voter *, const struct Voter *));

void reverseQuickSort(struct VotersArray *source, int low, int high,
                      int (*compare)(const struct Voter *, const struct Voter *));

int binarySearch(struct VotersArray *votersArray, struct Voter *voter, int low, int high,int (*compare)(const struct Voter *, const struct Voter *));

void insertionSort(struct VotersArray *votersArray, int (*compare)(const struct Voter *, const struct Voter *));
void dualSelectionSort(struct VotersArray *votersArray, int (*compare)(const struct Voter *, const struct Voter *));