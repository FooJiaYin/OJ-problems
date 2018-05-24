#include <stdio.h>
#include <string.h>

#define MAX_SIZE 500
char content[MAX_SIZE];
char input[MAX_SIZE]={0};
int buffer=0, read=0, curr=0;

void left()
{
    read += strlen("left")+1;
    char temp;
    curr--;
    temp = content[curr];
    buffer++;
    while(read<MAX_SIZE)
        type();
    content[curr++] = temp;
}

void type()
{
    int i=0;
    for(i=0; input[read]!='/'&&read<MAX_SIZE; i++, read++);
    strncpy(content+curr, input+read-i, i);
    //printf("%s", content);
    curr += i;
    if(!strncmp(input+read+1, "backspace", strlen("backspace")))
    {
        read += strlen("backspace")+1;
        if(curr) curr--;
    }
    else if(!strncmp(input+read+1, "left", strlen("left")))
    {
        left();
    }
    else if(!strncmp(input+read+1, "right", strlen("right")))
    {
        read += strlen("right")+1;
        if(buffer)
        {
            curr++;
            return;
        }
    }
    else if(!strncmp(input+read+1, "newline", strlen("newline")))
    {
        read += strlen("newline")+1;
        content[curr++] = '\n';
    }
}

int main()
{
    fgets(input, MAX_SIZE, stdin);

    while(read<MAX_SIZE)
    {
        type();
    }
    content[curr] = '\0';

    printf("%s", content);

    return 0;
}
