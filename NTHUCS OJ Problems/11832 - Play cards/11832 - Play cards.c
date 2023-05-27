#include <stdio.h>
#include <stdlib.h>

typedef struct _card {
    unsigned long number;
    struct _card *next;
} Card;

Card* add(int idx, unsigned long num, Card *head)
{
    Card *temp = NULL;
    if(idx == 0) {
        temp = (Card*)malloc(sizeof(Card));
        if(temp != NULL) {
            temp->number = num;
            temp->next = head;
            head = temp;
        }
    }
    else {
        Card *now = head;
        for(int i=0; i<idx-1; i++){
            if(now != NULL) now = now->next;
        }
        temp = now->next;
        now->next = (Card*)malloc(sizeof(Card));
        if(now->next != NULL) {
            now->next->number = num;
            now->next->next = temp;
        }
    }
    return head;
}

Card* cut(int start, int to_move, Card *head)
{
    if(start > 0) { 				//important!!
        Card *old_head = head;
        Card *temp = head;
        for(int i=0; i<start-1; i++) {
            temp = temp->next;
        }
        Card *top_end = temp;
        for(int i=0; i<to_move; i++) {
            top_end = top_end->next;
        }
        head = temp->next;
        temp->next = top_end->next;
        top_end->next = old_head;
    }
    return head;
}

void print(Card *head)
{
    Card *now = head;
    while(now != NULL) {
        printf("%d\n", now->number);
        if(now->next != NULL) now = now->next;
        else return;
    }
}

int main(void)
{
    int initial_no, operation;
    Card* head = NULL;
    scanf("%d %d", &initial_no, &operation);

    for(int i=0; i<initial_no; i++) {
        int num;
        scanf("%d", &num);
        head = add(i, num, head);
    }
    //print(head);
    while(operation--) {
        char instruction[5] = {0};
        int var1, var2;
        scanf("%s %d %d", &instruction, &var1, &var2);
        if(instruction[0] == 'A')
            head = add(var1, var2, head);
        else if(instruction[0] == 'C')
            head = cut(var1, var2, head);
        //print(head);
    }
    print(head);

    return 0;
}
