#include <stdio.h>
#include <stdlib.h>
#include "function.h"


BTNode* EXPR()
{
    BTNode *root = (BTNode*)malloc(sizeof(BTNode));
    if(expr[pos-1]=='(' || pos==0) {
        root = FACTOR();
        pos--;
    }
    else if(expr[pos] == ')' || expr[pos]=='A' || expr[pos]=='B' || expr[pos]=='C' || expr[pos]=='D') {
        root->right = FACTOR();
        if(expr[pos]=='&') root->data = OP_AND;
        else if(expr[pos]=='|') root->data = OP_OR;
        else {
            pos--;
            return root->right;
        }
        pos--;
        root->left = EXPR();
    }
    return root;
}

BTNode* FACTOR()
{
    BTNode *root;
    if(expr[pos]=='A' || expr[pos]=='B' || expr[pos]=='C' || expr[pos]=='D'){
        pos--;
        root = makeNode(expr[pos+1]);
    }
    else if(expr[pos]==')') {
        pos--;
        root = EXPR();
    }
    return root;
}
BTNode* makeNode(char c)
{
    BTNode *leave = (BTNode*)malloc(sizeof(BTNode));
    switch(c){
        case 'A':
            leave->data = ID_A;
            break;
        case 'B':
            leave->data = ID_B;
            break;
        case 'C':
            leave->data = ID_C;
            break;
        case 'D':
            leave->data = ID_D;
            break;
    }
    leave->left = NULL;
    leave->right = NULL;
    return leave;
}
