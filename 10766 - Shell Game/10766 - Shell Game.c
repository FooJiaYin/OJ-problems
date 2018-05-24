#include<stdio.h>

int main(void)
{
    int ball[5]={0,1,2,3,4}, k, swap1, swap2, temp;

    scanf("%d", &k);

    for(k=k;k>0;k--)
    {
        scanf("%d %d", &swap1, &swap2);
        temp = ball[swap1];
        ball[swap1] = ball[swap2];
        ball[swap2] = temp;
    }

    printf("%d %d %d %d %d", ball[0], ball[1], ball[2], ball[3], ball[4]);

    return 0;
}
