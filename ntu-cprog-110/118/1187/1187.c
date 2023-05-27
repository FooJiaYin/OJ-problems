#include <stdio.h>
#include <string.h>
#define NUM 5

typedef struct {
    char Name[80];
    char Phone[20];
    char Email[20];
    int Id;
} Employee;

int main(void) {
    char command;
    Employee employees[50];
    int numEmployee = 0;

    while (scanf("%c", &command) != EOF) {
        if (command == 'i') {
            // employees[numEmployee].Id = numEmployee;
            scanf("%s", employees[numEmployee].Name);
            scanf("%s", employees[numEmployee].Phone);
            scanf("%s", employees[numEmployee].Email);
            numEmployee++;
        } 
        else if (command == 'l') {
            if (numEmployee == 0) printf("No data.\n");
            for (int i = 0; i < numEmployee; i++) {
                printf("#%d\n", i + 1);
                printf("Name: %s\n", employees[i].Name );
                printf("Phone: %s\n", employees[i].Phone);
                printf("Email: %s\n", employees[i].Email);
            }
        } 
        else if (command == 's') {
            char filename[100] = "";
            scanf("%s", filename);
            FILE* fp = fopen(filename, "wb");
            if (fp == NULL) return 0;

            fwrite(&numEmployee, 4, 1, fp);
            for (int i = 0; i < numEmployee; i++) {
                fwrite(&employees[i], sizeof(Employee), 1, fp);
            }
            fclose(fp);
        } 
        else if (command == 'o') {
            char filename[100] = "";
            scanf("%s", filename);
            FILE* fp = fopen(filename, "rb");
            if (fp == NULL) return 0;

            fread(&numEmployee, 4, 1, fp);
            for (int i = 0; i < numEmployee; i++) {
                fread(&employees[i], sizeof(Employee), 1, fp);
            }
            // for (int i = 0; i < 3000; i++) {
            //     char c;
            //     fread(&c, 1, 1, fp);
            //     printf("%x", c);
            // }
            // printf("\n");
            fclose(fp);
        } 
        else if (command == 'c') {
            numEmployee = 0;
        }
        else if (command == 'q') break;
    }
    return 0;
}