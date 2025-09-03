#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?1:-1;
}

int main(void)
{
	int N, M, **card=NULL, *score=NULL, max;

	scanf("%d%d", &N, &M);
	card=(int **)malloc(N*sizeof(int *));
	score=(int *)calloc(N,sizeof(int));

	for(int n=0;n<N;++n)
	{
		card[n]=(int *)malloc(M*sizeof(int));
		for(int m=0;m<M;++m)
			scanf("%d", &card[n][m]);
		qsort((void *)card[n],(size_t)M,sizeof(int),compare);
	}

	for(int m=0;m<M;++m)
	{
		max=0;

		for(int n=0;n<N;++n)
			max=card[n][m]<max?max:card[n][m];

		for(int n=0;n<N;++n)
			if(card[n][m]==max)
				++score[n];
	}

	max=0;
	for(int n=0;n<N;++n)
		max=score[n]<max?max:score[n];

	for(int n=0;n<N;++n)
	{
		free(card[n]);
		if(score[n]==max)
			printf("%d ", n+1);
	}
	free(card);
	free(score);
	return 0;
}