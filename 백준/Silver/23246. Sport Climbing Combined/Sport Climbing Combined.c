#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int b, multiply, sum;
}
player;

int compare(const void *x,const void *y)
{
	if(((player *)x)->multiply!=((player *)y)->multiply)
		return ((player *)x)->multiply<((player *)y)->multiply?-1:1;
	else if(((player *)x)->sum!=((player *)y)->sum)
		return ((player *)x)->sum<((player *)y)->sum?-1:1;
	else
		return ((player *)x)->b<((player *)y)->b?-1:1;
}

int main(void)
{
	int n, p, q, r;
	player *rank=NULL;

	scanf("%d", &n);
	rank=(player *)malloc(n*sizeof(player));

	for(int i=0;i<n;++i)
	{
		scanf("%d%d%d%d", &rank[i].b, &p, &q, &r);
		rank[i].multiply=p*q*r;
		rank[i].sum=p+q+r;
	}

	qsort((void *)rank,(size_t)n,sizeof(player),compare);

	for(int i=0;i<3;++i)
		printf("%d ", rank[i].b);
	free(rank);
	return 0;
}