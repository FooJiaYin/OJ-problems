#include<stdio.h>

int factory[1010][1010]={0};

int main(void)
{
    int N, M, K, instruction, wrong=0;
    int x=0, y=0;

    scanf("%d %d", &N, &M);
    scanf("%d", &K);

    factory[0][0]=1;

    while(K--)
    {
        scanf("%d", &instruction);
        int i=x, j=y;

        /* Check */
        if(instruction==1) i--;         //up
        else if(instruction==2) i++;    //down
        else if(instruction==3) j--;    //left
        else j++;                       //right

        if(i>=0 && i<N && j>=0 && j<M) //okay
        {
            x=i, y=j; //walk
            factory[x][y]++;
        }
        else wrong++;
    }

    printf("%d\n", wrong);

    for(x=0; x<N; x++)
        for(y=0; y<M; y++)
        {
            if(y<M-1) printf("%d ", factory[x][y]);
            else printf("%d\n", factory[x][y]);
        }

    return 0;
}
