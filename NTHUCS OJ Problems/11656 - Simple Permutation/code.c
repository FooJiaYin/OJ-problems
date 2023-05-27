#include <stdio.h>

#include "function.h"

// Not "11656.h" !!

void print(int level, int n){

    // add your code here!
    if(level>n) return;
    if(level<n) printf("%d ", level);
    print(level+1, n);
    if(level>1) printf("%d ", level);
    if(level==1) printf("%d\n", level);
}
