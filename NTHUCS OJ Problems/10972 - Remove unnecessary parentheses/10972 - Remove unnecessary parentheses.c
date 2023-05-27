#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
    char data;
    struct _node *left;
    struct _node *right;
} Node;

Node* makeNode(char);
Node* EXPR();
Node* FACTOR();
void printInfix(Node*);

char exp[260] = {0};
int now = 0;

int main(void) 
{
    scanf("%s", exp);
    now = strlen(exp)-1;
    Node *root = EXPR();
    printInfix(root);
    return 0;
}

Node* EXPR()
{
    Node *root = (Node*)malloc(sizeof(Node));
    if(exp[now-1]=='(' || now==0) {
        root = FACTOR();
        now--;
    }
    else if(exp[now] == ')' || exp[now]=='A' || exp[now]=='B' || exp[now]=='C' || exp[now]=='D') {
        root->right = FACTOR();
        if(exp[now]=='&' || exp[now]=='|') root->data = exp[now];
        else {
            now--;
            return root->right;
        }
        now--;
        root->left = EXPR();
    }
    return root;
}

Node* FACTOR()
{
    Node *root;
    if(exp[now]=='A' || exp[now]=='B' || exp[now]=='C' || exp[now]=='D'){
        root = (Node*)malloc(sizeof(Node));
        root->data = exp[now];
        root->left = NULL;
        root->right = NULL;
        now--;
    }
    else if(exp[now]==')') {
        now--;
        root = EXPR();
    }
    return root;
}

void printInfix(Node *root)
{
    if(root == NULL) return;
    printInfix(root->left);
    printf("%c", root->data);
    if(root->right) {
        if(root->right->data=='&' || root->right->data=='|'){
            printf("(");
            printInfix(root->right);
            printf(")");
        }
        else printInfix(root->right);
    }
    free(root);
}
