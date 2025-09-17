#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int a, b;
	char c;
}
type;

int compare(const void *x,const void *y)
{
	return ((type *)x)->b<((type *)y)->b?-1:((type *)x)->b>((type *)y)->b?1:((type *)x)->a<((type *)y)->a?-1:1;
}

int main(void)
{
	int N, M;
	type *input=NULL;

	scanf("%d%d", &N, &M);
	input=(type *)malloc(M*sizeof(type));

	for(int m=0;m<M;++m)
		scanf("%d%d %c", &input[m].a, &input[m].b, &input[m].c);

	qsort((void *)input,(size_t)M,sizeof(type),compare);

	for(int m=0;m<M;++m)
		printf("%c", input[m].c);
	free(input);
	return 0;
}