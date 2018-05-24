#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int id;
    struct _node *prev;
    struct _node *next;
} Node;

#define MAX 6000

int compositeList[MAX] = {0};

void makeCompositeList(void)
{
    int now = -1;
    for(int num=4; num<MAX; num++) {
        for(int i=2; i*i<=num && compositeList[now]!=num; i++) {
            if(num%i==0) compositeList[++now] = num;
        }
    }
}

Node *createList(int N)
{
    Node *head = (Node*) malloc(sizeof(Node));
    Node *new = head;
    for(int i=1; i<=N; i++) {
        new->next = (Node*) malloc(sizeof(Node));
        new->next->id = i;
        new->next->prev = new;
        new = new->next;
    }
    new->next = head->next;
    new->next->prev = new;
    free(head);
    return new->next;
}

int solveJosephus(Node *head)
{
    int step = 0;
    Node *now = head;
    while(now->next != now) {
        Node *to_kill;
        int i;
        for(i=0; i<(compositeList[step]); i++) {
            now = now->next;
        }
        step++;
        to_kill = now->prev;
        to_kill->next->prev = to_kill->prev;
        to_kill->prev->next = to_kill->next;
        free(to_kill);
    } 
    return now->id;
}

int main (void)
{
    makeCompositeList();

    int N;
    while(scanf("%d", &N) != EOF) {
        Node *head = createList(N);
        Node *now = head;
        printf("%d\n", solveJosephus(head));
    }
    return 0;
}
