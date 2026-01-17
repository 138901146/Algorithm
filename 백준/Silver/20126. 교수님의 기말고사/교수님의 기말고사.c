#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int x, y;
}
test;

int compare(const void *a,const void *b)
{
	return ((test *)a)->x<((test *)b)->x?-1:1;
}

int main(void)
{
	int N, M, S, last=0;
	test *exam=NULL;

	scanf("%d%d%d", &N, &M, &S);

	exam=(test *)malloc(N*sizeof(test));

	for(int i=0;i<N;++i)
		scanf("%d%d", &exam[i].x, &exam[i].y);

	qsort((void *)exam,(size_t)N,sizeof(test),compare);

	for(int i=0;i<N;++i)
		if(last+M<=exam[i].x)
		{
			printf("%d", last);
			free(exam);
			return 0;
		}
		else
			last=exam[i].x+exam[i].y<last?last:exam[i].x+exam[i].y;

	printf("%d", last+M<=S?last:-1);
	free(exam);
	return 0;
}