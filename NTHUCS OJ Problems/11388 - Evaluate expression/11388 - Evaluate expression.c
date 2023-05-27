#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    char data;
    struct _node *left;
    struct _node *right;
} Node;

Node* constructTree()
{
    Node *head = (Node*)malloc(sizeof(Node));
    scanf("%c", &head->data);
    head->left = head->right = NULL;
    if(head->data=='|'||head->data=='&'){
        head->left = constructTree();
        head->right = constructTree();
    }
    return head;
}

int evaluate(int A, int B, int C, int D, Node* head)
{
    switch(head->data){
        case 'A': return A;
        case 'B': return B;
        case 'C': return C;
        case 'D': return D;
        case '|': return (evaluate(A, B, C, D, head->left)||evaluate(A, B, C, D, head->right));
        case '&': return (evaluate(A, B, C, D, head->left)&&evaluate(A, B, C, D, head->right));
    }
}

int main(void)
{
    Node *head = constructTree();
    int A,B,C,D;
    scanf("%d %d %d %d", &A, &B, &C, &D);
    printf("%d", evaluate(A, B, C, D, head));
}
