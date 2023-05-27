#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>

#include "function.h"


List* zip(List *lptr1, List *lptr2)
{
    if(lptr1 == NULL || lptr2 == NULL) return NULL;

    Atom a;
    a.dtype = 2;
    a.pair = (Pair*)malloc(sizeof(Pair));
    a.pair->left = copy_atom(lptr1->data);
    a.pair->right = copy_atom(lptr2->data);

    return cons(&a, zip(lptr1->next, lptr2->next));
}

Pair* unzip(List *lptr)
{
    if(lptr == NULL) return pair_list(NULL, NULL);
    else if(lptr->data->dtype == 2) {
        Pair *next_pair = unzip(lptr->next);
        List *l1 = cons(lptr->data->pair->left, next_pair->left->lst);
        List *l2 = cons(lptr->data->pair->right, next_pair->right->lst);
        return pair_list(l1, l2);
    }
}
