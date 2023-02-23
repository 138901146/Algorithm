#include<stdio.h>
#include<stdlib.h>

int N, M, K, *r=NULL, *c=NULL, *s=NULL;

int rotate(int **A,int bit)
{
	int min[65], count=0, min_value=10000, original_min=10000;

	if(bit==(1<<K)-1)
	{
		for(int n=0;n<N;n++)
		{
			int sum=0;

			for(int m=0;m<M;m++)
				sum+=A[n][m];

			if(sum<original_min)
				original_min=sum;
		}
		return original_min;
	}

	for(int k=0;k<K;k++)
		if(!(bit&1<<k))
		{
			int **B=(int **)malloc(N*sizeof(int *));
			for(int n=0;n<N;n++)
			{
				B[n]=(int *)malloc(M*sizeof(int));
				for(int m=0;m<M;m++)
					B[n][m]=A[n][m];
			}

			for(int i=1;i<=s[k];i++)
			{
				int temp=B[r[k]-i][c[k]+i];

				for(int j=0;j<2*i;j++)
					B[r[k]-i][c[k]+i-j]=B[r[k]-i][c[k]+i-j-1];
				for(int j=0;j<2*i;j++)
					B[r[k]-i+j][c[k]-i]=B[r[k]-i+j+1][c[k]-i];
				for(int j=0;j<2*i;j++)
					B[r[k]+i][c[k]-i+j]=B[r[k]+i][c[k]-i+j+1];
				for(int j=0;j<2*i;j++)
					B[r[k]+i-j][c[k]+i]=B[r[k]+i-j-1][c[k]+i];
				B[r[k]-i+1][c[k]+i]=temp;
			}

			min[count++]=rotate(B,bit|1<<k);

			for(int n=0;n<N;n++)
				free(B[n]);
			free(B);
		}

	for(int i=0;i<count;i++)
		if(min[i]<min_value)
			min_value=min[i];

	return min_value;
}

int main(void)
{
	int **A=NULL;

	scanf("%d%d%d", &N, &M, &K);
	A=(int **)malloc(N*sizeof(int *));
	for(int n=0;n<N;n++)
	{
		A[n]=(int *)malloc(M*sizeof(int));

		for(int m=0;m<M;m++)
			scanf("%d", &A[n][m]);
	}
	r=(int *)malloc(K*sizeof(int));
	c=(int *)malloc(K*sizeof(int));
	s=(int *)malloc(K*sizeof(int));

	for(int k=0;k<K;k++)
	{
		scanf("%d%d%d", &r[k], &c[k], &s[k]);
		r[k]--;
		c[k]--;
	}
	printf("%d\n", rotate(A,0));

	free(s);
	free(c);
	free(r);
	for(int n=0;n<N;n++)
		free(A[n]);
	free(A);
	return 0;
}