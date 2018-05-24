#include <stdio.h>

char choose()
{
    char input, left, right, ans;
    input = getchar();

    if(input=='L')
    {
        left = choose();
        right = choose();
        ans = left;
    }

    else if(input=='R')
    {
        left = choose();
        right = choose();
        ans = right;
    }

    else ans = input;

    return ans;
}

int main(void)
{
    printf("%c\n", choose());
    return 0;
}
