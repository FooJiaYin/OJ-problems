#include<stdio.h>

int main(void)
{
    int number[9]={0}, visit[9]={0}, i;

    scanf("%d %d %d %d %d %d %d %d %d", &number[0], &number[1], &number[2], &number[3], &number[4], &number[5], &number[6], &number[7], &number[8]);

    visit[0] = number[0];

    for(i=1; i<9 && visit[i-1]>1; i++)
    {
        visit[i] = number[visit[i-1]-1];
    }

    printf("%d\n", visit[0]+visit[1]+visit[2]+visit[3]+visit[4]+visit[5]+visit[6]+visit[7]+visit[8]);
}
