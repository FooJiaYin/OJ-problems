#include <stdio.h>

int main(void)
{
    int M, N, target;
    scanf(" %d %d %d", &M, &N, &target);
    int i=1, row=1, col=1, layer=1;
    while(i<target){
        while(col<N && i<target) col++, i++;
        N--;
        while(row<M && i<target) row++, i++;
        M--;
        while(col>layer && i<target) col--, i++;
        layer++;
        while(row>layer && i<target) row--, i++;
    }
    printf("%d %d\n", row, col);
    return 0;
}
