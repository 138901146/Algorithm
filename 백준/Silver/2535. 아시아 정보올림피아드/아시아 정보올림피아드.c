#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int country, id, score;
}
competition;

int compare(const void *x,const void *y)
{
	return ((competition *)x)->score<((competition *)y)->score?1:-1;
}

int main(void)
{
	int N;
	competition *olympiad=NULL;

	scanf("%d", &N);
	olympiad=(competition *)malloc(N*sizeof(competition));

	for(int n=0;n<N;++n)
		scanf("%d%d%d", &olympiad[n].country, &olympiad[n].id, &olympiad[n].score);
	qsort((void *)olympiad,(size_t)N,sizeof(competition),compare);

	for(int n=0;n<2;++n)
		printf("%d %d\n", olympiad[n].country, olympiad[n].id);
	if(olympiad[0].country==olympiad[1].country)
	{
		for(int n=2;n<N;++n)
			if(olympiad[n].country!=olympiad[0].country)
			{
				printf("%d %d", olympiad[n].country, olympiad[n].id);
				break;
			}
	}
	else
		printf("%d %d\n", olympiad[2].country, olympiad[2].id);
	free(olympiad);
	return 0;
}