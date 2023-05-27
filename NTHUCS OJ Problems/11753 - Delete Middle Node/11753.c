#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main() {
    Node *head_a = NULL;
    int data;

    while(1) { // read List a
        scanf("%d", &data);
        if (data >= 0) {
          Create_List(&head_a, data);
        } else break;
    }
    
    Node *head = Delete_Middle_Node(head_a);
    Print_List(head);
    Free_List(head);
    
    return 0;
}


