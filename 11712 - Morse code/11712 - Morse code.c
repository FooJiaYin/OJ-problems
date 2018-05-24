#include <stdio.h>
#include<string.h>
char input[1020]={0}, letter[5]={0}, string[600]={0};
int N, now=0, ls=0;

void translate(i)
{
    letter[i+1]='\0';
    //printf("%s", letter);

    if (strcmp(letter, "*-")==0)     string[ls++] = 'A';
    else if (strcmp(letter, "-***"  )==0) string[ls++] = 'B';
    else if (strcmp(letter, "-*-*"  )==0) string[ls++] = 'C';
    else if (strcmp(letter, "-**"   )==0) string[ls++] = 'D';
    else if (strcmp(letter, "*"     )==0) string[ls++] = 'E';
    else if (strcmp(letter, "**-*"  )==0) string[ls++] = 'F';
    else if (strcmp(letter, "--*"   )==0) string[ls++] = 'G';
    else if (strcmp(letter, "****"  )==0) string[ls++] = 'H';
    else if (strcmp(letter, "**"    )==0) string[ls++] = 'I';
    else if (strcmp(letter, "*---"  )==0) string[ls++] = 'J';
    else if (strcmp(letter, "-*-"   )==0) string[ls++] = 'K';
    else if (strcmp(letter, "*-**"  )==0) string[ls++] = 'L';
    else if (strcmp(letter, "--"    )==0) string[ls++] = 'M';
    else if (strcmp(letter, "-*"    )==0) string[ls++] = 'N';
    else if (strcmp(letter, "---"   )==0) string[ls++] = 'O';
    else if (strcmp(letter, "*--*"  )==0) string[ls++] = 'P';
    else if (strcmp(letter, "--*-"  )==0) string[ls++] = 'Q';
    else if (strcmp(letter, "*-*"   )==0) string[ls++] = 'R';
    else if (strcmp(letter, "***"   )==0) string[ls++] = 'S';
    else if (strcmp(letter, "-"     )==0) string[ls++] = 'T';
    else if (strcmp(letter, "**-"   )==0) string[ls++] = 'U';
    else if (strcmp(letter, "***-"  )==0) string[ls++] = 'V';
    else if (strcmp(letter, "*--"   )==0) string[ls++] = 'W';
    else if (strcmp(letter, "-**-"  )==0) string[ls++] = 'X';
    else if (strcmp(letter, "-*--"  )==0) string[ls++] = 'Y';
    else if (strcmp(letter, "--**"  )==0) string[ls++] = 'Z';

    //printf("%s\n", string);
}

void scan_signal(int i)
{
    int length;
    for(length=0; input[now]=='='; ++length, now++);

    if(length==1) letter[i] = '*';
    else if(length==3) letter[i] = '-';
    if(now<=N) separate(i);
}

void separate(int i)
{
    int length;
    for(length=0; input[now]=='.'; ++length, now++);

    if(length==1)
        if(now<N) scan_signal(i+1);

    if(length==3||length==7||length==0)
    {
        translate(i);
        if(length==7) string[ls++] = ' ';
        if(now<N) scan_signal(0);
    }
}

int main(void)
{
    scanf("%d", &N);
    scanf("%s", &input);
    scan_signal(0);
    printf("%s\n", string);
}
