#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int N, **W=NULL;
bool *visited=NULL;

int simulate(int initial,int current,int count)
{
	int min=100000000, distance;

	if(count==N-1)
		return W[current][initial];

	for(int n=0;n<N;n++)
		if(!visited[n])
		{
			visited[n]=true;
			distance=W[current][n]+simulate(initial,n,count+1);
			if(distance<min)
				min=distance;
			visited[n]=false;
		}

	return min;
}

int main(void)
{
	int min=100000000, distance;

	scanf("%d", &N);
	W=(int **)malloc(N*sizeof(int *));
	visited=(bool *)calloc(N,sizeof(bool));
	for(int i=0;i<N;i++)
	{
		W[i]=(int *)malloc(N*sizeof(int));
		for(int j=0;j<N;j++)
		{
			scanf("%d", &W[i][j]);
			if(W[i][j]==0)
				W[i][j]=100000000;
		}
	}

	for(int n=0;n<N;n++)
	{
		visited[n]=true;
		distance=simulate(n,n,0);
		if(distance<min)
			min=distance;
		visited[n]=false;
	}

	printf("%d\n", min);
	for(int n=0;n<N;n++)
		free(W[n]);
	free(W);
	free(visited);
	return 0;
}