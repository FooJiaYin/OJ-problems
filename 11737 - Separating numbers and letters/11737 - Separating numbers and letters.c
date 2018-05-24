#include <stdio.h>
#include <string.h>
#include <ctype.h>

char input[1000010]={0};

int main(void)
{
    char test = getchar();
    while(test != EOF) {
        ungetc(test, stdin);
        fgets(input, 1000000, stdin);

        int total=0, num=0;
        char *token;
        token = strtok(input, " ");
        while(token != NULL) {
            if(isdigit(*token)) {
                sscanf(token, "%d", &num);
                total += num;
            }
            token = strtok(NULL, " ");
        }
        printf("%d\n", total);
        test = getchar();
    }
}
