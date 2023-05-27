#include <stdio.h>
#include <stdlib.h>

#define N 1010

typedef struct _vector {
    unsigned long dimension;
    int value;
} Vector;

int main(void)
{
    unsigned long dim_temp;
    int value_temp;
    long long total=0;
    Vector *vector[N]={0};
    int i, j;
    scanf("%ul", &dim_temp);
    scanf("%*c%d",&value_temp);
    for(i=0; (dim_temp!=0 || value_temp!=0) && i<N-1; i++){
        if(value_temp!=0) {
            vector[i] = malloc(sizeof(Vector));
            vector[i]->dimension = dim_temp;
            vector[i]->value = value_temp;
        }
        scanf(" %ul", &dim_temp);
        scanf("%*c%d",&value_temp);
    }
    scanf("%ul", &dim_temp);
    scanf("%*c%d",&value_temp);
    while(dim_temp!=0 || value_temp!=0){
        for(j=0; j<i; j++){
            if(dim_temp == vector[j]->dimension)
                total += vector[j]->value * value_temp;
        }
        scanf("%ul", &dim_temp);
        scanf("%*c%d",&value_temp);
    }
    printf("%ld\n", total);

    return 0;
}
