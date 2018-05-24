#include<stdio.h>
#include<string.h>

char string[100020]={0};

int main(void)
{
    while(scanf("%s", string) != EOF)
    {
        int i,j;
        for(i=0, j=strlen(string)-1; i<=j-1; i++, j--)
        {
            if(string[i]!=string[j])
            {
                printf("No\n");
                break;
            }
        }
        if(string[i]==string[j])
            printf("Yes\n");
    }
    return 0;
}
