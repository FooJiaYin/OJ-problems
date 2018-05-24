#include<stdio.h>
#include<string.h>

int valid = 1, now;
char string[1010] = {0};

void check(char open)
{
    if(valid){
        if(open=='}'||open==']'||open==')'||open=='>') { //the opening can not be closing parenthesis
            valid = 0;
            return;
        }
        char input = string[now++];
        /*continue reading till no more opening parenthesis */
        while(input=='{'||input=='['||input=='('||input=='<') {
            check(input);
            input = string[now++];
        }
        /*check if the closing parenthesis match the opening*/
        if(open=='{' && input!='}') valid = 0;
        else if(open=='[' && input!=']') valid = 0;
        else if(open=='(' && input!=')') valid = 0;
        else if(open=='<' && input!='>') valid = 0;
    }
}

int main(void)
{
    int N;
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        now = 0, valid = 1;
        scanf("%*c%c", &string[0]); //determine if the string is blank //%*c: ommit the '\n' after each case
        if(string[0]!='\n') {
            ungetc(string[0], stdin); //read the whole string
            scanf("%s", string);
            while(now<strlen(string) && valid) check(string[now++]); //check the opening
        }
        else ungetc(string[0], stdin);
        if(valid) printf("Case %d: Yes\n", i);
        else printf("Case %d: No\n", i);
    }
    return 0;
}
