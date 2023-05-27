#include <stdio.h>
#include <stdlib.h>
#include "function.h"


int main(){

    int n, m;

    while(scanf("%d", &n)!=EOF){
        head = createList(n);
        printf("%d\n", solveJosephus());
        freeList();
    }

    return 0;
}

