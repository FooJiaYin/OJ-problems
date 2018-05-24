#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void constructTree(Node** head)
{
    *head = (Node*)malloc(sizeof(Node));
    (*head)->data = s2[idx++];
    (*head)->right = (*head)->left = NULL;
    if(s2[idx-1]=='|'||s2[idx-1]=='&') {
        constructTree(&((*head)->right));
        constructTree(&((*head)->left));
    }
}
