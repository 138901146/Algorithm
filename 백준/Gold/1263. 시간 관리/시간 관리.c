#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int T, S;
}
work;

int compare(const void *x,const void *y)
{
	return ((work *)x)->S<((work *)y)->S?1:-1;
}

int main(void)
{
	int N, last;
	work *list=NULL;

	scanf("%d", &N);
	list=(work *)malloc(N*sizeof(work));

	for(int i=0;i<N;++i)
		scanf("%d%d", &list[i].T, &list[i].S);
	qsort((void *)list,(size_t)N,sizeof(work),compare);

	last=list[0].S-list[0].T;
	for(int i=1;i<N;++i)
		last=list[i].S<last?list[i].S-list[i].T:last-list[i].T;

	printf("%d", last<0?-1:last);
	free(list);
	return 0;
}