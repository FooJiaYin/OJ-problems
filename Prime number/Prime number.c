#include<stdio.h>

int main(void)

{
    int number, divisor, limit;
    limit = 100;

    printf("List of Prime Numbers (<%d):\n", limit);

    for(number = 1; number <= limit; number++)
    {
        for(divisor = 2; divisor < number && number%divisor > 0; divisor++);

        if(number == divisor)
           printf("%d\n", number);
    }

    return 0;
}

