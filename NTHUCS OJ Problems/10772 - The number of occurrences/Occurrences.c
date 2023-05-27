#include <stdio.h>
#include <string.h>

int main(void)
{
    char A[5]; //one for '\0'
    char B[9]; //for the current B string
    int n;
    int i,j;
    int bp; //bs for the current position in B
    int nc=0; //for the current matchings between A and some B
    int nmax=0;

    scanf("%s",A);
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%s",B);

        bp=0;
        nc=0;
        //to derive the number of occurrences for the current B string
        for(bp=0;bp<=strlen(B)-strlen(A);bp++){
            for(j=0;j<strlen(A);j++){
                if(B[bp+j]!=A[j]) break;
            }
            if(j==strlen(A)) nc++;//match
        }
        if(nc>nmax) nmax=nc;
    }

    printf("%d",nmax);

    return 0;
}
