#include<stdio.h>
#include<string.h>

int main(void)
{
    int i, j, k, n=0;
    int N;
    char subs[500][15]={0}, count[500]={0};
    scanf("%d", &N);

    /* Find longest substring */
    while(N--)
    {
        char string[15];
        scanf("%s", string);

        int length=0;
        for(i=0; i<strlen(string); i++)
        {
            for(j=i; j<strlen(string) && string[j+1]>=string[j]; j++);
            if(j-i>=length)
            {
                if(j-i==length) n++;
                length = j-i;
                for(j=i; j<strlen(string) && string[j+1]>=string[j]; j++)
                    subs[n][j-i]=string[j], subs[n][j-i+1]=string[j+1];
            }
            if(length==0) subs[n][0]=string[i]; //longest substring length = 1;
        }

        n++;
    }
    /*for(i=0; i<=n; i++)
        if(strlen(subs[i])>0) printf("%s\n", subs[i]);*/

    /* Count the frequency */
    for(i=0; i<=n; i++)
        for(j=i+1; j<=n; j++)
            if(strcmp(subs[i], subs[j])==0) count[j]++, count[i]=-1;

    for(i=0; i<=n; i++)
        if(strlen(subs[i])>0 && count[i]>=0)
        {
            count[i]++;
            // printf("%s %d\n", subs[i], count[i]);
        }

    /* Sorting */
    int temp;
    char temp_string[15]={0};
    for(i=0; i<=n; i++)
        for(j=i; j<=n; j++)
            if(count[i]<count[j]||(count[i]==count[j]&&strcmp(subs[i], subs[j])>0))
            {
                temp = count[i];
                count[i] = count[j];
                count[j] = temp;
                strcpy(temp_string, subs[i]);
                strcpy(subs[i], subs[j]);
                strcpy(subs[j], temp_string);
            }

    for(i=0; i<=n; i++)
        if(count[i]>=0 && strlen(subs[i])>0) printf("%s %d\n", subs[i], count[i]);


    return 0;
}
