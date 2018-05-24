#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int compare(const void *a, const void *b) {
    char *va = (char *)a;
    char *vb = (char *)b;
    return *va - *vb;
}
int main(void) {
    int N;
    scanf("%d", &N);
    while(N--) {
        char input[20];
        int num[15]={0}, seq=0;
        scanf("%s", input);

        qsort(input, strlen(input), sizeof(char), compare);

        int i;
        for(i=0; i<strlen(input); i++) {
            printf("%c", input[i]);
        }
        printf("\n");
    }
    return 0;
}
