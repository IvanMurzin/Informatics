#include "List.h"

int addElementToList(List *list, char data) {
    Node *element = malloc(sizeof(Node));
    element->data = data;
    element->next = NULL;
    if (list->size == 0) {
        list->size = 1;
        list->head = element;
        list->last = list->head;
        return 1;
    }
    list->size += 1;
    list->last->next = element;
    list->last = list->last->next;
    return 1;
}

void destroyNode(Node *node) {
    free(node);
}

void destroy(List *list) {
    Node *tmp = list->head;
    while (tmp != NULL) {
        tmp = list->head->next;
        destroyNode(list->head);
        list->head = tmp;
    }
    list->size = 0;
    free(list);
}

void printList(List *list) {
    Node *tmp = list->head;
    while (tmp != NULL) {
        printf("%c", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

List *getStringList() {
    List *list = malloc(sizeof(List));
    char c;
    while (1) {
        c = (char) getchar();
        if (c == '\n') return list;
        addElementToList(list, c);
    }
}

void destroyWord(List *word) {
    word->head = NULL;
    word->last = NULL;
    word->size = 0;
}

void *duplicateWords(List *list) {
    Node *tmp = list->head;
    int letters = 0;
    List *word = malloc(sizeof(List));
    while (tmp != NULL) {
        char data = tmp->data;
        if (data == ' ' || data == '\t' && letters != 0) {
            letters = 0;
            if (word != NULL && word->size != 0 && word->size % 2 == 0) {
                addElementToList(word, ' ');
                word->last->next = tmp->next;
                tmp->next = word->head;
                tmp = word->last;
                destroyWord(word);
            } else {
                destroy(word);
                word = malloc(sizeof(List));
            }
        } else {
            addElementToList(word, data);
            letters += 1;
        }
        tmp = tmp->next;
    }
    if (word != NULL && word->size % 2 == 0) {
        addElementToList(list, ' ');
        list->last->next = word->head;
        list->last = word->last;
        destroyWord(word);
        free(word);
    } else destroy(word);
}

