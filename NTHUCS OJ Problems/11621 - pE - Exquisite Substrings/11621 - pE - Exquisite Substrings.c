#include<stdio.h>
#include<string.h>

int main (void)
{
    char string[2020];

    while(scanf("%s", string) != EOF)
    {
        int n, i, count=0;

        /* Odd */
        for(n=1 ; n<strlen(string)-1 ; n++)
        {
            for(i=1 ; n-i>=0 && n+i<strlen(string) ; i++)
            {
                if(string[n-i]==string[n+i]) count++;
                else break;
            }
        }

        /* Even */
        for(n=1 ; n<strlen(string) ; n++)
        {
            for(i=1 ; n-i>=0 && n+i-1<strlen(string) ; i++)
            {
                if(string[n-i]==string[n+i-1]) count++;
                else break;
            }
        }
        printf("%d\n", count);
    }

    return 0;
}
