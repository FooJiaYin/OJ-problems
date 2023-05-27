#include <stdio.h>
#include <string.h>
char string[200050];

int main(void)
{
    long long occurance[30]={0};
    long long count=0;

    scanf("%s", &string);
    int len = strlen(string);

    int i, j;
    for(i=0; i<len; i++)
        occurance[string[i]-'a']++;

    for(i=0; i<26; i++)
        for(j=i+1; j<26; j++)
            count += occurance[i]*occurance[j];

    printf("%lld\n", count+1);

    return 0;
}
