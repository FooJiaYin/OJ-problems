#include <stdio.h>
#include <math.h>

int main(void)
{
    int i, j, N, max=0, bin[21]={0};
    unsigned long SUM=0;
    scanf("%d", &N);

    for(i=0; i<N; i++)
    {
        unsigned input;
        scanf("%u", &input);
        for(j=0; input>0; j++, input/=2) //convert input to binary
        {
            bin[j] += input%2;      //add binary to places
        }
        if(j > max) max = j;        //record the longest binary places
    }

    for(i=0; i<max; i++)    //for every places
    {
        if(bin[i]*2>N)      //more ones than zeros
            SUM += (N-bin[i])* pow(2,i);
        else
            SUM += bin[i] * pow(2,i);
    }
    printf("%lu\n", SUM);

    return 0;
}
