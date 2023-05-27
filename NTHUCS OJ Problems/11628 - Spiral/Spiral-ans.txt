#include <stdio.h>
char map[5000][5000]={0};
int main()
{
	int direction[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

	int T, N;
	int r, c;
	int Ne, idx;
	int i=0, j=0, k=0;

	scanf("%d",&T);

	while(i<T){
		scanf("%d",&N);

		Ne=N;
		idx=0;
		r=0, c=-1;

		// store '#' to map array
		while(Ne>0){
            j=0;
			while(j<Ne){
				r=r+direction[idx][0];
				c=c+direction[idx][1];
				map[r][c]='#';
				j++;
			}
            idx = (idx+1)%4;
			Ne--;
		}

		// draw outcome
		for(j=0;j<N;j++){
			for(k=0;k<N;k++){
				if(map[j][k]!='#'){
					map[j][k]=' ';
					printf("%c", map[j][k]);
				}
				else{
					printf("%c", map[j][k]);
					map[j][k]=' ';
				}
			}
			printf("\n");
		}

		// next T loop
		i++;
	}
}
