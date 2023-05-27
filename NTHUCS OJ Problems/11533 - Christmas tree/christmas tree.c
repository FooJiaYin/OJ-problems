#include<stdio.h>

int main(void)
{
    int level, width, height,i, space=0, leaf, wood;

    scanf("%d %d %d",&level, &width, &height);

    /*cap*/
    for(i=1;i<=level;i++)
    {
        if(level*2-1 < width)
            space = (width-(level*2-1))/2;

        for(space += level-i;space>0; space--)
                printf(" ");

        for(leaf = 2*i - 1;leaf>0;leaf--)
            printf("*");

        printf("\n");
    }

    /*trunk*/
    for (i=1;i<=height;i++)
    {
        if(level*2-1 > width)
        {
            for (space = ((level*2-1)-width)/2; space>0; space--)
                printf(" ");
        }

        for(wood=width;wood>0;wood--)
            printf("*");

        printf("\n");
    }

    return 0;
}
