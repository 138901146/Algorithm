#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int X, A;
}
VILLAGE;

int compare(const void *x,const void *y)
{
	return ((VILLAGE *)x)->X<((VILLAGE *)y)->X?-1:1;
}

int main(void)
{
	int N;
	long long total=0, sum=0;
	VILLAGE *village=NULL;

	scanf("%d", &N);
	village=(VILLAGE *)malloc(N*sizeof(VILLAGE));

	for(int i=0;i<N;++i)
	{
		scanf("%d%d", &village[i].X, &village[i].A);
		total+=village[i].A;
	}
	qsort((void *)village,(size_t)N,sizeof(VILLAGE),compare);

	for(int i=0;i<N;++i)
	{
		sum+=village[i].A;

		if(total<=(sum<<1))
		{
			printf("%d", village[i].X);
			free(village);
			return 0;
		}
	}

	printf("%d", village[N-1].X);
	free(village);
	return 0;
}