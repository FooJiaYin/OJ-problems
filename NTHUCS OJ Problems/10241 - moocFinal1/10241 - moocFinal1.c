#include <stdio.h>

int value[7] = {0};
int number[7] = {0};

void showResult(int type) {
    int i;
    printf("(%d", number[0]);
    for (i=1; i<type ;i++) {
        printf(",%d", number[i]);
    }
    printf(")\n");

    return;
}

void change(int amount, int smallest, int type) {
    if(smallest>=type||amount<0) return;
    else if(amount==0) showResult(type);
    else if(amount>0) {
        change(amount, smallest+1, type);
        number[smallest]++;
        change(amount-value[smallest], smallest, type);
        number[smallest]--;
    }
}

int main(void)
{
    int type, amount;
    scanf("%d", &type);
    for(int i=0; i<type; i++)
        scanf("%d", &value[i]);
    scanf("%d", &amount);

    change(amount, 0, type);

    return 0;
}
