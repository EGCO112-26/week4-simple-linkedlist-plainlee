#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stdnode.h"

int main(int argc, char *argv[]) {
    
    typedef struct node Node;
    typedef Node* NodePtr;

    NodePtr head = NULL;
    NodePtr temp = NULL;
    int i;

    
    if (argc < 3 || (argc - 1) % 2 != 0) {
        return 0;
    }

    
    for (i = 1; i < argc; i += 2) {

        NodePtr newNode = (NodePtr) malloc(sizeof(Node));
        if (newNode == NULL) return 1;

        newNode->id = atoi(argv[i]);
        strcpy(newNode->name, argv[i + 1]);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    
    temp = head;
    while (temp) {
        printf("%d %s\n", temp->id, temp->name);
        temp = temp->next;
    }

    
    temp = head;
    while (temp) {
        head = head->next;
        free(temp);
        temp = head;
    }

    return 0;
}