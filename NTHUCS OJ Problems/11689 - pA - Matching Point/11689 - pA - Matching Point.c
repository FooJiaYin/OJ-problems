#include<stdio.h>
#include<string.h>
char s[25],t[25];
int len_s, len_t, count;

void match(int i,int j)
{
    //printf("i=%d j=%d count=%d\n", i,j,count);
    if(j==len_t)
        count++;
    for(;i<len_s; i++)
    {
        if(j<len_t)
        {
            if(s[i]==t[j])
                match(i+1, j+1);
        }
    }
}

int main(void)
{
    while(scanf("%s", &s)!=EOF)
    {
        scanf("%s", &t);
        count = 0;              //remember!!
        len_s = strlen(s);
        len_t = strlen(t);
        match(0,0);
        printf("%d\n", count);
    }
    return 0;
}
