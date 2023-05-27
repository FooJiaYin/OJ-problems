#include<stdio.h>
int grade[30]={0};amount[30]={0};
int total;

void count(int* max, long m, int i, int n)
{
    if(i<n)
    {
        if(m==0) total++;

        else if(m>0)
        {
            count(max, m, i+1, n);
            amount[i]++;
            if(amount[i]<=max[grade[i]]) //not exceed total no of the grade
                count(max, m-grade[i], i, n);
            amount[i]--;
        }
    }
}

int main(void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, i, nv, input;
        long m;
        int max[2050]={0}; //to record the frequency of each grade
        scanf("%d %ld", &n, &m);
        for(i=0, nv=0; i<n; i++)
        {
            scanf("%d", &input);
            max[input]++;
            if(max[input]==1) //never appear before
                grade[nv++]=input; 
        }
        total = 0;
        count(max, m, 0, nv);
        printf("%d\n", total);
    }
    return 0;
}
