#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	unsigned int **way=NULL;
	int n, m, T;

	way=(unsigned int **)malloc(1001*sizeof(unsigned int *));
	for(int w=0;w<1001;w++)
		way[w]=(unsigned int *)calloc(1001,sizeof(unsigned int));

	way[2][1]=way[3][1]=1;
	for(int w=1;w<1001;w++)
		way[w][w]=1;
	way[3][2]=2;

	for(int i=4;i<1001;i++)
		for(int j=2;j<i;j++)
			way[i][j]=(way[i-1][j-1]+way[i-2][j-1]+way[i-3][j-1])%1000000009;

	scanf("%d", &T);

	for(int t=0;t<T;t++)
	{
		scanf("%d %d", &n, &m);
		printf("%d\n", way[n][m]);
	}

	for(int w=0;w<1001;w++)
		free(way[w]);
	free(way);
	return 0;
}