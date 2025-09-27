#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int start, end;
}
location;

int compare(const void *x,const void *y)
{
	return ((location *)x)->end<((location *)y)->end?-1:1;
}

int main(void)
{
	int N, L, last=0, total=0, count;
	location *pool=NULL;

	scanf("%d%d", &N, &L);
	pool=(location *)malloc(N*sizeof(location));

	for(int n=0;n<N;++n)
		scanf("%d%d", &pool[n].start, &pool[n].end);
	qsort((void *)pool,(size_t)N,sizeof(location),compare);

	for(int n=0;n<N;++n)
	{
		if(pool[n].end<=last)
			continue;
		last=pool[n].start<last?last:pool[n].start;
		count=(pool[n].end-last)/L+((pool[n].end-last)%L!=0);
		total+=count;
		last+=count*L;
	}

	printf("%d", total);
	free(pool);
	return 0;
}