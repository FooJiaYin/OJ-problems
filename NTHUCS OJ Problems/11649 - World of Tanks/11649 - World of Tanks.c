#include <stdio.h>
#include <string.h>

#define EAST 0
#define SOUTH 1
#define WEST 2
#define NORTH 3

char map[100][100];
char actions[100]={};
int coin_amount = 0;

// tank's initial direction
char init_dir;
// tank's direction now
int dir_now;
// tank's center x and y
int center_x, center_y;

void decide_initial_direction()
{
    /// Decide tank's initial direction
    /// Using init_dir
    /// To determine dir_now
    switch(init_dir)
    {
        case 'N': dir_now = NORTH;
            break;
        case 'E': dir_now = EAST;
            break;
        case 'S': dir_now = SOUTH;
            break;
        case 'W': dir_now = WEST;
            break;
    }
}

void show_map(int row, int col)
{
    int i,j;
    for (i = 1; i <= row; i++){
        for (j = 1; j <= col; j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    return;
}

void take_a_step()
{
    //printf("x:%d y:%d\n", center_x, center_y);
    int i,j;
    if (dir_now == NORTH){
        /// Detect wall first
        if (map[center_x-2][center_y]=='#'){
            return;
        }
        /// And then detect hill
        else if (map[center_x-2][center_y-1]=='^'||map[center_x-2][center_y]=='^'||map[center_x-2][center_y+1]=='^') {
            return;
        }
        /// If there is no obstacle, take a step
        else {
            center_x--;
        }
    }
    else if (dir_now == SOUTH){
        /// Detect wall first
        if (map[center_x+2][center_y]=='#'){
            return;
        }
        /// And then detect hill
        else if (map[center_x+2][center_y-1]=='^'||map[center_x+2][center_y]=='^'||map[center_x+2][center_y+1]=='^') {
            return;
        }
        /// If there is no obstacle, take a step
        else {
            center_x++;
        }
    }
    else if (dir_now == EAST){
        /// Detect wall first
        if (map[center_x][center_y+2]=='#'){
            return;
        }
        /// And then detect hill
        else if (map[center_x-1][center_y+2]=='^'||map[center_x][center_y+2]=='^'||map[center_x+1][center_y+2]=='^') {
            return;
        }
        /// If there is no obstacle, take a step
        else {
            center_y++;
        }
    }
    else if (dir_now == WEST){
        /// Detect wall first
        if (map[center_x][center_y-2]=='#'){
            return;
        }
        /// And then detect hill
        else if (map[center_x-1][center_y-2]=='^'||map[center_x][center_y-2]=='^'||map[center_x+1][center_y-2]=='^') {
            return;
        }
        /// If there is no obstacle, take a step
        else {
            center_y--;
        }
    }
}

void pick_the_coins()
{
    int j, k;
    for (j = center_x - 1; j <= center_x + 1; j++){
        for (k = center_y - 1; k <= center_y + 1; k++){
            /// determine whether there are coins under the tank
            if (map[j][k]=='$')
            {
                coin_amount++;
                map[j][k] = '=';
            }
        }
    }
}

void turn(char action)
{
    /// Change direction depending on dir_now
    if (action == 'R') dir_now = (dir_now+1)%4;
    if (action == 'L') dir_now = (dir_now+3)%4;
}

int main()
{
    int i, j, k, rows, cols;
    int actions_number;
    int component = 0;

    /// Read problem's input
    scanf("%d %d %d %c", &rows, &cols, &actions_number, &init_dir);
    while (getchar() != '\n');
    for (i = 0; i < actions_number; i++){
        scanf("%c", &actions[i]);
    }

    /// Read map
    for (i = 1; i <= rows; i++){
        while (getchar() != '\n');
        for (j = 1; j <= cols; j++){
            scanf("%c", &map[i][j]);
            /// Find tank's center x and y
            if (((map[i][j]) == 'x') || ((map[i][j]) == 'o') || ((map[i][j]) == 'O')){
                component++;
                if (component == 5){
                    center_x = i;
                    center_y = j;
                }
            }
        }
    }

    decide_initial_direction();

    for (i = 0; i < actions_number; i++){
        if (actions[i] == 'F'){
            take_a_step();
            pick_the_coins();
        }
        else turn(actions[i]);
    }

    printf("%d\n", coin_amount);

    return 0;
}
