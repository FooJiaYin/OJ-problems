#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void Create_List(Node **ptr, int data) {
    Node *node = (Node *) malloc(sizeof(Node*));
    node->data = data;
    if(*ptr == NULL) {
        *ptr = node;
    }
    else {
        Node *temp = *ptr;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
    node->next = NULL;
}

Node* Delete_Middle_Node(Node* head) {
    Node *temp = head;
    int n=1;
    while(temp->next != NULL) {
        temp = temp->next;
        n++;
    }

    if(n%2) n = (n+1)/2;
    else  n = (n/2)+1;

    int i;
    for(i=0, temp = head; i<n-2; i++) {
        temp = temp->next;
    }
    //printf("%d\n", temp->data);
    Node *del = temp->next;
    temp->next = del->next;
    free(del);

    return head;
}

void Print_List(Node *node) {
    while(node->next != NULL) {
        printf("%d->", node->data);
        node = node->next;
    }
    printf("%d\n", node->data);
}

void Free_List(Node *node) {
    while(node != NULL) {
        free(node);
        node = node->next;
    }
}
