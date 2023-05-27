#include<stdio.h>
#include<string.h>

char s[200020];

int main(void)
{
    while(scanf("%s", &s)!=EOF)
    {
        long i, j, k, l, next=0;
        long long lucky;

        l = strlen(s);
        lucky = l*(l+1)/2;

        while(next<strlen(s))
        {
            for(i=next; s[i]!='9' && i<strlen(s); i++);
            l = i-next;
            lucky -= l*(l+1)/2;
            next = i+1;
        }
        printf("%lld\n", lucky);
    }
    return 0;
}
