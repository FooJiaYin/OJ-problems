#include <stdlib.h>
#include <stdio.h>
#include "function.h"

void deleteNode(Node ** nd, int data)
{
    if(data==1)
        *nd = (*nd)->next;

    else {
        Node *now = *nd;
        for(int i=1; i<data-1 && now; i++, now=now->next);
        now->next = now->next->next;
    }
}

Node* createList()
{
    Node *head;
    Node *now = head;
    while(1){
        now->next = (Node*)malloc(sizeof(Node));
        scanf("%d", &now->next->data);
        if(now->next->data==-1) break;
        else now = now->next;
    }
    now->next = NULL;
    return head->next;
}
