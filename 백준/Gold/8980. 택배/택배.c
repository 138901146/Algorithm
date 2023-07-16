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
	int N, C, M, sum=0, load, max, *state=NULL;
	boxinfo *delivery=NULL;

	scanf("%d%d", &N, &C);
	scanf("%d", &M);

	state=(int *)calloc(N+1,sizeof(int));
	delivery=(boxinfo *)malloc(M*sizeof(boxinfo));
	for(int m=0;m<M;m++)
		scanf("%d%d%d", &delivery[m].from, &delivery[m].to, &delivery[m].count);

	qsort((void *)delivery,(size_t)M,sizeof(boxinfo),compare);

	for(int m=0;m<M;m++)
	{
		max=0;

		for(int i=delivery[m].from;i<delivery[m].to;i++)
			max=max>state[i]?max:state[i];

		load=C-max<delivery[m].count?C-max:delivery[m].count;
		sum+=load;

		for(int i=delivery[m].from;i<delivery[m].to;i++)
			state[i]+=load;
	}

	printf("%d\n", sum);
	free(state);
	free(delivery);
	return 0;
}