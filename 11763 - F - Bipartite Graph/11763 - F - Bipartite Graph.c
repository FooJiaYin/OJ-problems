#include <stdio.h>
#include <stdlib.h>
int connection[1010][1010]={0}, color[1010]={0};
int n, bipartite=1;

void initialize()
{
    int i, j;
    for(i=1; i<=n; i++){
        color[i] = 0;
        for(j=1; j<=n; j++) {
            connection[i][j] = 0;
        }
    }
    color[1] = 1;
    bipartite = 1;
}

int main(void)
{
    int T;
    scanf("%d", &T);
    while(T--){
        initialize();

        int i, j, edges_no;
        scanf("%d %ld", &n, &edges_no);

        while(edges_no--){
            int pt1, pt2;
            scanf("%d %d", &pt1, &pt2);
            connection[pt1][pt2]++;
            connection[pt2][pt1]++;
        }

        for(i=1;i<=n && bipartite;i++){
            for(j=i+1;j<=n && bipartite;j++){
                if(connection[i][j]){
                    if(color[i]*color[j]==1) bipartite = 0;
                    else if(color[i]) color[j] = -color[i];
                    else if(color[j]) color[i] = -color[j];
                }
            }
        }

        if(bipartite) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
