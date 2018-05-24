#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void showList(Node *head)
{
    for(int i=0; head->next && i<88; i++){
        printf("%d\n", head->number);
        head = head->prev;
    }
    printf("%d\n", head->number);
}

int main(){

    int n, m;

    while(scanf("%d%d", &n, &m)!=EOF){
        head = createList(n);
        //showList(head);
        printf("%d\n", solveJosephus(m));
        freeList();
    }

    return 0;
}

