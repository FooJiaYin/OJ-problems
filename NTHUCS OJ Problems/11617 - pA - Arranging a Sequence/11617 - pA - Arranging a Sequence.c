#include<stdio.h>
long request[100020]={0}, frequency[200020]={0};

int main(void)
{
    long n, m, i;

    scanf("%ld %ld", &n, &m);

    for(i=0; i<m; i++)
    {
        scanf("%ld", &request[i]);
        frequency[request[i]]++;
    }

    for(i=m-1; i>=0; i--)
    {
        if(frequency[request[i]]>=1)        //print requested numbers
            printf("%ld\n", request[i]);
        if (frequency[request[i]]>1)        //repeated number won't be print again
            frequency[request[i]]=-1;
    }

    for(i=1; i<=n; i++)                     //print the rest numbers
        if(frequency[i]==0) printf("%ld\n",i);

    return 0;
}
