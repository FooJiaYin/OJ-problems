#include<stdio.h>

int gcd(int a, int b)
{
    int i;
    if(a<=b)
        for(i=a; i>=0 && (a%i>0 || b%i>0); i--);
    else
        for(i=b; i>=0 && (a%i>0 || b%i>0); i--);
    return i;
}

int lcm(int a, int b)
{
    int i;
    if(a<=b)
        for(i=b; i%a>0 || i%b>0; i++);
    else
        for(i=a; i%a>0 || i%b>0; i++);
    return i;
}

int main(void)
{
    int a[3000]={0},b[3000]={0},no,i=0;

    scanf("%d",&no);

    while(i<no){
        scanf("%d",&a[i]);
        b[i]=a[i];
        i++;
    }

    for(i=0;i<no-1;i++)
    {
        a[i+1] = gcd(a[i],a[i+1]);
        b[i+1] = lcm(b[i],b[i+1]);
    }

    printf("%d %d",a[i],b[i]);

    return 0;
}

