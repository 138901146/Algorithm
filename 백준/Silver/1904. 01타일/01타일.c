#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int **tile=malloc(2*sizeof(int *)), N;

	scanf("%d", &N);
	for(int i=0;i<2;i++)
		tile[i]=calloc(N+1,sizeof(int));

	tile[1][1]=tile[1][2]=1;
	tile[0][2]=1;
	for(int n=3;n<=N;n++)
	{
		tile[0][n]=(tile[0][n-2]+tile[1][n-2])%15746;
		tile[1][n]=(tile[0][n-1]+tile[1][n-1])%15746;
	}

	printf("%d\n", (tile[0][N]+tile[1][N])%15746);
	for(int i=0;i<2;i++)
		free(tile[i]);
	free(tile);
	return 0;
}