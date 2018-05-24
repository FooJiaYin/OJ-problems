#include <stdio.h>

void execInst(int *ptrArr[], char inst, int param1, int param2)
{
    if(inst=='S')
    {
        *ptrArr[param1] = param2;
    }

    else
    {
        ptrArr[param1] = ptrArr[param2];
    }
}
