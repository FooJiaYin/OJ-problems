#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void Create_List(Node** ptr, int data) {
    Node *node = (Node*) malloc(sizeof(Node));
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

Node* Add_List(Node* node_a, Node* node_b) {
    Node *head = NULL;
    while(node_a != NULL || node_b !=NULL) {
        if(node_a != NULL && node_b !=NULL) {
            Create_List(&head, node_a->data + node_b->data);
            node_a = node_a->next;
            node_b = node_b->next;
        }
        else if(node_a != NULL) {
            Create_List(&head, node_a->data);
            node_a = node_a->next;
        }
        else if(node_b != NULL) {
            Create_List(&head, node_b->data);
            node_b = node_b->next;
        }
    }
    return head;
}

void Print_List(Node* node) {
    while(node->next != NULL) {
        printf("%d->", node->data);
        node = node->next;
    }
    printf("%d\n", node->data);
}

void Free_List(Node* node) {
    while(node != null) {
        free(node);
        node = node->next;
    }
}
