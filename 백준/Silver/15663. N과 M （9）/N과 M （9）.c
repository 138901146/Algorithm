#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int *A=NULL, *B=NULL, N, M, history[40320][8], count=0;

void N_M(int m,bool *used)
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
			history[count][i]=B[i];
		count++;
		return;
	}

	for(int i=0;i<N;i++)
		if(!used[i])
		{
			B[m]=A[i];
			used[i]=true;
			N_M(m+1,used);
			used[i]=false;
		}
}

int main(void)
{
	scanf("%d%d", &N, &M);

	A=(int *)malloc(N*sizeof(int));
	B=(int *)malloc(M*sizeof(int));
	bool *used=(bool *)calloc(M,sizeof(bool));

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

	N_M(0,used);

	for(int i=0;i<count;i++)
		for(int j=i+1;j<count;j++)
			for(int k=0;k<M;k++)
				if(history[i][k]>history[j][k])
					for(int l=0;l<M;l++)
					{
						history[i][k]+=history[j][k];
						history[j][k]=history[i][k]-history[j][k];
						history[i][k]-=history[j][k];
					}
				else if(history[i][k]<history[j][k])
					break;

	for(int i=0;i<count;i++)
	{
		for(int j=0;j<M;j++)
			printf("%d ", history[i][j]);
		printf("\n");
	}
	free(A);
	free(B);
	return 0;
}