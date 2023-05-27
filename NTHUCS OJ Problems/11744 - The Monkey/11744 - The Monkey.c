#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct _record {
    char character;
    struct _record *left;
    struct _record *right;
} Record;

Record *head = NULL;
Record *cursor = NULL;

void del() {
    if(cursor->right != NULL) {
        Record *temp = cursor->right;
        cursor->right = temp->right;
        if(temp->right != NULL) {
            temp->right->left = cursor;
        }
        free(temp);
    }
}

void shift_left() {
    if(cursor != head) {
        cursor = cursor->left;
    }
}
void shift_right() {
    if(cursor->right != NULL) {
        cursor = cursor->right;
    }
}

void type_new(char input) {
    Record *new_record = (Record*) malloc(sizeof(Record));
    new_record->character = input;
    new_record->left = cursor;
    new_record->right = cursor->right;
    cursor->right = new_record;
    if (new_record->right != NULL) {
        (new_record->right)->left = new_record;
    }

    cursor = new_record;
}

int main(void)
{
    head = (Record *)malloc(sizeof(Record));
    head->character = '0';
    head->left = NULL;
    head->right = NULL;
    cursor = head;

    char input=0;
    while(1) {
        input = getchar();
        if(input == 'D') {
            del();
        }
        else if(input == '<') {
            shift_left();
        }
        else if(input == '>') {
            shift_right();
        }
        else if(islower(input) || input=='_') {
            type_new(input);
        }
        else {
            break;
        }
    }

    while(head->right != NULL) {
        head = head->right;
        printf("%c", head->character);
        free(head->left);
    }
    printf("\n");
    free(head);

    return 0;
}
