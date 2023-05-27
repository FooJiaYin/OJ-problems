#include <stdio.h>
#include <string.h>

int main(void) {

    int N = 0, count = 0;
    int numbers[501] = {0};
    int xor[501] = {0};

    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &numbers[i]); 
        if (i == 0) xor[i] = numbers[i];
        else xor[i] = xor[i-1] ^ numbers[i];
    } 

    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            for (int k = j; k < N; k++) {
                int l = xor[j-1] ^ xor[i-1];
                int r = xor[k] ^ xor[j-1];
                if (l == r) {
                    count++;
                    printf("(i: %d,j: %d,k: %d)\n", i, j, k);
                }
            }
        }
    }
    printf("%d", count);
    
    return 0;
}