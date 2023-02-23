#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void N_M(int *A,int *B,int N,int M,int current)
{
	if(current==M)
	{
		for(int m=0;m<M;m++)
			printf("%d ", A[m]);
		printf("\n");
	}
	else
		for(int n=0;n<N;n++)
		{
			bool same=false;

			for(int i=0;i<current;i++)
				if(A[i]==B[n])
				{
					same=true;
					break;
				}
			if(!same)
			{
				A[current]=B[n];
				N_M(A,B,N,M,current+1);
			}
		}
}

int main(void)
{
	int N, M, *A=NULL, *B=NULL;

	scanf("%d %d", &N, &M);
	A=(int *)malloc(M*sizeof(int));
	B=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;n++)
		scanf("%d", &B[n]);

	for(int i=0;i<N-1;i++)
		for(int j=i+1;j<N;j++)
			if(B[i]>B[j])
			{
				int temp=B[i];
				B[i]=B[j];
				B[j]=temp;
			}

	N_M(A,B,N,M,0);

	free(A);
	free(B);
	return 0;
}