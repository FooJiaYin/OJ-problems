#include <stdio.h>

int main(void) {
    char c;
    while ((c = getchar()) != EOF) {
        switch (c) {
            case '0': printf("O"); break;
            case '1': printf("I"); break;
            case '3': printf("E"); break;
            case '4': printf("A"); break;
            case '5': printf("S"); break;
            case '7': printf("T"); break;
            default: printf("%c", c);
        }
    }
    return 0;
}