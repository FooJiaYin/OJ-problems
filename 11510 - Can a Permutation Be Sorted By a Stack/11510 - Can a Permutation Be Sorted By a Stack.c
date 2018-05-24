#include <stdio.h>

int main(void)
{
    char test = getchar();
    while(test!=EOF)
    {
        ungetc(test, stdin);
        int stack[1010]={0};
        int supply, level=0, now=1, input=0;
        scanf("%d", &supply);
        while(supply>0) {
            if(input!=now) scanf("%d", &input);
            /* Output */
            while(input==now) {
                now++, supply--;
                if(supply>0) scanf("%d", &input);
            }
            /* Pop */
            while(stack[level]==now) now++, level--;
            /* Push */
            if(input!=now && supply>0) stack[++level] = input, supply--;
        }
        if(level) printf("NO\n");
        else printf("YES\n");

        test = getchar();
        if(test=='\n')test = getchar();
    }
    return 0;
}
