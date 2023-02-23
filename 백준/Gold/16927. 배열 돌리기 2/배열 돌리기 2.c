#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, M, R, **A=NULL, NS=0, MS=0, NE, ME;

	scanf("%d%d%d", &N, &M, &R);
	A=(int **)malloc(N*sizeof(int *));
	for(int n=0;n<N;n++)
	{
		A[n]=(int *)malloc(M*sizeof(int));

		for(int m=0;m<M;m++)
			scanf("%d", &A[n][m]);
	}

	NE=N-1;
	ME=M-1;

	while(NS<NE && MS<ME)
	{
		int rotate=R%(2*(NE-NS+ME-MS));

		for(int r=0;r<rotate;r++)
		{
			int temp=A[NS][MS];

			for(int m=MS;m<ME;m++)
				A[NS][m]=A[NS][m+1];
			for(int n=NS;n<NE;n++)
				A[n][ME]=A[n+1][ME];
			for(int m=ME;m>MS;m--)
				A[NE][m]=A[NE][m-1];
			for(int n=NE;n>NS;n--)
				A[n][MS]=A[n-1][MS];
			A[NS+1][MS]=temp;
		}
		NS++;
		NE--;
		MS++;
		ME--;
	}

	for(int n=0;n<N;n++)
	{
		for(int m=0;m<M;m++)
			printf("%d ", A[n][m]);
		printf("\n");
		free(A[n]);
	}
	free(A);
	return 0;
}