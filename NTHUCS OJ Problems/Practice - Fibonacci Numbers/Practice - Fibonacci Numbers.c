#include <stdio.h>
int fib_loop(int n){
    int i,fib1=0, fib2=0,fib=0;
    for(fib2=1,i=1;i<=n;i++)
    {
        fib1=fib2;
        fib2=fib;
        fib=fib2+fib1;
    }
    return fib;
}

int fib(int n)
{
    if(n==0||n==1) return n;
    return fib(n-1)+fib(n-2);
}

int table[1000];
int fib_table(int n)
{
    if (table[n]!=0) return table[n];
    if(n==1||n==0) return n;
    return fib_table(n-1)+fib_table(n-2);
}

int main(void){
    int n;
    scanf("%d", &n);
    printf("%d", fib(n));
    return 0;
}

