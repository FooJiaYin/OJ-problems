#include <stdio.h>
#include <string.h>

int main(void) {

    int count_int = 0, count_float = 0;
    
    while (1) {
        char string[100] = {0};
        scanf("%s", &string);

        if (strlen(string) == 1 && string[0] == 'q') {
            break;
        }

        char result;
        
        float number_float;
        result = sscanf(string, "%f", &number_float);
        
        if(result != 0) {
            int number_int;
            sscanf(string, "%d", &number_int);

            if (number_int - number_float == 0) {
                count_int++;
            }
            else {
                count_float++;
            }
        }
    }
    printf("%d\n%d\n", count_float, count_int);
    return 0;
}