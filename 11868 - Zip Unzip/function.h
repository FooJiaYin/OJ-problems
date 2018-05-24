#ifndef FUNCTION_H
#define FUNCTION_H
#define STR_EXPAND(tok) #tok
#define STR(tok) STR_EXPAND(tok)
#define STR_LEN 20

/* incomplete struct Atom */
struct Atom;

/* a pair of atom */
typedef struct Pair {
    struct Atom *left;
    struct Atom *right;
} Pair;

/* a list of atoms */
typedef struct List {
    struct Atom *data;
    struct List *next;
} List;

/* an atom can be a string, an int, a pair of atoms, or a list */
typedef struct Atom {
    char str[STR_LEN+1];
    int val;
    Pair *pair;
    List *lst;
    int dtype; /* 0 for string, 1 for int, 2 for pair, 3 for list*/
} Atom;



/* functions for creating an atom */
Atom* atom_str(char *str);
Atom* atom_val(int val);

Atom* copy_atom(Atom *aptr);
void print_atom(Atom *aptr);
void free_atom(Atom *atpr);

/* convert an atom to a single-atom list */
List* atom_to_list(Atom *a);

/* this function is important */
/* useful for creating a new copy of an existing list */
List* cons(Atom *a, List *b);

void print_list(List *lptr);
void free_list(List *lptr);
int length(List *lptr);
List* read_list_helper(List *l, int n);
List* read_list(void);

Atom* head(List *lptr);
List* tail(List *lptr);

List* zip(List *lptr1, List *lptr2);
Pair* unzip(List *lptr);

List* take(int n, List *l);
List* drop(int n, List *l);

Pair* pair_list(List *lptr1, List *lptr2);
Pair* split_at(int n, List *l);

void print_pair(Pair* p);
void free_pair(Pair* p);

#endif
