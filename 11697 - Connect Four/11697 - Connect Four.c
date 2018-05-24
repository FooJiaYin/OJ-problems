#include <stdio.h>

char board[6][7];

void show_board(){
        int i, j;
        for( i = 0 ; i < 6 ; i++ ){
                for( j = 0 ; j < 7 ; j++ ){
                        printf( "%c", board[i][j] );
                }
                printf("\n");
        }
}

int main(){

        int i, j;
        int n, col, row;
        int win = 0;
        char color;

        // Initial
        for( i = 0 ; i < 6 ; i++ )
                for( j = 0 ; j < 7 ; j++ )
                        board[i][j] = '-';

        // Get moves
        scanf( "%d", &n );
        while( n-- ){
                getchar();
                scanf( "%d %c", &col, &color );
                // Put the disk
                col--; // Input is 1 ~ 7, but index is 0 ~ 6
		// Fall to the bottom
                for( row = 5 ; row >= 0 && board[row][col] != '-' ; --row );
                board[row][col] = color;
        }

        // check result
	/* Please insert your code here */
        for(row=0; row<6; row++)
        {
            for(col=0; col<7; col++)
                if(board[row][col]!='-')
                {
                    int a,b,c,d;
                    color = board[row][col];
                    for(a=0; row+a<=6 && board[row+a][col]==color; a++);
                    for(b=0; col+b<=7 && board[row][col+b]==color; b++);
                    for(c=0; row+c<=6 && col+c<=7 && board[row+c][col+c]==color; c++);
                    for(d=0; row+d<=6 && col-d>=0 && board[row+d][col-d]==color; d++);
                    if(a>=4 || b>=4 || c>=4 || d>=4)
                    {
                        win = 1;
                        break;
                    }
                }
            if(win) break;
        }


        if( win )
                printf("%c win\n", color);
        else
                printf( "No result\n" );
        show_board();

        return 0;

}
