#include<stdio.h>
#include<stdlib.h>

int *A=NULL, *B=NULL, N, M;

void N_M(int n,int m)
{
	if(m==M)
	{
		for(int i=0;i<M;i++)
			printf("%d ", B[i]);
		printf("\n");
		return;
	}

	for(int i=n;i<N;i++)
	{
		B[m]=A[i];
		N_M(i,m+1);
	}
}

int main(void)
{
	scanf("%d%d", &N, &M);

	A=(int *)malloc(N*sizeof(int));
	B=(int *)malloc(M*sizeof(int));

	for(int n=0;n<N;n++)
		scanf("%d", &A[n]);

	int count=0;
	for(int i=0;i<N;i++)
		for(int j=i+1;j<N;j++)
			if(A[i]>A[j])
			{
				A[i]+=A[j];
				A[j]=A[i]-A[j];
				A[i]-=A[j];
			}

	for(int n=0;n<N-1;n++)
		if(A[n]==A[n+1])
		{
			A[n]=10001;
			count++;
		}

	for(int i=0;i<N;i++)
		for(int j=i+1;j<N;j++)
			if(A[i]>A[j])
			{
				A[i]+=A[j];
				A[j]=A[i]-A[j];
				A[i]-=A[j];
			}
	N-=count;

	N_M(0,0);

	free(A);
	free(B);
	return 0;
}