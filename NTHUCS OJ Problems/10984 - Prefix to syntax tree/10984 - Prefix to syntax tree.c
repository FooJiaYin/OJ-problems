#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void constructTree(Node** head)
{
    *head = (Node*)malloc(sizeof(Node));
    scanf("%c", &(*head)->data);
    (*head)->left = (*head)->right = NULL;
    if((*head)->data == '|' || (*head)->data == '&') {
        constructTree(&((*head)->left));
        constructTree(&((*head)->right));
    }
}
