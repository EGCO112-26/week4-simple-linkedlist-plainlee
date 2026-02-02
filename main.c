#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "std_node.h"

int main(int argc, char *argv[]) {

    typedef struct node Node;
    typedef Node* NodePtr;

    NodePtr head = NULL;
    NodePtr temp = NULL;

    int i;
    for (i = 1; i < argc; i += 2) {

        NodePtr newNode = (NodePtr) malloc(sizeof(Node));

        newNode->id=  atoi(argv[i]);
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


    printf("print linked list\n");
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
