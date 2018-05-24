#include<stdio.h>
#include<stdlib.h>
int prime(int n);
/*找到第n個質數*/
int main()
{
 int a;
 scanf("%d",&a);
 printf("%d\n",prime(a));
 system("pause");
 return 0;
}

int prime(int n)
{
    int i=1,j,k;
    /* 找到一個質數則i+1,j是被除數,k是除數,函數設計會少算2所以把i初值設1*/
    /*do
    {*/
    for(j=2;i<=n;j++)
    {
            for(k=2; k<j && j%k!=0; k++);
            if(j==k)
                i++;
    }
   /* }while(i<n);*/
    return k;
}
