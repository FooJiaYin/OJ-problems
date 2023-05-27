#include <stdio.h>

int max(a,b)
{
    if(a>b) return a;
    else return b;
}

int min(a,b)
{
    if(a<b) return a;
    else return b;
}

int min_max()
{
    char input;
    int ans;
    input = getchar();

    if(isdigit(input))
        ans = input-'0';
    else if (input=='M')
        ans = max(min_max(), min_max());
    else if (input=='m')
        ans = min(min_max(), min_max());

    return ans;
}

int main(void)
{
    printf("%d", min_max());
    return 0;
}
