#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, K, **C=NULL;

	scanf("%d %d", &N, &K);
	C=(int **)malloc((N+1)*sizeof(int *));
	K=K*2>=N?N-K:K;
	for(int c=0;c<=N;c++)
		C[c]=(int *)calloc(K+1,sizeof(int));

	C[0][0]=1;
	for(int i=1;i<=N;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=K;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%10007;
	}

	printf("%d\n", C[N][K]);
	for(int c=0;c<=N;c++)
		free(C[c]);
	free(C);
	return 0;
}