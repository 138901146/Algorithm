#include<stdio.h>
#include<malloc.h>

int *parent=NULL, *depth=NULL, **child=NULL, *child_count=NULL;

void find(int current)
{
	for(int i=0;i<child_count[current];i++)
		if(!parent[child[current][i]])
		{
			depth[child[current][i]]=depth[current]+1;
			parent[child[current][i]]=current;
			find(child[current][i]);
		}
}

int main(void)
{
	int N, M, **edge=NULL, v1, v2;

	scanf("%d", &N);
	edge=(int **)malloc((N-1)*sizeof(int *));
	child=(int **)malloc((N+1)*sizeof(int *));
	child_count=(int *)calloc(N+1,sizeof(int));

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

	parent=(int *)calloc(N+1,sizeof(int));
	depth=(int *)calloc(N+1,sizeof(int));
	parent[1]=1;
	find(1);

	scanf("%d", &M);
	while(M--)
	{
		scanf("%d%d", &v1, &v2);

		while(depth[v1]<depth[v2])
			v2=parent[v2];
		while(depth[v1]>depth[v2])
			v1=parent[v1];

		while(v1!=v2)
		{
			v1=parent[v1];
			v2=parent[v2];
		}

		printf("%d\n", v1);
	}

	for(int n=1;n<=N;n++)
		free(child[n]);
	free(child);
	free(child_count);
	free(parent);
	free(depth);
	return 0;
}