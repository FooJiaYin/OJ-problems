#include <stdio.h>

int main(void)
{
    int num[5] = {0};
    float ans = 0;
    scanf("%1d%1d%1d", &num[0], &num[1], &num[2]);
    ans = (float)(num[0]+num[2])*50.5 + num[1]*10;
    printf("%.1f\n", ans);
    return 0;
}
