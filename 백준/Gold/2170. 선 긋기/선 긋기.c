#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int x, y;
}
line;

int compare(const void *x,const void *y)
{
	return ((line *)x)->x<((line *)y)->x?-1:((line *)x)->x>((line *)y)->x?1:((line *)x)->y<((line *)y)->y?-1:1;
}

int main(void)
{
	int N, sum=0, y;
	line *list=NULL;

	scanf("%d", &N);
	list=(line *)malloc(N*sizeof(line));

	for(int n=0;n<N;++n)
		scanf("%d%d", &list[n].x, &list[n].y);
	qsort((void *)list,(size_t)N,sizeof(line),compare);

	y=list[0].y;
	sum=list[0].y-list[0].x;
	for(int n=0;n<N;++n)
		if(list[n].y<=y)
			continue;
		else if(list[n].x<=y)
		{
			sum+=list[n].y-y;
			y=list[n].y;
		}
		else
		{
			sum+=list[n].y-list[n].x;
			y=list[n].y;
		}

	printf("%d", sum);
	free(list);
	return 0;
}