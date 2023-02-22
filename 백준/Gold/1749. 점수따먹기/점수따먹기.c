#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, M, **matrix=NULL, max=-10000;

	scanf("%d%d", &N, &M);
	matrix=(int **)malloc((N+1)*sizeof(int *));
	for(int i=0;i<=N;i++)
		matrix[i]=(int *)calloc(M+1,sizeof(int));

	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			scanf("%d", &matrix[i][j]);

	for(int i=0;i<=N;i++)
		for(int j=1;j<=M;j++)
			matrix[i][j]+=matrix[i][j-1];

	for(int j=0;j<=M;j++)
		for(int i=1;i<=N;i++)
			matrix[i][j]+=matrix[i-1][j];

	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			for(int k=0;k<i;k++)
				for(int l=0;l<j;l++)
					max=matrix[i][j]-matrix[k][j]-matrix[i][l]+matrix[k][l]>max?matrix[i][j]-matrix[k][j]-matrix[i][l]+matrix[k][l]:max;

	printf("%d\n", max);
	for(int i=0;i<=N;i++)
		free(matrix[i]);
	free(matrix);
	return 0;
}