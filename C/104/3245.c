#include <stdio.h>
#include <string.h>

int main(void) {

    int N = 0;
    char operators[1000] = {'+'};
    unsigned int numbers[1000] = {0};

    scanf("%d", &N);
    scanf("%d", &numbers[0]);
    
    for (int i = 1; i < N; i++) {
        scanf("%c%d", &operators[i], &numbers[i]);    
        if (operators[i] == '*') {
            numbers[i] *= numbers[i-1];
            numbers[i-1] = 0;
            operators[i] = operators[i-1];
        }
    }
    for (int i = 1; i < N; i++) {
        if (operators[i] == '+') {
            numbers[i] += numbers[i-1];
        }
        else {
            numbers[i] = numbers[i-1] - numbers[i];
        }
    }

    printf("%d", numbers[N-1]);
    
    return 0;
}