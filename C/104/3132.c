#include <stdio.h>
#include <string.h>

int main(void) {

    char char_map[256][9] = {
        "1000001," ,"1000010,", "1000011,",
        "1000100," ,"1000101,", "1000110,",
        "1000111," ,"1001000,", "1001001,",
        "1001010," ,"1001011,", "1001100,",
        "1001101," ,"1001110,", "1001111,",
        "1010000," ,"1010001,", "1010010,",
        "1010011," ,"1010100,", "1010101,",
        "1010110," ,"1010111,", "1011000,",
        "1011001," ,"1011010,"
    };
    int stop = 0, names = 1;
    char c;
    
    while (names) {
        char string[100] = {0};
        scanf("%s", &string);

        if (sscanf(string, "%d", &stop) && stop == -1) {
            break;
        }
        else if (strlen(string) == 1 && string[0] == '+') {
            char instruction[100] = {0};
            scanf(" %c", &c);
            scanf("%s", &instruction);
            int i = 0;
            for (i = 0; i < strlen(instruction); i++) {
                char_map[c][i] = instruction[i];
            }
            char_map[c][i] = ',';
            // printf("%c: %s\n", c, char_map[c]);
        }
        else {
            for (int i = 0; i < strlen(string); i++) {
                c = string[i];

                if (c >= 'a' && c <= 'z') {
                    printf(char_map[c - 'a']);
                } 
                else if (c >= 'A' && c <= 'Z')  {
                    printf(char_map[c - 'A']);
                }
                else {
                    printf(char_map[c]);
                }
            }
            printf("\n");
        }
    } 
    return 0;
}