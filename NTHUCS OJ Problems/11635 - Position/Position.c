#include <stdio.h>
#include <string.h>

char str[1000001];

int main()
{
   int i;
   int found;
   char ch;

   scanf("%s", str); /* AbAABzBCAaa */

   ch = 'A'; //initialize
   while (ch<='z') {
        found = 0;
        unsigned long len = strlen(str);
        for (i=0; i<len; i++) {
            if (str[i] == ch) {
                if (!found) {
                    printf("%c: %d", ch, i);
                    found = 1;
                } else {
                    printf(" %d", i);
                }
            }
        }

        if (found)
            printf("\n");

        if (ch == 'Z') {
            ch = 'a';
        }
        else
            ch++; //update
   }
}
