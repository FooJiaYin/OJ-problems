#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main() {
    Node *head_a = NULL, *head_b = NULL;
    int data;

    while(1) { // read List a
        scanf("%d", &data);
        if (data >= 0) {
          Create_List(&head_a, data);
        } else break;
    }
    while(1) { // read List b
        scanf("%d", &data);
        if (data >= 0) {
          Create_List(&head_b, data);
        } else break;
    }
    
    Node *head = Add_List( head_a, head_b );
    
    Print_List( head_a );
    Print_List( head_b );
    Print_List( head );
    
    Free_List( head_a );
    Free_List( head_b );
    Free_List( head );
    
    return 0;
}


