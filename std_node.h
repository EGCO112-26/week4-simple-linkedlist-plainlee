#ifndef node_h
#define node_h

struct node {
    char id;
    char name[50];
    struct node *next;
};

#endif