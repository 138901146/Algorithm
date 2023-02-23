#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int *A=NULL, *B=NULL, N, M, history[40320][8], count=0;

void N_M(int n,int m)
{
	if(m==M)
	{
		bool same=true;

		for(int i=0;i<count;i++)
		{
			bool same=true;

			for(int j=0;j<M;j++)
				if(B[j]!=history[i][j])
				{
					same=false;
					break;
				}
			if(same)
				return;
		}

		for(int i=0;i<M;i++)
		{
			history[count][i]=B[i];
			printf("%d ", B[i]);
		}
		count++;
		printf("\n");
		return;
	}

	if(n>=N)
		return;

	for(int i=n;i<N;i++)
	{
		B[m]=A[i];
		N_M(i+1,m+1);
	}
}

int main(void)
{
	scanf("%d%d", &N, &M);

	A=(int *)malloc(N*sizeof(int));
	B=(int *)malloc(M*sizeof(int));

	for(int n=0;n<N;n++)
		scanf("%d", &A[n]);

	for(int i=0;i<N;i++)
		for(int j=i+1;j<N;j++)
			if(A[i]>A[j])
			{
				A[i]+=A[j];
				A[j]=A[i]-A[j];
				A[i]-=A[j];
			}

	N_M(0,0);

	free(A);
	free(B);
	return 0;
}