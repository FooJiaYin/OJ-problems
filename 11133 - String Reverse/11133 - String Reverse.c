#include<stdio.h>
#include<string.h>

int main (void)
{
    char string[1000]={0};
    int i, scan;

    while(scan>0)
    {

        scan = scanf("%s", &string);
        if (scan<1) break;

        for(i=strlen(string)-1; i>=0; i--)
            printf("%c", string[i]);
        printf("\n");
    }

    return 0;
}

