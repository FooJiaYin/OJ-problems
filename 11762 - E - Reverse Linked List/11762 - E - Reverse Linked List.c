#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int num;
    struct _node *prev;
} Node;

Node* Create_List(Node* now, int input)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->num = input;
    newNode->prev = now;
    return newNode;
}

Node* Reverse_List(Node* head) {
    return head;
}

void Print_List(Node* now) {
    while(now->prev!=NULL) {
        printf("%d->", now->num);
        now = now->prev;
    }
    printf("%d\n", now->num);
}

void Free_List(Node* now) {
    while(now!=NULL) {
        Node *temp = now;
        now = now->prev;
        free(temp);
    }
}
