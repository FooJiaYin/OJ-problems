#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

void Create_List(Node**, int);
Node* Add_List(Node*, Node*);
void Print_List(Node*);
void Free_List(Node*);
