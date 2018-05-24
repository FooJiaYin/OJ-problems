#include <stdio.h>
#include <stdlib.h>
#include "function.h"

Node* createList(int n)
{
    Node *new;
    new = (Node*)malloc(sizeof(Node));
    head = new;
    new->number = 1;
    for(int i=2; i<=n; i++) {
        /* Set up new Node */
        new->next = (Node*)malloc(sizeof(Node));
        new->next->number = i;
        new->next->prev = new;
        new = new->next;

        /* Link the last Node and head */
        if(i==n) {
            new->next = head;
            head->prev = new;
        }
    }
    return head;
}

void freeList()
{
    //free(head);
}

int solveJosephus(int step)
{
    Node *now = head;
    int direction = 1;
    while(now->next!=now) {
        Node *to_kill;
        /* Count */
        if(direction==1) {  //counter-clockwise
            for(int i=1; i<step-1; i++)
                now = now->next;
            to_kill = now->next;
        }
        else {              //clockwise
            for(int i=1; i<step-1; i++)
                now = now->prev;
            to_kill = now->prev;
        }
        /* Kill */
        to_kill->prev->next = to_kill->next;
        to_kill->next->prev = to_kill->prev;
        //free(to_kill);

        direction = -direction;
    }
    return now->number;
}
