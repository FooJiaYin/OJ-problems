#include <stdio.h>

int position[110] = {0};
int type[110] = {0};
int size, count=0;

void display(void)
{
    int i, j;
    for (i=0; i<size; i++) {
	    for (j=0; j<size; j++) {
	        if (position[i]==j && type[i]==1) printf("@");
	        else if (position[i]==j) printf("^");
	        else printf("O");
	    }
	    printf("\n");
	}
	printf("\n");
}

int check(int row, int col)
{
    for(int i=0; i<row; i++) {
        if(type[row]==1){
            if(position[i]==col || row-i == col-position[i] || row-i == position[i]-col)
                return 0;
        }
        else {
            if(position[i]==col || (row-i == col-position[i] && type[i]==1) || (row-i == position[i]-col && type[i]==1)) return 0;
        }
    }
    if(type[row]==1) return 1;
    else return 2;
}

void place(int row)
{
	int j;
	if (row == size) {
		//display();
		count++;
	} else {
		for (j=0; j<size; j++) {
			if (check(row, j)) {
				position[row] = j;
				place(row+1);
			}
		}
	}
}

void control(int queen, int rook)
{
    if(queen+rook==0){
        place(0);
        return;
    }
    if(queen>0) {
        type[size-queen-rook] = 1, queen--;
        control(queen, rook);
        queen++;
    }
    if(rook>0) {
        type[size-queen-rook] = 0, rook--;
        control(queen, rook);
    }
}

int main(void)
{
    int queen, rook;
    scanf(" %d %d", &queen, &rook);
    size = queen+rook;
	control(queen, rook);
	printf("%d\n", count);
	return 0;
}
