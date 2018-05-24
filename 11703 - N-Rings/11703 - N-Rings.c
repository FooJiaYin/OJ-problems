#include<stdio.h>

void in(int);

void out(int n){
    // take off the first n rings
    if(n)
    {
        out(n-2);
        printf("Move ring %d out\n", n);
        in(n-2);
        out(n-1);
    }
}

void in(int n){     //hanoi
    //put on the first n rings
    if(n)
    {
        in(n-1);
        out(n-2);
        printf("Move ring %d in\n", n);
        in(n-2);
    }
}

int n;

int main(){

    scanf("%d",&n);

    out(n);

    return 0;

}
