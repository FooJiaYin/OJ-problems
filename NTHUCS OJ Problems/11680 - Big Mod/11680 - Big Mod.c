#include<stdio.h>


long long MOD(long long* mod[] , int i, long long p) //Calculate a^(2^i)%p
{
    if (mod[i]==0)
    	mod[i]=(MOD(mod, i-1, p)*MOD(mod, i-1, p))%p; //record the result of MOD (fast power algorithm)
    return mod[i];
}

int main(void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        long long mod2pw[50]={0};
        long long a,n,p,i,mod;
        scanf("%lld %lld %lld", &a, &n, &p);
        mod2pw[0]=a%p;
        for (mod=1, i=0; n>0; n/=2, i++) //convert n to binary
        {
            if (mod2pw[0]!=0)
            {
                if(n%2)
                    mod=(mod*MOD(mod2pw, i,p))%p;
            }
            else mod = mod2pw[0]; //if(a%p==0) mod=0
        }
        printf("%lld\n", mod);
    }
    return 0;
}
