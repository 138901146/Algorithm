#include<stdio.h>
#include<malloc.h>

int *parent=NULL, **child=NULL, *child_count=NULL;

void find_parent(int current)
{
	for(int i=0;i<child_count[current];i++)
		if(child[current][i]!=1 && !parent[child[current][i]])
		{
			parent[child[current][i]]=current;
			find_parent(child[current][i]);
		}
}

int main(void)
{
	int N, **edge=NULL;

	scanf("%d", &N);
	edge=(int **)malloc((N-1)*sizeof(int *));
	parent=(int *)calloc(N+1,sizeof(int));
	child_count=(int *)calloc(N+1,sizeof(int));
	child=(int **)malloc((N+1)*sizeof(int *));

	for(int n=0;n<N-1;n++)
	{
		edge[n]=(int *)malloc(2*sizeof(int));
		for(int i=0;i<2;i++)
		{
			scanf("%d", &edge[n][i]);
			child_count[edge[n][i]]++;
		}
	}

	for(int n=1;n<=N;n++)
	{
		child[n]=(int *)malloc(child_count[n]*sizeof(int));
		child_count[n]=0;
	}

	for(int n=0;n<N-1;n++)
	{
		child[edge[n][0]][child_count[edge[n][0]]++]=edge[n][1];
		child[edge[n][1]][child_count[edge[n][1]]++]=edge[n][0];
		free(edge[n]);
	}
	free(edge);

	find_parent(1);

	free(child[1]);
	for(int n=2;n<=N;n++)
	{
		printf("%d\n", parent[n]);
		free(child[n]);
	}
	free(child);
	free(parent);
	free(child_count);
	return 0;
}