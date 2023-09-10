#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, M, **Q=NULL, *sum=0, max=0, total=0, A;

	scanf("%d%d", &N, &M);
	Q=(int **)malloc(N*sizeof(int *));
	sum=(int *)calloc(M,sizeof(int));
	for(int n=0;n<N;++n)
	{
		Q[n]=(int *)malloc(M*sizeof(int));
		for(int m=0;m<M;++m)
			scanf("%d", &Q[n][m]);
	}

	scanf("%d", &A);

	for(int m=0;m<M;++m)
	{
		for(int n=0;n<N;++n)
			sum[m]+=Q[n][m];

		if(m>=A)
			total-=sum[m-A];
		total+=sum[m];
		max=total>max?total:max;
	}

	printf("%d", max);
	while(N)
		free(Q[--N]);
	free(Q);
	free(sum);
	return 0;
}