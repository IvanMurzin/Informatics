#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct List List;

struct Node {
    char data;
    Node *next;
};


struct List {
    int size;
    Node *head;
    Node *last;
};

int addElementToList(List *list, char data);

void destroyNode(Node *node);

void destroy(List *list);

void printList(List *list);

List *getStringList();

void destroyWord(List *word);

void *duplicateWords(List *list);
