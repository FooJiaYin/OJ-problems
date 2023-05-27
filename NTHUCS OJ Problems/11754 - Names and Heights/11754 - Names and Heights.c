#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int compare_str(const void *a, const void *b) {
    char **va = (char **)a;
    char **vb = (char **)b;
    return strcmp(*va, *vb);
}

int compare_int(const void *a, const void *b) {
    int *va = (int *)a;
    int *vb = (int *)b;
    return *va - *vb;
}

int main(void) {
    char name[85][20]={0};
    char *name_sort[85];
    int height[85]={0};

    int N, i;
    scanf("%d", &N);

    for(i=0; i<N; i++)  {
        scanf("%s", name[i]);
        name_sort[i] = name[i];
    }
    for(i=0; i<N; i++)  {
        scanf("%d", &height[i]);
    }

    qsort(name_sort, N, sizeof(char*), compare_str);
    qsort(height, N, sizeof(int), compare_int);

    for(i=0; i<N; i++) {
        printf("%s %d\n", name_sort[i], height[i]);
    }

    return 0;
}
