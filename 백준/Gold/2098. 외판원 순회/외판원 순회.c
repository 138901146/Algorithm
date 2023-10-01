#include<stdio.h>
#include<malloc.h>

int N, **W=NULL, **distance=NULL, full;

int tsp(int visited,int city)
{
	if(visited==full-1)
		return W[city][0]==0?10000000:W[city][0];
	else if(distance[city][visited]!=-1)
		return distance[city][visited];

	distance[city][visited]=10000000;
	for(int n=0;n<N;++n)
		if(!(visited&(1<<n)) && W[city][n])
		{
			int next=tsp(visited|(1<<n),n)+W[city][n];
			distance[city][visited]=distance[city][visited]<next?distance[city][visited]:next;
		}

	return distance[city][visited];
}

int main(void)
{

	scanf("%d", &N);
	W=(int **)malloc(N*sizeof(int *));
	distance=(int **)malloc(N*sizeof(int *));
	full=1<<N;

	for(int i=0;i<N;++i)
	{
		W[i]=(int *)malloc(N*sizeof(int));
		distance[i]=(int *)malloc(full*sizeof(int));
		for(int j=0;j<N;++j)
			scanf("%d", &W[i][j]);
		for(int j=0;j<full;++j)
			distance[i][j]=-1;
	}

	printf("%d", tsp(1,0));
	for(int n=0;n<N;++n)
	{
		free(W[n]);
		free(distance[n]);
	}
	free(W);
	free(distance);
	return 0;
}