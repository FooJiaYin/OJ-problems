#include <stdio.h>
#include <string.h>

int main(void) {

    int stop = 0;
    int first = 1;
    int offset = 0;

    scanf("%d", &offset);
    
    while (1) {
        char string[500] = {0};

        if (scanf("%s", &string) == EOF) {
            break;
        }

        for (int i = 0; i < strlen(string); i++) {
            if (string[i] >= 'A' && string[i] <= 'Z') {
                string[i] = 'A' + (string[i] - 'A' - offset%26 + 26) % 26 ;
            } 
            else if (string[i] >= 'a' && string[i] <= 'z')  {
                string[i] = 'a' + (string[i] - 'a' - offset%26 + 26) % 26 ;
            }
        }

        if (first == 1) {
            first = 0;
            printf("%s", string);
        } else {
            printf(" %s", string);
        }
    }
    
    return 0;
}