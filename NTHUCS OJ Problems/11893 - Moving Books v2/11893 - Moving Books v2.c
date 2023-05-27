#include <stdio.h>
#include <stdlib.h>

typedef struct _book {
    int data;
    struct _book *above;
    struct _book *below;
} Book;

Book *table = NULL;

void createBook (int n)
{
    table = (Book*)malloc(sizeof(Book));
    table->data = -1;
    Book *now = table;
    for(int i=0; i<n; i++) {
        now->above = (Book*)malloc(sizeof(Book));
        now->above->data = i;
        now->above->below = now;
        now = now->above;
    }
    now->above = NULL;
}

Book *searchBook(int id)
{
    Book *now = table->above;
    while(now->above){
        if(now->data==id) return now;
        else now = now->above;
    }
    if(id==-1||now->data==id) return now;
    else return NULL;
}

void moveBook(int id_1, int id_2, char command)
{
    if(id_1==id_2) return;
    Book *book_1, *book_2;
    book_1 = searchBook(id_1);
    if(command) book_2 = searchBook(id_2);
    if(book_1==NULL || (command && book_2==NULL)) return;

    if(book_1->above) book_1->above->below = book_1->below;
    book_1->below->above = book_1->above;
    if(command) {
        if(command=='o'){
            book_1->above = book_2->above;
            book_1->below = book_2;
        }
        else if(command=='u'){
            book_1->below = book_2->below;
            book_1->above = book_2;
        }
        if(book_1->above) book_1->above->below = book_1;
        book_1->below->above = book_1;
    }
}

void switchBook (int id)
{
    Book *pivot = searchBook(id);
    if(pivot==NULL||id==0) return;
    //printf("%d\n", pivot->data);
    Book *top = searchBook(-1);
    top->above = table->above;
    top->above->below = top;
    table->above = pivot;
    pivot->below->above = NULL;
    pivot->below = table;
}

void reverseList()
{
    Book *top = searchBook(-1);
    Book *now = top;
    table->above = top;
    /*Book *now2 = table;
    while(now2->above) {
        printf("%d ", now->above->data);
        now2 = now2->above;
    }
    printf("\n");*/
    while(now->below!=table) {
        now->above = now->below;
        //printf("%d %d %d\n", now->data, now->above->data, now->below->data);
        now = now->below;
    }
    now->above = NULL;

    now = table;
    while(now->above) {
        now->above->below = now;
        //printf("%d %d\n", now->data, now->above->data);
        now = now->above;
    }
}

int main(void)
{
    int N;
    scanf("%d", &N);
    createBook(N);

    while(1){
        char command_1[8] = {0}, command_2[8] = {0};
        int book_1, book_2;
        scanf("%s", &command_1);
        if(command_1[0]=='m') {
            scanf("%d %s %d", &book_1, command_2, &book_2);
            moveBook(book_1, book_2, command_2[0]);
        }
        else if(command_1[2]=='m') {
            scanf("%d", &book_1);
            moveBook(book_1, -1, 0);
        }
        else if(command_1[0]=='s') {
            scanf("%d", &book_1);
            switchBook(book_1);
        }
        else if(command_1[0]=='r') {
            reverseList();
        }
        else if(command_1[0]=='e') break;
    }

    Book *now = table;
    while(now->above) {
        printf("%d ", now->above->data);
        now = now->above;
    }
    printf("\n");

    return 0;
}
