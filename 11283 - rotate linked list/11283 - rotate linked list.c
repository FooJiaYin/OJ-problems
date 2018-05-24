#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void rotateList(Node** head, int k)
{
    Node *now = *head;
    Node *temp;
    for(int i=0; now->next != NULL; i++) {
        if(i == k-1) temp = now;
        now = now->next;
    }
    now->next = *head;
    *head = temp->next;
    temp->next = NULL;
}
