#include<stdio.h>

unsigned long long GCD(int a, int b)
{
	if (b==0)
		return a;
	else
		return GCD(b, a%b);
    /*int i;
    if(a<=b)
        for(i=a; i>=0 && (a%i>0 || b%i>0); i--);
    else
        for(i=b; i>=0 && (a%i>0 || b%i>0); i--);
    return i;*/
}

unsigned long long LCM(unsigned long long a, unsigned long long b)
{

    unsigned long long gcd,lcm;

    gcd = GCD(a,b);
    lcm = (a/GCD(a,b))*b;
    return lcm;

    /*int a1, b1;
    a1=a/GCD(a,b);
    b1=b/GCD(a,b);
    return a1*b1*GCD(a,b);*/

    /*int i;
    if(a<=b)
        for(i=b; i%a>0 || i%b>0; i++);
    else
        for(i=a; i%a>0 || i%b>0; i++);
    return i;*/

}

int main(void)
{
    int T;

    scanf("%d", &T);
    while(T--)
    {
        unsigned long long n, x[3], balloonx3;
        int i;

        scanf("%llu %llu %llu %llu", &n, &x[0], &x[1], &x[2]);

        for(i=0;i<3;i++)
            x[i] = GCD(x[i],n);

        //balloonx3 = n/LCM(x[0],x[1])/(x[2]/GCD(x[2],LCM(x[0],x[1])));
        balloonx3 = n/LCM(LCM(x[0],x[1]),x[2]);

        printf("%llu\n", balloonx3);
    }

    return 0;
}

