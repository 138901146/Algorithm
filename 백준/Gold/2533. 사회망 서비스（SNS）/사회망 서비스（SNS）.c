#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

int **friend=NULL, *friend_count=NULL, **min=NULL;
bool *visited=NULL;

void find_min(int current)
{
	min[current]=(int *)malloc(2*sizeof(int));
	for(int i=0;i<2;++i)
		min[current][i]=i;

	for(int i=0;i<friend_count[current];++i)
	{
		int next=friend[current][i];

		if(!visited[next])
		{
			visited[next]=true;
			find_min(next);

			min[current][0]+=min[next][1];
			min[current][1]+=min[next][0]<min[next][1]?min[next][0]:min[next][1];
		}
	}
}

int main(void)
{
	int N, **edge=NULL;

	scanf("%d", &N);
	edge=(int **)malloc((N-1)*sizeof(int *));
	friend=(int **)malloc((N+1)*sizeof(int *));
	friend_count=(int *)calloc(N+1,sizeof(int));

	for(int i=0;i<N-1;++i)
	{
		edge[i]=(int *)malloc(2*sizeof(int));

		for(int j=0;j<2;++j)
		{
			scanf("%d", &edge[i][j]);
			++friend_count[edge[i][j]];
		}
	}

	for(int n=1;n<=N;++n)
	{
		friend[n]=(int *)malloc(friend_count[n]*sizeof(int));
		friend_count[n]=0;
	}

	for(int i=0;i<N-1;++i)
	{
		for(int j=0;j<2;++j)
			friend[edge[i][j]][friend_count[edge[i][j]]++]=edge[i][j^1];
		free(edge[i]);
	}
	free(edge);

	min=(int **)malloc((N+1)*sizeof(int *));
	visited=(bool *)calloc(N+1,sizeof(bool));
	visited[1]=true;
	find_min(1);

	printf("%d", min[1][0]<min[1][1]?min[1][0]:min[1][1]);
	while(N)
	{
		free(min[N]);
		free(friend[N--]);
	}
	free(min);
	free(friend);
	free(friend_count);
	free(visited);
	return 0;
}