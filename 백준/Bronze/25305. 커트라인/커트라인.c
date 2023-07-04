#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?1:*(int *)x==*(int *)y?0:-1;
}

int main(void)
{
	int N, k, *score=NULL;

	scanf("%d%d", &N, &k);

	score=(int *)malloc(N*sizeof(int));
	for(int n=0;n<N;n++)
		scanf("%d", &score[n]);
	qsort((void *)score,(size_t)N,sizeof(int),compare);

	printf("%d\n", score[N-k]);
	free(score);
	return 0;
}