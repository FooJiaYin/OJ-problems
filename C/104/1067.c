#include <stdio.h>

int main(void) {
    char string[100] = {0};
    int numbers = 0, alphabets = 0, vowels = 0, consonants = 0;

    scanf("%s", &string);

    for (int i = 0; i < strlen(string); i++) {
        char c = string[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            alphabets++;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                vowels++;
            }
            else {
                consonants++;
            }
        } else if (c >='0' && c <= '9') {
            numbers++;
        }
    }
    printf("%d %d %d %d\n", numbers, alphabets, vowels, consonants);
    return 0;
}