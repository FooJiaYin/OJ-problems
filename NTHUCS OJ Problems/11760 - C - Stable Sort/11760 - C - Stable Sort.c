#include <stdio.h>
#include <stdlib.h>

typedef struct _data {
    char name[110];
    int score;
} Data;

void printList(Data** ptr, long N)
{
    long i;
    for(i=0; i<N; i++) {
        printf("%s %d\n", ptr[i]->name, ptr[i]->score);
    }
}

int main(void)
{
    long N, i, j;
    scanf("%ld", &N);

    Data **list = (Data**)malloc(sizeof(Data*)*N);
    Data **sort = (Data**)malloc(sizeof(Data*)*N);

    for(i=0; i<N; i++) {
        list[i] = (Data*)malloc(sizeof(Data));
        scanf("%s %d", list[i]->name, &list[i]->score);
        sort[i] = list[i];
    }

    for(i=0; i<N-1; i++){
        for(j=0; j<N-i-1; j++){
            if(sort[j]->score < sort[j+1]->score) {
                Data *temp = sort[j];
                sort[j] = sort[j+1];
                sort[j+1] = temp;
            }
        }
    }

    printList(sort, N);
    return 0;
}
