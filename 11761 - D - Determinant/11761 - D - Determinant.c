#include <stdio.h>
int matrix[9][9]={0}, col[9]={0}, size;

long long det(int n)
{
    if(n==0) return 1;
    else {
        long long ans=0, flag=1;
        for(int i=0; i<size; i++)
        {
            if(col[i]==0){
                col[i] = 1;
                ans += flag*matrix[size-n][i]*det(n-1);
                col[i] = 0, flag = -flag;
            }
        }
        return ans;
    }
}

int main(void)
{
    scanf("%d", &size);

    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
            scanf("%d", &matrix[i][j]);

    printf("%lld\n", det(size));

    return 0;
}
