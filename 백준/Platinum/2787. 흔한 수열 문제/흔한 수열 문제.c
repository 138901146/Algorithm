#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#include<memory.h>

int **adjacent_list=NULL, *adjacent_list_count=NULL, *occupied=NULL;
bool *visited=NULL;

bool dfs(int current)
{
	for(int i=0;i<adjacent_list_count[current];++i)
	{
		int next=adjacent_list[current][i];

		if(!visited[next])
		{
			visited[next]=true;

			if(!occupied[next] || dfs(occupied[next]))
			{
				occupied[next]=current;
				return true;
			}
		}
	}

	return false;
}

int main(void)
{
	int N, M, *min=NULL, *max=NULL, cmd, x, y, v, count=0, *matched=NULL;
	bool **unable=NULL;

	scanf("%d%d", &N, &M);

	if(!M)
	{
		for(int n=1;n<=N;++n)
			printf("%d ", n);
		return 0;
	}

	min=(int *)calloc(N+1,sizeof(int));
	max=(int *)calloc(N+1,sizeof(int));
	unable=(bool **)malloc((N+1)*sizeof(bool *));

	for(int n=1;n<=N;++n)
		unable[n]=(bool *)calloc(N+1,sizeof(bool));

	while(M--)
	{
		scanf("%d%d%d%d", &cmd, &x, &y, &v);

		if(cmd==1)
			for(int i=x;i<=y;++i)
				max[i]=max[i]?max[i]<v?max[i]:v:v;
		else
			for(int i=x;i<=y;++i)
				min[i]=min[i]?v<min[i]?min[i]:v:v;

		for(int i=1;i<x;++i)
			unable[i][v]=true;
		for(int i=y+1;i<=N;++i)
			unable[i][v]=true;
	}

	adjacent_list=(int **)malloc((N+1)*sizeof(int *));
	adjacent_list_count=(int *)calloc(N+1,sizeof(int));

	for(int n=1;n<=N;++n)
	{
		if(!min[n])
			min[n]=1;
		if(!max[n])
			max[n]=N;

		for(int i=min[n];i<=max[n];++i)
			adjacent_list_count[n]+=!unable[n][i];

		adjacent_list[n]=(int *)malloc(adjacent_list_count[n]*sizeof(int));
		adjacent_list_count[n]=0;

		for(int i=min[n];i<=max[n];++i)
			if(!unable[n][i])
				adjacent_list[n][adjacent_list_count[n]++]=i;
		free(unable[n]);
	}
	free(min);
	free(max);
	free(unable);

	occupied=(int *)calloc(N+1,sizeof(int));
	visited=(bool *)malloc((N+1)*sizeof(bool));
	for(int n=1;n<=N;++n)
	{
		memset(visited,0,N+1);
		count+=dfs(n);
	}

	if(count!=N)
		printf("-1");
	else
	{
		matched=(int *)malloc((N+1)*sizeof(int));
		for(int n=1;n<=N;++n)
			matched[occupied[n]]=n;
		for(int n=1;n<=N;++n)
			printf("%d ", matched[n]);
		free(matched);
	}

	for(int n=1;n<=N;++n)
		free(adjacent_list[n]);
	free(adjacent_list);
	free(adjacent_list_count);
	free(occupied);
	free(visited);
	return 0;
}