#include<stdio.h>

int main(void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int i, j, k, n, stick[1010]={0}, get=0;
        scanf("%d", &n);

        for(i=0; i<n; i++)
            scanf("%d", &stick[i]);

        for(i=0; i<n; i++)
            for(j=i; j<n; j++)
                if(stick[i]<stick[j])
                {
                    int temp;
                    temp = stick[i];
                    stick[i] = stick[j];
                    stick[j] = temp;
                }

        for(i=0; i<n && get==0; i++)
            for(j=i+1; j<n && get==0; j++)
                for(k=j+1; k<n; k++)
                    if (stick[i]<stick[j]+stick[k])
                    {
                        get = 1;
                        break;
                    }

        if(get) printf("%d\n", stick[i-1]+stick[j-1]+stick[k]); //i-1 and j-1 for i++ and j++ in the loop just now
        else printf("-1\n");
    }

    return 0;
}

