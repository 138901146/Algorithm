#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, *A=NULL, M, count=0;

	scanf("%d %d", &N, &M);
	A=(int *)malloc(N*sizeof(int));
	for(int i=0;i<N;i++)
		scanf("%d", &A[i]);

	for(int i=0;i<N;i++)
	{
		int sum=0;

		for(int j=i;j<N&&sum<M;j++)
			sum+=A[j];
		count+=sum==M;
	}

	printf("%d\n", count);
	free(A);
	return 0;
}