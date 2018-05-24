#include <stdio.h>

void flow(long population[6], double entry[6][6], int n)
{
    int i, j;
    long temp[6];
    for(i=0; i<n; i++){
        temp[i] = population[i];
    }
    for(i=0; i<n; i++){
        population[i] = 0;
        for(j=0; j<n; j++){
            population[i] += temp[j]*entry[i][j];
        }
    }
}

/*void Print_population(long population[6], int n)
{
    int i;
    for(i=0; i<n; i++){
        printf("%ld ", population[i]);
    }
    printf("\n");
}*/

int main(void)
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, i, j;
        scanf("%d", &n);

        double entry[6][6]={0};
        for(i=0; i<n; i++){
            for(j=0; j<n; j++) {
                scanf("%lf", &entry[i][j]);
            }
        }

        long population[6]={0}, p;
        for(i=0; i<n; i++){
            scanf("%ld", &population[i]);
        }
        scanf("%ld", &p);

        for(i=0; i<=1000;i++) {
            //Print_population(population, n);
            if(population[0]<=p) {
                printf("%d\n", i);
                break;
            }

            long temp = population[0];
            flow(population, entry, n);

            if(temp<=population[0]){
                printf("Never\n");
                break;
            }
        }
    }
    return 0;
}
