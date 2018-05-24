#include<stdio.h>
#include<string.h>

int main(void)
{
    char str[4][10]={0};
    int i,j,k,print;

    scanf("%s %s %s", str[0], str[1], str[2]);
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
        {
            if(str[i][0]==str[j][strlen(str[j])-1])
                for(k=1; k<strlen(str[i]); k++)
                    str[j][strlen(str[j])] = str[i][k];
            if(strlen(str[j])==7) print=j;
        }
    printf("%s", str[print]);

    return 0;
}
