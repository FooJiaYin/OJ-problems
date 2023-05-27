#include <stdio.h>
#include <stdlib.h>

typedef struct _book {
    int id;
    struct _book *on;
    struct _book *under;
} Book;

Book *createBooks(int n)
{
    Book *table = (Book*)malloc(sizeof(Book));
    table->id = -1;
    table->under = NULL;
    Book *now = table;
    for(int i = 0; i < n; i++) {
        now->on = (Book*)malloc(sizeof(Book));
        now->on->id = i;
        now->on->under = now;
        now = now->on;
    }
    now->on = NULL;
    return table;
}

Book *searchBook(Book *table, int to_find)
{
    Book *now = table;
    while(now) {
        if(now->id == to_find) break;
        now = now->on;
    }
    return now;
}

void moveBook(Book *table, int id_A, int id_B, char cmd)
{
    Book *book_A = searchBook(table, id_A);
    Book *book_B = NULL;
    if(id_B != -1) book_B = searchBook(table, id_B);
    if(id_A == id_B || book_A == NULL || (id_B != -1 && book_B == NULL)) return;
    book_A->under->on = book_A->on;
    if(book_A->on) book_A->on->under = book_A->under;
    if(cmd == 'o') {
        book_A->on = book_B->on;
        if(book_A->on) book_A->on->under = book_A;
        book_B->on = book_A;
        book_A->under = book_B;
    }
    else if(cmd == 'u') {
        book_A->under = book_B->under;
        if(book_A->under) book_A->under->on = book_A;
        book_B->under = book_A;
        book_A->on = book_B;
    }
}

int main(void)
{
    int N;
    scanf("%d", &N);
    Book* table = createBooks(N);

    char command_1[8] = {0};
    while(1) {
        scanf("%s", command_1);
        if(command_1[0] == 'e') break;
        else if (command_1[0] == 'm'){
            int id_A, id_B; 
            char command_2[7] = {0};
            scanf(" %d %s %d", &id_A, command_2, &id_B);
            moveBook(table, id_A, id_B, command_2[0]);
        }
        else if (command_1[0] == 'r'){
            int id_A;
            scanf("%d", &id_A);
            moveBook(table, id_A, -1, 0);
        }
    }
    Book *now = table->on;
    while(now) {
        printf("%d ", now->id);
        now = now->on;
    }
    printf("\n");

    return 0;
}