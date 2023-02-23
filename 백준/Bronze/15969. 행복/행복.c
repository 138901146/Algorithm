#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?1:*(int *)x==*(int *)y?0:-1;
}

int main(void)
{
	int N, *score=NULL;

	scanf("%d", &N);
	score=(int *)malloc(N*sizeof(int));
	for(int i=0;i<N;i++)
		scanf("%d", &score[i]);

	qsort((void *)score,(size_t)N,sizeof(int),compare);

	printf("%d\n", score[N-1]-score[0]);
	free(score);
	return 0;
}