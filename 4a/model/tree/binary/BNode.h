#ifndef LAB4_BNODE_H
#define LAB4_BNODE_H
typedef struct BNode {
    unsigned key;
    const char *data;
    int generation;
    struct BNode *parent;
    struct BNode *left;
    struct BNode *right;
    struct BNode *next;
    struct BNode *previous;
} BNode;

BNode *getBNode(unsigned key, const char *data);

#endif
