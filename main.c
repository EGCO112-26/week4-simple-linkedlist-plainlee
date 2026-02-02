#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "std_node.h"

int main(int argc,const char *argv[]) {
    if (argc < 2) {
      //  printf("Usage: %s id1 name1 id2 name2 ...\n", argv[0]);
        return 1;
    }


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
            temp = newNode;
        }
    }


    printf("Student List:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d %s\n", temp->id, temp->name);
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL) {
        head = head->next;
        free(temp);
        temp = head;
    }

    return 0;
}
