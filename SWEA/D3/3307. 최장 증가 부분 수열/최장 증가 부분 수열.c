#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int T, *A=NULL, *B=NULL, N, max;

	scanf("%d", &T);

	for(int t=1;t<=T;t++)
	{
		scanf("%d", &N);
		max=1;
		A=(int *)malloc(N*sizeof(int));
		B=(int *)malloc(N*sizeof(int));
		for(int n=0;n<N;n++)
		{
			scanf("%d", &A[n]);
			B[n]=1;
		}

		for(int i=N-2;i>=0;i--)
		{
			for(int j=i+1;j<N;j++)
				B[i]=A[i]<=A[j]&&B[j]+1>B[i]?B[j]+1:B[i];
			max=B[i]>max?B[i]:max;
		}

		printf("#%d %d\n", t, max);
		free(A);
		free(B);
	}

	return 0;
}