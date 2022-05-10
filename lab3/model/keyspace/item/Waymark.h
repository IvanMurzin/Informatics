#ifndef LAB3_WAYMARK_H
#define LAB3_WAYMARK_H
typedef struct Waymark {
    int next;
    int previous;
} Waymark;

Waymark getWaymark(int next, int previous);
#endif
