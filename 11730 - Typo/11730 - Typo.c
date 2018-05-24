#include <stdio.h>
#include <string.h>
char s[200020], t[200020];

int main(void)
{
    int N;
    scanf("%d", &N);

    while(N--)
    {
        int typo=0;
        scanf("%s %s", &s, &t);
        if(strcmp(s,t))
        {
            int i;
            for(i=0; s[i]==t[i]&&(i<strlen(s)||i<strlen(t)); i++); //skip the same part

            /*types one wrong character*/
            if(strlen(s)==strlen(t)&&!strcmp(s+i+1,t+i+1)) typo = 1;
            /*switches two different adjacent characters*/
            else if(strlen(s)==strlen(t)&&!strcmp(s+i+2,t+i+2)&&s[i]==t[i+1]&&s[i+1]==t[i]) typo = 1;
            /*forgets to type one character*/
            else if(strlen(s)==strlen(t)+1&&!strcmp(s+i+1,t+i)) typo = 1;
            /*types one more character*/
            else if(strlen(s)==strlen(t)-1&&!strcmp(s+i,t+i+1)) typo = 1;
        }
        if(typo) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
