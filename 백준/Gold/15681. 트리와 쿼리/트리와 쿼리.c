#include<stdio.h>
#include<malloc.h>

int R, **child=NULL, *child_count=NULL, *subtree_size=NULL;

int find_size(int current)
{
	subtree_size[current]=1;
	for(int i=0;i<child_count[current];i++)
		if(!subtree_size[child[current][i]])
		{
			find_size(child[current][i]);
			subtree_size[current]+=subtree_size[child[current][i]];
		}
}

int main(void)
{
	int N, Q, U, **edge=NULL;

	scanf("%d%d%d", &N, &R, &Q);
	child=(int **)malloc((N+1)*sizeof(int *));
	child_count=(int *)calloc(N+1,sizeof(int));
	edge=(int **)malloc((N-1)*sizeof(int *));

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

	subtree_size=(int *)calloc(N+1,sizeof(int));
	find_size(R);

	while(Q--)
	{
		scanf("%d", &U);
		printf("%d\n", subtree_size[U]);
	}

	for(int n=0;n<N;n++)
		free(child[n]);
	free(child);
	free(child_count);
	free(subtree_size);
	return 0;
}