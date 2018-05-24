#include <stdio.h>
#include <stdlib.h>

typedef struct _book {
    int id;
    struct _book* on_it;
    struct _book* under_it;
} Book;

void returnBooks(Book* bottom)
{
    Book *now = bottom->on_it;
    while(now != NULL) {
        now->under_it->on_it = NULL;
        now->under_it = NULL;
        now = now->on_it;
    }
}

Book* findTop(Book* bottom, Book* to_move)
{
    Book *top = bottom;
    while(top->on_it != NULL) {
        if(top == to_move) return NULL;
        top = top->on_it;
    }
    if(top == to_move) return NULL;
    else return top;
}

void moveBooks(Book* to_move, Book* bottom)
{
    if(to_move->under_it != NULL) to_move->under_it->on_it = NULL;
    to_move->under_it = bottom;
    bottom->on_it = to_move;
}

void showBooks(Book book[], int total)
{
    for(int i=0; i<total; i++) {
        printf("%d:", i);
        if(book[i].under_it == NULL) {
            Book *now = &book[i];
            while(now != NULL) {
                printf(" %d", now->id);
                now = now->on_it;
            }
        }
        printf("\n");
    }
}

int main(void)
{
    int total;
    scanf("%d", &total);

    /* Initialization */
    Book book[total];
    Book *table[total];
    for(int i=0; i<total; i++) {
        book[i].id = i;
        book[i].on_it = NULL;
        book[i].under_it = NULL;
    }

    char command_1[6], command_2[6];
    int id_A, id_B;
    while(1) {
        scanf("%s", command_1);
        if(command_1[0] == 'e') break;
        else {
            scanf("%d %s %d", &id_A, command_2, &id_B);

            if(findTop(&book[id_A], &book[id_B]) && findTop(&book[id_B], &book[id_A]))    //judge if command valid
            {
                if(command_1[0]=='m') { //move
                    returnBooks(&book[id_A]);
                }
                if(command_2[1]=='n') { //onto
                    returnBooks(&book[id_B]);
                    moveBooks(&book[id_A], &book[id_B]);
                }
                if(command_2[1]=='v') { //over
                    moveBooks(&book[id_A], findTop(&book[id_B], 0));
                }
            }         
        }
    }
    showBooks(book, total);
    return 0;
}
