#include <string.h>
#include "function.h"

// construct a new Str by linked list of Char
Str::Str(char* src_char) {
    head = new Char(*src_char);
    int len = strlen(src_char);
    int i;
    for(tail = head, i = 1; i<len; tail = tail->next, i++) {
        tail->next = new Char(src_char[i]);
    }
}

// copy constructor
// have to copy all Chars of another Str
Str::Str(const Str & src) {
    head = new Char(src.head->text);
    Char *src_tempChar;
    for(tail = head, src_tempChar = src.head->next; src_tempChar; tail = tail->next, src_tempChar = src_tempChar->next) {
        tail->next = new Char(src_tempChar->text);
    }
}

// equality operator
bool Str::operator==( const Str & ref) const {
    for(Char *tempA = head, *tempB = ref.head; tempA && tempB; tempA=tempA->next, tempB=tempB->next) {
        if(tempA->text!=tempB->text) return false;
        if((tempA->next==NULL && tempB->next) || (tempA->next && tempB->next==NULL)) return false;
    }
    return true;
}
