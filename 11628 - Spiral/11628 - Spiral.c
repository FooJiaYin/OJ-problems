#include<stdio.h>
int space[2500][2500]={0};

void Initialize(int N)
{
    int i,j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
            space[i][j]=0;
    }
}

void PrintSpace(int N)
{
    int i,j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            if(space[i][j]) printf("#");
            else printf(" ");
        }
        printf("\n");
    }
}

int main(void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int N;
        scanf("%d", &N);

        Initialize(N);

        int direction=0, steps=N+1;
        int i=0, j=-1, n;

        while(steps--)
        {
            for(n=0; n<steps; n++)
            {
                if(direction==0) j++; 	//walk right
                else if(direction==1) i++; 	//walk down
                else if(direction==2) j--; 	//walk left
                else i--; 			//walk up
                space[i][j]=1;
            }
            direction = (direction+1)%4;
        }

        PrintSpace(N);
    }
    return 0;
}
