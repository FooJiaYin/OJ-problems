#include <stdio.h>
#include <string.h>

int main(void)
{
    char test;
    while(scanf("%c", &test)!=EOF) //scan first char
    {
        char input[110][110]={0};
        ungetc(test, stdin);

        int i;
        for(i=0;1; i++)
        {
            do{
                test = getchar();
            } while(test==' ');     //skip spaces

            if(test=='\n') break; 	//contain no words
            else
            {
                ungetc(test,stdin);
                scanf(" %s", input[i]);
            }
        }
        for(i--; i>0; i--)
            printf("%s ", input[i]);
        printf("%s\n", input[0]);
    }

    return 0;
}
