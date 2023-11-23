#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

int **sailor=NULL, *sailor_count=NULL, *status=NULL;
bool *visited=NULL;

bool dfs(int current)
{
	for(int i=0;i<sailor_count[current];++i)
		if(!visited[sailor[current][i]])
		{
			visited[sailor[current][i]]=true;

			if(status[sailor[current][i]]==0 || dfs(status[sailor[current][i]]))
			{
				status[sailor[current][i]]=current;
				return true;
			}
		}

	return false;
}

int main(void)
{
	int N, M, *shirt=NULL, *collar=NULL, count=0;

	scanf("%d%d", &N, &M);
	shirt=(int *)malloc((N+1)*sizeof(int));
	collar=(int *)malloc(M*sizeof(int));
	sailor=(int **)malloc((N+1)*sizeof(int *));
	sailor_count=(int *)calloc(N+1,sizeof(int));

	for(int n=1;n<=N;++n)
		scanf("%d", &shirt[n]);

	for(int m=0;m<M;++m)
	{
		scanf("%d", &collar[m]);

		for(int n=1;n<=N;++n)
			if(shirt[n]<=collar[m]<<1 && collar[m]<<2<=shirt[n]*3 || shirt[n]<=collar[m] && collar[m]<<2<=shirt[n]*5)
				++sailor_count[n];
	}

	for(int n=1;n<=N;++n)
	{
		sailor[n]=(int *)malloc(sailor_count[n]*sizeof(int));
		sailor_count[n]=0;
	}

	for(int m=0;m<M;++m)
		for(int n=1;n<=N;++n)
			if(shirt[n]<=collar[m]<<1 && collar[m]<<2<=shirt[n]*3 || shirt[n]<=collar[m] && collar[m]<<2<=shirt[n]*5)
				sailor[n][sailor_count[n]++]=m;

	free(shirt);
	free(collar);
	visited=(bool *)malloc(M*sizeof(bool));
	status=(int *)calloc(M,sizeof(int));

	for(int n=1;n<=N;++n)
	{
		for(int m=0;m<M;++m)
			visited[m]=false;
		dfs(n);
	}

	for(int m=0;m<M;++m)
		count+=status[m]>0;

	printf("%d", count);
	for(int n=1;n<=N;++n)
		free(sailor[n]);
	free(sailor);
	free(sailor_count);
	free(status);
	free(visited);
	return 0;
}