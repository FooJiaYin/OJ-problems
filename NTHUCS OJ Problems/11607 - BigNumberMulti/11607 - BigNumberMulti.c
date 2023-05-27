#include<stdio.h>
#include<string.h>

int main(void)
{
    int T;

    scanf("%d", &T);
    const int t=T;

    for(T=0; T<t; T++)
    {
        int ans[4002]={0}, i, j, length_a, length_b;
        char a[4002]={0}, b[4002]={0};

        scanf("%s %s", &a, &b);
        length_a = strlen(a);
        length_b = strlen(b);

        for(i=0; i<length_a; i++)
            a[i]-='0';
        for(i=0; i<length_b; i++)
            b[i]-='0';

        for(i=length_b-1; i>=0; i--)
        {
            for(j=i; j>=0; j--)
                ans[i] += a[j] * b[i-j-1];
        }

        for(i=length_a+length_b-1; i>=length_b; i--)
        {
            for(j=length_b-1; j>=i-1-length_b; j--)
                ans[i] += b[j] * a[i-j-1];
        }

        for(i=length_a+length_b-1; i>=0; i--)
        {
            ans[i-1]+=ans[i]/10;
            ans[i]=ans[i]%10;
        }

        for(i=0; i<length_a+length_b; i++)
            printf("%d", ans[i]);
        printf("\n");
    }

    return 0;
}
