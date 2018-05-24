#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _factory {
	char name[22];
	long profit;
} Factory;

Factory* factory[100020]={0};
Factory* original[100020]={0};

int compare1(const void *a, const void *b) {
	Factory **fa = (Factory **) a;
	Factory **fb = (Factory **) b;
	if((*fa)->profit < (*fb)->profit) return 1;
	if((*fa)->profit == (*fb)->profit) return 0;
	else return -1;
}

int compare2(const void *a, const void *b) {
    Factory **fa = (Factory **) a;
	Factory **fb = (Factory **) b;
	return(strcmp((*fa)->name,(*fb)->name));
}

int main(void) {
	int n, x, y;
	scanf("%d %d %d", &n, &x, &y);

	int i;
	long a, b;
	for(i=0; i<n; i++) {
		factory[i] = (Factory *)malloc(sizeof(Factory));
		scanf("%s %ld %ld", factory[i]->name, &a, &b);
		factory[i]->profit = a-b;
	}
	qsort(factory, n, sizeof(Factory *), compare1);
	qsort(factory, x, sizeof(Factory *), compare2);
	for(i=0; i<x; i++) {
		printf("%s\n", factory[i]->name);
		free(factory[i]);
	}
	for(;i<n; i++) {
        free(factory[i]);
	}

	return 0;
}
