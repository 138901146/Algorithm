#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int from, to, count;
}
boxinfo;

int compare(const void *x,const void *y)
{
	return (((boxinfo *)x)->to<((boxinfo *)y)->to || ((boxinfo *)x)->to==((boxinfo *)y)->to && ((boxinfo *)x)->from<((boxinfo *)y)->from)?-1:1;
}

int main(void)
{
	int N, C, M, answer=0;
	boxinfo *delivery=NULL;

	scanf("%d%d", &N, &C);
	scanf("%d", &M);

	delivery=(boxinfo *)malloc(M*sizeof(boxinfo));
	for(int m=0;m<M;m++)
		scanf("%d%d%d", &delivery[m].from, &delivery[m].to, &delivery[m].count);

	qsort((void *)delivery,(size_t)M,sizeof(boxinfo),compare);

	for(int c=0;c<C;c++)
	{
		int last=-1;
		for(int m=0;m<M;m++)
			if(delivery[m].from>=last && delivery[m].count>0)
			{
				last=delivery[m].to;
				delivery[m].count--;
				answer++;
			}
	}

	printf("%d\n", answer);
	free(delivery);
	return 0;
}