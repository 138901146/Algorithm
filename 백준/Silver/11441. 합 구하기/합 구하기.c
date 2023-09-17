#include<stdio.h>
#include<malloc.h>

int main(void)
{
	int N, M, *A=NULL, i, j;

	scanf("%d", &N);
	A=(int *)malloc((N+1)*sizeof(int));
	A[0]=0;

	for(int n=1;n<=N;++n)
	{
		scanf("%d", &A[n]);
		A[n]+=A[n-1];
	}

	scanf("%d", &M);

	while(M--)
	{
		scanf("%d%d", &i, &j);
		printf("%d\n", A[j]-A[i-1]);
	}

	free(A);
	return 0;
}