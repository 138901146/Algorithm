#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
#include<memory.h>

int adjacent_list_count[101]={0}, **adjacent_list=NULL, *occupied=NULL;
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
	int learned_count, class, N, *needed=NULL, *fillable=NULL, **fill_list=NULL, total=0;
	bool learned[101]={0}, used[101]={0};

	scanf("%d", &learned_count);

	while(learned_count--)
	{
		scanf("%d", &class);
		learned[class]=true;
	}

	scanf("%d", &N);
	adjacent_list=(int **)malloc(101*sizeof(int *));
	needed=(int *)malloc(N*sizeof(int));
	fillable=(int *)malloc(N*sizeof(int));
	fill_list=(int **)malloc(N*sizeof(int *));

	for(int n=0;n<N;++n)
	{
		scanf("%d%d", &needed[n], &fillable[n]);

		total+=needed[n];
		fill_list[n]=(int *)malloc(fillable[n]*sizeof(int));

		for(int i=0;i<fillable[n];++i)
		{
			scanf("%d", &fill_list[n][i]);
			adjacent_list_count[fill_list[n][i]]+=needed[n];
		}
	}

	for(int i=1;i<101;++i)
	{
		adjacent_list[i]=(int *)malloc(adjacent_list_count[i]*sizeof(int));
		adjacent_list_count[i]=0;
	}

	total=0;
	for(int n=0;n<N;++n)
	{
		for(int i=0;i<fillable[n];++i)
			for(int j=0;j<needed[n];++j)
				adjacent_list[fill_list[n][i]][adjacent_list_count[fill_list[n][i]]++]=total+j;

		total+=needed[n];
	}

	while(N--)
		free(fill_list[N]);
	free(fill_list);
	free(fillable);
	free(needed);
	visited=(bool *)malloc(total*sizeof(bool));
	occupied=(int *)calloc(total,sizeof(int));

	class=0;
	for(int i=1;i<101;++i)
		if(learned[i])
		{
			memset(visited,0,total);
			if(dfs(i))
			{
				++class;
				used[i]=true;
			}
		}

	for(int i=1;i<101;++i)
		if(!learned[i])
		{
			memset(visited,0,total);
			if(dfs(i))
			{
				++class;
				used[i]=true;
			}
		}

	if(class<total)
		printf("-1");
	else
	{
		class=0;
		for(int i=1;i<101;++i)
			class+=used[i]&&!learned[i];

		printf("%d\n", class);
		for(int i=1;i<101;++i)
			if(used[i] && !learned[i])
				printf("%d ", i);
	}

	for(int i=1;i<101;++i)
		free(adjacent_list[i]);
	free(adjacent_list);
	free(visited);
	free(occupied);
	return 0;
}