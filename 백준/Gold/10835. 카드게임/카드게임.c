#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

int main(void)
{
	int N, *A=NULL, *B=NULL, **score=NULL, max=0;
	bool **reachable=NULL;

	scanf("%d", &N);
	A=(int *)malloc(N*sizeof(int));
	B=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;++n)
		scanf("%d", &A[n]);
	for(int n=0;n<N;++n)
		scanf("%d", &B[n]);

	score=(int **)malloc((N+1)*sizeof(int *));
	for(int n=0;n<=N;++n)
		score[n]=(int *)calloc(N+1,sizeof(int));
	reachable=(bool **)malloc((N+1)*sizeof(bool *));
	for(int n=0;n<=N;++n)
		reachable[n]=(bool *)calloc(N+1,sizeof(bool));
	reachable[0][0]=true;

	for(int a=0;a<N;++a)
		for(int b=0;b<N;++b)
		{
			if(!reachable[a][b])
				continue;

			score[a+1][b]=score[a][b]<score[a+1][b]?score[a+1][b]:score[a][b];
			score[a+1][b+1]=score[a][b]<score[a+1][b+1]?score[a+1][b+1]:score[a][b];
			reachable[a+1][b]=reachable[a+1][b+1]=true;
			if(B[b]<A[a])
			{
				score[a][b+1]=score[a][b]+B[b]<score[a][b+1]?score[a][b+1]:score[a][b]+B[b];
				reachable[a][b+1]=true;
			}
		}

	for(int n=0;n<=N;++n)
	{
		max=score[N][n]<max?max:score[N][n];
		max=score[n][N]<max?max:score[n][N];
	}

	printf("%d", max);
	for(int n=0;n<=N;++n)
	{
		free(score[n]);
		free(reachable[n]);
	}
	free(score);
	free(reachable);
	free(A);
	free(B);
	return 0;
}