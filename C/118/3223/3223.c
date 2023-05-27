#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]) {
    char filename[30];
    FILE* fp;
    char day[14];
    int rainFall;
    int consumption;
    int amount;
    int totalRainFall = 0;
    int maxConsumption = 0;
    int count = 0;
    char dummy[40];

    do {
        scanf("%s", filename);
        fp = fopen(filename,"r");
        if (fp == NULL) {
            printf("file open error!\n");
        }
    } while (fp == NULL);

    do {
        scanf("%d", &amount);
        if (amount < 500) {
            printf("The amount of water storage is wrong!\n");
        }
    } while (amount < 500);
    
    fscanf(fp, "%s", dummy); 
    fgetc(fp);

    // /* Read csv content */
    while(fscanf(fp, "%[^,],%d,%d", &day, &rainFall, &consumption) != EOF) {
        if(feof(fp)) break;
        fgetc(fp);
        totalRainFall += rainFall;
        if(consumption > maxConsumption) maxConsumption = consumption;
        count++;

        if (count == 24) {
            int averageRainFall = round(totalRainFall / 24.0);
            amount += averageRainFall - maxConsumption;
            if (amount > 100) {
                printf("%s %d %d %d\n", day, averageRainFall, maxConsumption, amount);
            }
            else {
                printf("[!!!]WARNING %10s %d\n", day, amount-100);
            }
            
            totalRainFall = 0;
            maxConsumption = 0;
            count = 0;
        }
    }
    fclose(fp); 

    return 0;
}
