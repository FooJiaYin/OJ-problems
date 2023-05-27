#include <stdio.h>
#include <string.h>

int main(void) {

    int stop = 0;
    int first = 1;
    
    while (1) {
        char string[100] = {0};
        scanf("%s", &string);

        if (sscanf(string, "%d", &stop) && stop == -1) {
            break;
        }

        for (int i = 0; i < strlen(string); i++) {
            if (string[i] >= 'A' && string[i] <= 'Z') {
                string[i] = 'a' + (string[i] - 'A' + 23) % 26 ;
            } 
            else if (string[i] >= 'a' && string[i] <= 'z')  {
                string[i] = 'a' + (string[i] - 'a' + 23) % 26 ;
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