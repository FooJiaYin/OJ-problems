#include<stdio.h>
#include<stdlib.h>
#define FOR(I,N) for(I=0;I<N;I++)
struct matrix
	{
	int numRow;
	int numCol;
	double **arr;
	};

void *myMalloc(int size)
	{
	void *ptr;
	ptr=malloc(size);
	if (ptr==NULL)
		{
		printf("ERROR: memory error!\n");
		system("pause");
		exit(1);
		}
	return ptr;
	}

FILE *myFopen(char *fileName, char *mode)
	{
	FILE *fp;
	fp=fopen(fileName, mode);
	if (fp==NULL)
		{
		printf("ERROR: file %s cannnot open!\n", fileName);
		system("pause");
		exit(1);
		}
	return fp;
	}

struct matrix *newMatrix(int numRow, int numCol)
	{
	int i;
	struct matrix *aM;
	aM=(struct matrix*)myMalloc(sizeof(struct matrix));
	aM->numRow=numRow;
	aM->numCol=numCol;
	aM->arr=(double**)myMalloc(numRow*sizeof(double*));
	FOR(i,numRow)
		aM->arr[i]=(double*)myMalloc(numCol*sizeof(double));
	return aM;
	}
struct matrix *readMatrix(char *fileName)
	{
	FILE *fp;
	struct matrix *aM;
	int i, j, numRow, numCol;
	fp=myFopen(fileName, "r");
	fscanf(fp, "%d %d", &numRow, &numCol);
	aM=newMatrix(numRow, numCol);
	FOR(i, aM->numRow)
		{
		FOR(j,aM->numCol)
			{
			fscanf(fp, "%lf", &(aM->arr[i][j]));
			}
		}
	fclose(fp);
	return aM;
	}
void writeMatrix(struct matrix *aM, char *fileName)
	{
	FILE *fp;
	int i,j;
	fp=myFopen(fileName, "w");
	fprintf(fp, "%d %d\n", aM->numRow, aM->numCol);
	FOR(i,aM->numRow)
		{
		FOR(j, aM->numCol)
			fprintf(fp, "%f ", aM->arr[i][j]);
		fprintf(fp, "\n");
		}
	fclose(fp);
	}

void productMatrix (struct matrix * c, struct matrix * a, struct matrix * b)
	{
	int i, j, k;
	if ( b->numRow!=a->numCol)
		{
		printf("ERROR: number of rows of a & number of cols of b are different.\n");
		system("pause");
		return;
		}
	if ( c->numRow!=a->numRow || c->numCol!=b->numCol)
		{
		printf("ERROR: matrix c have incorrect size.\n");
		system("pause");
		return;
		}
	FOR(i,c->numRow)
		FOR(j,c->numCol) {
		    c->arr[i][j] = 0;
            FOR(k,a->numCol)
                c->arr[i][j] += a->arr[i][k]*b->arr[k][j];
		}
	return;
	}

int main()
{
	struct matrix *a, *b, *c;
	a=readMatrix("A.txt");
	b=readMatrix("B.txt");
	c=newMatrix(a->numRow, b->numCol);
	productMatrix(c,a,b);
	writeMatrix(c, "C.txt");
	system("pause");
}
