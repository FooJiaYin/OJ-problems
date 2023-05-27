#include <stdio.h>

int main(){
    int A[500][500];
    int ans = 0;

    int n = 0, i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &A[i][j]);
        }
    }

    for(i = 0; i < n; i+=2){
        for(j = 0; j < n; j+=2){
            int SUM;
            SUM = A[i][j] + A[i+1][j] + A[i][j+1] + A[i+1][j+1];
            if(SUM > ans) ans = SUM;
        }
    }

    printf("%d\n", ans);
    return 0;
}
