#include <stdlib.h>
#include <string.h>
#include "Item.h"
#include "Node.h"

Item *getItem(Key key, const char *data) {
    Item *node = calloc(1, sizeof(Item));
    node->key = key;
    node->number = 1;
    node->data = data;
    return node;
}

Item *getItemCopy(Item *item) {
    char *newData = malloc(strlen(item->data) + 1);
    strcpy(newData, item->data);
    Item *newItem = getItem(item->key, newData);
    newItem->number = item->number;
    return newItem;
}

void destroyItem(Item *item) {
    if (item == NULL) return;
    free((char *) item->data); // todo delete
    free(item);
}

int containsAny(Item *src, Key key, Item **result) {
    if (src == NULL) return 0;
    Item *cursor = src;
    while (cursor != NULL) {
        if (equalsKey(cursor->key, key)) {
            *result = cursor;
            return 1;
        }
        cursor = cursor->next;
    }
    return 0;
}

int contains(Item *src, Key key, int number, Item **result) {
    if (src == NULL) return 0;
    Item *cursor = src;
    while (cursor != NULL) {
        if (equalsKey(cursor->key, key) && cursor->number == number) {
            *result = cursor;
            return 1;
        }
        cursor = cursor->next;
    }
    return 0;
}

int deleteFromList(Item **src, Key key, int number) {
    if (src == NULL || *src == NULL) return 0;
    Item *cursor = *src;
    Item *previous = cursor;
    while (cursor != NULL) {
        if (equalsKey(cursor->key, key) && cursor->number == number) {
            Item *trash = cursor;
            if (previous == cursor)
                *src = (*src)->next;
            else
                previous->next = cursor->next;
            destroyItem(trash);
            return 1;
        }
        previous = cursor;
        cursor = cursor->next;
    }
    return 0;
}

int maxNumber(Item *src, Key key) {
    if (src == NULL) return -1;
    Item *cursor = src;
    int number = -1;
    while (cursor != NULL) {
        if (equalsKey(cursor->key, key)) number = number > cursor->number ? number : cursor->number;
        cursor = cursor->next;
    }
    return number;
}

int putSorted(Item **src, Item *item) {
    if (src == NULL || *src == NULL || item == NULL) return 1;
    Item *cursor = *src;
    while (cursor != NULL && equalsKey(cursor->key, item->key)) {
        item->number = item->number > (cursor->number + 1) ? item->number : (cursor->number + 1);
        cursor = cursor->next;
    }
    if (gt((*src)->key, item->key)) {
        item->next = *src;
        *src = item;
        return 0;
    }
    while (cursor->next != NULL) {
        while (cursor->next != NULL && equalsKey(cursor->next->key, item->key)) {
            item->number = (item->number > cursor->next->number + 1) ? item->number : (cursor->next->number + 1);
            cursor = cursor->next;
        }
        if (cursor->next == NULL) break;
        if (gt(cursor->next->key, item->key)) {
            Item *tmp = cursor;
            item->next = tmp->next;
            cursor->next = item;
            return 0;
        }
        cursor = cursor->next;
    }
    cursor->next = item;
    return 0;
}

