#include<stdio.h>
#include<string.h>

char string[1000020]={0};
long position[65][1000020]={0};

long CountAlphabet(int alphabet)
{
    int i;
    long count=0;
    for(i=0; i<strlen(string); i++)
    {
        if(string[i]-'A'==alphabet)
        {
            position[alphabet][count]=i;
            count++;
        }
    }
    return count;
}

void PrintPosition(int alphabet, long count)
{
    int i;
    printf("%c: ", alphabet+'A');
    for(i=0; i<count; i++)
    {
        if(i<count-1) printf("%d ", position[alphabet][i]);
        else printf("%d\n", position[alphabet][count-1]);
    }
    return;
}

int main(void)
{
    scanf("%s", string);

    int i,j,alphabet;
    long count;

    for(alphabet=0; alphabet<='Z'-'A'; alphabet++)
    {
        count = CountAlphabet(alphabet);
        if(count>0) PrintPosition(alphabet, count);
    }

    for(alphabet='a'-'A'; alphabet<='z'-'A'; alphabet++)
    {
        count = CountAlphabet(alphabet);
        if(count>0) PrintPosition(alphabet, count);
    }

    return 0;
}
