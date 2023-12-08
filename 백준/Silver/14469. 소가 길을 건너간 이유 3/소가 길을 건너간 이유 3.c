#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int arrival, test;
}
farm;

int compare(const void *x,const void *y)
{
	return ((farm *)x)->arrival<((farm *)y)->arrival?-1:1;
}

int main(void)
{
	int N, time;
	farm cow[100];

	scanf("%d", &N);

	for(int n=0;n<N;++n)
		scanf("%d%d", &cow[n].arrival, &cow[n].test);

	qsort((void *)cow,(size_t)N,sizeof(farm),compare);

	time=cow[0].arrival+cow[0].test;
	for(int n=1;n<N;++n)
	{
		time=cow[n].arrival<time?time:cow[n].arrival;
		time+=cow[n].test;
	}

	printf("%d", time);
	return 0;
}