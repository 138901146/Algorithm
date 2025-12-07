#include<stdio.h>
#include<stdlib.h>

#define INF 123456

typedef struct
{
	int location, color;
}
dot;

int compare(const void *x,const void *y)
{
	return ((dot *)x)->color<((dot *)y)->color?-1:((dot *)y)->color<((dot *)x)->color?1:((dot *)x)->location<((dot *)y)->location?-1:1;
}

int main(void)
{
	int N, sum=0;
	dot *dots=NULL;

	scanf("%d", &N);
	dots=(dot *)calloc(N+2,sizeof(dot));

	for(int i=1;i<=N;++i)
		scanf("%d%d", &dots[i].location, &dots[i].color);
	dots[N+1].color=INF;
	qsort((void *)dots,(size_t)N+1,sizeof(dot),compare);

	for(int i=1;i<=N;++i)
	{
		int distance=INF;

		if(dots[i].color==dots[i-1].color)
			distance=dots[i].location-dots[i-1].location<distance?dots[i].location-dots[i-1].location:distance;
		if(dots[i].color==dots[i+1].color)
			distance=dots[i+1].location-dots[i].location<distance?dots[i+1].location-dots[i].location:distance;

		sum+=distance;
	}

	printf("%d", sum);
	free(dots);
	return 0;
}