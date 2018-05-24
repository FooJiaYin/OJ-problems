#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _factory {
	char name[22];
	long difference;
	long a;
	long b;
} Factory;

Factory* factory[100020]={0};
Factory* original[100020]={0};
int n, x, y;

int compare_a(const void *a, const void *b) {
	Factory **fa = (Factory **) a;
	Factory **fb = (Factory **) b;
	if((*fa)->a < (*fb)->a) return 1;
	if((*fa)->a == (*fb)->a) return 0;
	else return -1;
}

int compare_b(const void *a, const void *b) {
	Factory **fa = (Factory **) a;
	Factory **fb = (Factory **) b;
	if((*fa)->b > (*fb)->b) return 1;
	if((*fa)->b == (*fb)->b) return 0;
	else return -1;
}

int compare_difference(const void *a, const void *b) {
	Factory **fa = (Factory **) a;
	Factory **fb = (Factory **) b;
	if((*fa)->difference < (*fb)->difference) return 1;
	if((*fa)->difference == (*fb)->difference) return 0;
	else return -1;
}

int compare_name(const void *a, const void *b) {
    Factory **fa = (Factory **) a;
	Factory **fb = (Factory **) b;
	return(strcmp((*fa)->name,(*fb)->name));
}

long split(int mid)
{
    qsort(factory, mid, sizeof(Factory *), compare_a);
    //printf("%d %d %d\n", n, x, y, mid);
	qsort(&factory[mid], n-mid, sizeof(Factory *), compare_b);

	int i;
	long profit=0;
    for(i=0; i<x; i++) profit += factory[i]->a;
    for(i=n-y; i<n; i++) profit += factory[i]->b;

    return profit;
}

int main(void) {
	scanf("%d %d %d", &n, &x, &y);

	int i;
	long a, b;
	for(i=0; i<n; i++) {
		factory[i] = (Factory *)malloc(sizeof(Factory));
		scanf("%s %ld %ld", factory[i]->name, &(factory[i]->a), &(factory[i]->b));
		factory[i]->difference = factory[i]->a - factory[i]->b;
	}

	long max=0;
	int mid;
	for(i=x; i<=n-y; i++) {
        qsort(factory, n, sizeof(Factory *), compare_difference);
		if(split(i)>max) {
            max = split(i);
            mid = i;
		}
	}

	qsort(factory, n, sizeof(Factory *), compare_difference);
	qsort(factory, mid, sizeof(Factory *), compare_a);

	/*for(i=0; i<mid; i++) {
		printf("%s\n", factory[i]->name);
	}printf("\n");*/

	qsort(factory, x, sizeof(Factory *), compare_name);

	for(i=0; i<x; i++) {
		printf("%s\n", factory[i]->name);
		free(factory[i]);
	}
	for(;i<n; i++) {
        free(factory[i]);
	}

	return 0;
}
