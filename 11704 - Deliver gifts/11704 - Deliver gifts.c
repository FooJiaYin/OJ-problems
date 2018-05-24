#include <stdio.h>
int value[25]={0};
int N, count=1; //initialization for multiplication

void sort() //bubble sort
{
    int i, j;
    for(i=N; i>=0; i--)
        for(j=0; j<=i; j++)
        {
            if(value[j-1]>value[j])
            {
                int temp;
                temp = value[j-1];
                value[j-1] = value[j];
                value[j] = temp;
            }
        }
}

int main(void)
{
    scanf("%d", &N);

    int i;
    for(i=1; i<=N; i++)
        scanf("%d", &value[i]);

    sort();

    for(i=1; i<=N; i++)
    {
        int num;                //number of people able to receive the gift
        num = value[i]-i+1;     //-i+1: number of people already had a gift
        if(num>0) count *= num;
        else count = 0;         //No way to deliver gift to every people
    }
    printf("%d\n", count);

    return 0;
}
