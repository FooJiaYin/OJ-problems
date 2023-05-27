#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]) {
    char filename[30];
    FILE* fp;
    char courseName[100];
    char category;
    int credit;
    char grade[3];
    int creditR = 0;
    int creditE = 0;
    char dummy[40];

    scanf("%s", filename);
    fp = fopen(filename,"r");
    fscanf(fp, "%s", dummy); 
    fgetc(fp);

    /* Read csv content */
    while(fscanf(fp, "%[^,],%c,%d,%[^\n]", &courseName, &category, &credit, grade) != EOF) {
        if(feof(fp)) break;
        fgetc(fp);

        // printf("%s %c %d %s\n", courseName, category, credit, grade);

        if (grade[0] != 'F') {
            if (category == 'R') {
                creditR += credit;
            }    
            else if (category == 'E') {
                creditE += credit;
            }
        }
    }
    printf("Required: %d\n", creditR);
    printf("Elective: %d\n", creditE);
    if (creditR >= 72 && creditE >= 28) {
        printf("Y\n");
    } 
    else {
        printf("N\n");
        if (creditR < 72 && creditE < 28) {
            printf("Student still needs to complete %d required credits & %d elective credits for graduation.\n", 72-creditR, 28-creditE);
        }
        else if (creditR < 72) {
            printf("Student still needs to complete %d required credits for graduation.\n", 72-creditR);
        }
        else if (creditE < 28) {
            printf("Student still needs to complete %d elective credits for graduation.\n", 28-creditE);
        }
    }

    fclose(fp); 

    return 0;
}
