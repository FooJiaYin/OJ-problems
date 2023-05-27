#include <stdio.h>
#include <string.h>

int main(void) {
    char string[100] = {0};
    int count[26] = {0};

    scanf("%s", &string);

    for (int i = 0; i < strlen(string); i++) {
        char c = string[i];
        if (c >= 'A' && c <= 'Z') {
            count[c - 'A']++;
        } 
        else if (c >= 'a' && c <= 'z')  {
            count[c - 'a']++;
        }
    }
    for (int i = 0; i < 26; i++) {
        printf("%d\n", count[i]);
    }

    return 0;
}