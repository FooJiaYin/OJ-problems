#include<stdio.h>

int main(void)
{
    int T, A, B, i, t;
    char card[5], card1, card2;

    scanf("%d", &T);
    for(t=T;t>0;t--)
    {
        /* Scan cards */
        card[0]=getchar();
        for(i=0; i<5; i++)
        {
            card[i]=getchar();
            while (card[i]==' '||card[i]=='\n'||card[i]=='1')
                card[i]=getchar();
        }

        /* Find the 1st pair of distinct cards */
        for(i=1, A=1; card[i]==card[0]; A++, i++);
        card1 = card[0];
        card2 = card[i];

        /* Check if the following card are same with the first 2 cards */
        for(B=1,i++;i<5;i++)
        {
            if (card[i]==card1) A++;
            if (card[i]==card2) B++;
        }

        if (A==2 && B==3 || A==3 && B==2)
            printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
