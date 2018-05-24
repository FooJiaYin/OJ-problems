#include<stdio.h>
#include<stdlib.h>

int main()
{
 int i,num,j,element=0;
 scanf("%d",&num);
 for(i=num;i>0;i--)
    {
        for(j=2;j<i;j++)
        {
            if(i%j==0)
            {
                element=1;
                break;
            }
            else element=0;
        }
     if(element==0)
        {
            printf("%d\n",i);
            break;
        }
     }
    system("pause");
    return 0;
}
