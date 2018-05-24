#include<stdio.h>
long grade[200020]={0};

int main(void)
{
    long n, i, largest=0, sum=0;
    scanf("%ld", &n);

    while(n--)
    {
        long input;
        scanf("%ld", &input);
        input += 100000;

        if(grade[input]==0)
        {
            if(input>largest) largest = input;
            grade[input]++;
        }
    }

    for(i=0; i<=largest; i++)
        sum += grade[i];

    printf("%ld\n", sum);

    return 0;
}
