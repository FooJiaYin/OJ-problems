#include <stdio.h>
#include <string.h>

int main(void)
{
    char test = getchar();
    while(test!=EOF)
    {
        char numA[1010]={0}, numB[1010]={0};
        int carries=0;
        ungetc(test, stdin);
        scanf(" %s %s", numA, numB);

        int lenA = strlen(numA);
        int lenB = strlen(numB);

        for(int prev=0, i=1; lenB-i>=0 || lenA-i>=0; i++) {
            int sum;
            if(lenB-i>=0 && lenA-i>=0)
                sum = numA[lenA-i]-'0' + numB[lenB-i]-'0';
            else if(lenA-i>=0)
                sum = numA[lenA-i]-'0';
            else
                sum = numB[lenB-i]-'0';

            if(sum>9||(sum==9&&prev==1)) carries++, prev = 1;
            else prev = 0;
        }
        printf("%d\n", carries);
        test = getchar();
        if(test=='\n')test = getchar();
    }
    return 0;
}
