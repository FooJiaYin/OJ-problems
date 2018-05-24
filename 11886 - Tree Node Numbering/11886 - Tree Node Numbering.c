#include <stdio.h>

int height=0, child=0;

void traversal(int id, int level)
{
    if(level==height) return;
    printf("%d ", id);
    for(int i=0; i<child; i++){
        traversal(id*child+1+i, level+1);
    }
}

int main(void)
{
    scanf("%d %d", &height, &child);
    traversal(0, 0);
    printf("\n");
    return 0;
}
