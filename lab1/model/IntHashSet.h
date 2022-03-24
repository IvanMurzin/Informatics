typedef struct IntHashSet IntHashSet;

int addToSet(IntHashSet *set, int element);

IntHashSet *getIntHashSet();

int printSet(IntHashSet *set);

int printSetLikeArray(IntHashSet *set);

int containsInSet(IntHashSet *set, int element);

int countDifferences(IntHashSet *set1, IntHashSet *set2);

void destroySet(IntHashSet *set);