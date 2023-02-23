#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void N_M(int *A,int N,int M,int current)
{
	if(current==M)
	{
		for(int m=0;m<M;m++)
			printf("%d ", A[m]);
		printf("\n");
	}
	else
		for(int n=1;n<=N;n++)
		{
			bool same=false;

			for(int i=0;i<current;i++)
				if(A[i]==n)
				{
					same=true;
					break;
				}
			if(!same)
			{
				A[current]=n;
				N_M(A,N,M,current+1);
			}
		}
}

int main(void)
{
	int N, M, *A=NULL;

	scanf("%d %d", &N, &M);
	A=(int *)malloc(M*sizeof(int));

	N_M(A,N,M,0);

	free(A);
	return 0;
}