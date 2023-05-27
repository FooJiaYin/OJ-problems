#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]) {
    char filename[30];
    FILE* fp;
    char area;
    int year;
    int month;
    int count[26][12] = {0};
    int isArea[26] = {0};
    char dummy[40];

    scanf("%s", filename);
    fp = fopen(filename,"r");
    fscanf(fp, "%s", dummy); 
    fgetc(fp);
    fgetc(fp);
    /* Read csv content */
    while(fscanf(fp, "%c,%d,%d", &area, &year, &month) != EOF) {
        if(feof(fp)) break;
        // printf("%c %d %d\n", area, year, month);
        fgetc(fp);
        fgetc(fp);
        count[area-'A'][month-1]++;
        isArea[area-'A'] = 1;
    }
    printf("Area Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec\n");
    for (int i = 0; i < 26; i++)
    {
        if (isArea[i])
        {
            printf("   %c", i+'A');
            for (int j = 0; j < 12; j++)
            {
                printf("%4d", count[i][j]);
            }
            printf("\n");
        }
    }

    
    fclose(fp); 

    return 0;
}
