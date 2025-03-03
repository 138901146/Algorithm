#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int a, b, c;
}
ability;

int ab(const void *x,const void *y)
{
	return ((ability *)x)->a+((ability *)x)->b<((ability *)y)->a+((ability *)y)->b?1:-1;
}

int ac(const void *x,const void *y)
{
	return ((ability *)x)->a+((ability *)x)->c<((ability *)y)->a+((ability *)y)->c?1:-1;
}

int bc(const void *x,const void *y)
{
	return ((ability *)x)->b+((ability *)x)->c<((ability *)y)->b+((ability *)y)->c?1:-1;
}

int main(void)
{
	int N, K, total=0, max=0;
	ability *class=NULL;

	scanf("%d%d", &N, &K);
	class=(ability *)malloc(N*sizeof(ability));

	for(int i=0;i<N;++i)
		scanf("%d%d%d", &class[i].a, &class[i].b, &class[i].c);

	qsort((void *)class,(size_t)N,sizeof(ability),ab);
	for(int i=0;i<K;++i)
		max+=class[i].a+class[i].b;

	qsort((void *)class,(size_t)N,sizeof(ability),ac);
	for(int i=0;i<K;++i)
		total+=class[i].a+class[i].c;
	max=total<max?max:total;

	qsort((void *)class,(size_t)N,sizeof(ability),bc);
	total=0;
	for(int i=0;i<K;++i)
		total+=class[i].b+class[i].c;
	max=total<max?max:total;

	printf("%d", max);
	free(class);
	return 0;
}