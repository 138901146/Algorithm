#include<stdio.h>
#include<stdlib.h>

void N_M(int *A,int N,int M,int current)
{
	if(current==M+1)
	{
		for(int m=1;m<=M;m++)
			printf("%d ", A[m]);
		printf("\n");
	}
	else
		for(int n=A[current-1];n<=N;n++)
		{
			A[current]=n;
			N_M(A,N,M,current+1);
		}
}

int main(void)
{
	int N, M, *A=NULL;

	scanf("%d %d", &N, &M);
	A=(int *)malloc((N+1)*sizeof(int));

	A[0]=1;
	N_M(A,N,M,1);

	free(A);
	return 0;
}