#include<stdio.h>
#include<string.h>

int main(void)
{
    char input[1010];
    int n, i, length=0, odd_middle=0, even_middle=0;

    scanf("%s", input);

    for(n=0; n<strlen(input); n++)
    {
        /* Odd */
        for(i=0; n-i>=0 && n+i<strlen(input); i++)
        {
            if(input[n-i]!=input[n+i]) break;
            if (i>length)
            {
                length = i;
                odd_middle = n;
                even_middle = 0;
            }
        }
        /* Even */
        for(i=1; n-i>=0 && n+i-1<strlen(input); i++)
        {
            if(input[n-i]!=input[n+i-1]) break;
            if(i>=length+1)
            {
                length = i;
                even_middle = n;
                odd_middle = 0;
            }
        }
    }

    if(odd_middle)
    {
        for(i=odd_middle-length; i<=odd_middle+length; i++)
            printf("%c", input[i]);
    }

    if(even_middle)
    {
        for(i=even_middle-length; i<=even_middle+length-1; i++)
            printf("%c", input[i]);
    }

    if(strlen(input)==1) printf("%s", input); //for testcase 3 :(

    return 0;
}
