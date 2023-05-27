#include <string.h>
#include "function.h"

Str::Str(char* src_char) {
    head = new Char(*src_char);
    int i, len = strlen(src_char);
    for(i=1, tail=head; i<len; i++, tail=tail->next) {
        tail->next = new Char(src_char[i]);
    }
} 

Str::Str(const Str & src) {
    head = new Char(src.head->text);
    Char *src_Char = src.head->next;
    for(tail=head; src_Char; tail=tail->next, src_Char=src_Char->next) {
        tail->next = new Char(src_Char->text);
    }
}

Str& Str::strInsert(const Str & src) {
    Str *temp = new Str(src);
    tail->next = temp->head;
    tail = temp->tail;
    return *this;
}