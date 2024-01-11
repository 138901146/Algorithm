#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int start, end;
}
term;

int compare(const void *x,const void *y)
{
	return ((term *)x)->end<((term *)y)->end?-1:((term *)x)->end>((term *)y)->end?1:((term *)x)->start<((term *)y)->start?-1:1;
}

int main(void)
{
	int N, count=0, last=-1;
	term *meeting=NULL;

	scanf("%d", &N);
	meeting=(term *)malloc(N*sizeof(term));

	for(int n=0;n<N;++n)
		scanf("%d%d", &meeting[n].start, &meeting[n].end);
	qsort((void *)meeting,(size_t)N,sizeof(term),compare);

	for(int n=0;n<N;++n)
		if(meeting[n].start>=last)
		{
			++count;
			last=meeting[n].end;
		}

	printf("%d", count);
	free(meeting);
	return 0;
}