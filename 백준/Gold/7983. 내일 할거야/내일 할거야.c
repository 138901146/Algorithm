#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int d, t;
}
homework;

int compare(const void *x,const void *y)
{
	return ((homework *)x)->t<((homework *)y)->t?1:-1;
}

int main(void)
{
	int n, last=2100000000;
	homework *list=NULL;

	scanf("%d", &n);
	list=(homework *)malloc(n*sizeof(homework));

	for(int i=0;i<n;++i)
		scanf("%d%d", &list[i].d, &list[i].t);
	qsort((void *)list,(size_t)n,sizeof(homework),compare);

	for(int i=0;i<n;++i)
	{
		last=list[i].t<last?list[i].t:last;
		last-=list[i].d;
	}

	printf("%d", last);
	free(list);
	return 0;
}