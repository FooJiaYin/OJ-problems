#include <stdio.h>

#define MAXNC 5
int liters[MAXNC];
int solution[MAXNC];

void showResult(int n) {
    int i;

    printf("(%d", solution[0]);

    for (i=1; i<n ;i++) {
        printf(",%d", solution[i]);
    }

    printf(")\n");

    return;
}

void filling(int amount, int cur, int n) {
    if(cur>=n||amount<0) return;
    if(amount==0) showResult(n);
    else
    {
        solution[cur]++;
        filling(amount-liters[cur], cur, n);
        solution[cur]--;
        filling(amount, cur+1, n);
    }
}

int main(void) {
    int n, i;
    int water;

    scanf("%d", &n);

    for (i=0; i<n ;i++) {
        scanf("%d", &liters[i]);
    }

    scanf("%d", &water);

    filling(water, 0, n);

    return 0;
}
