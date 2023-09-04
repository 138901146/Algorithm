#include<stdio.h>
#include<malloc.h>

int **parent=NULL, *child_count=NULL, **child=NULL, *depth=NULL, **shortest=NULL, **longest=NULL, **adjacent_distance=NULL;

void make_tree(int current)
{
	for(int i=0;i<child_count[current];++i)
		if(child[current][i]!=1 && !parent[child[current][i]][0])
		{
			parent[child[current][i]][0]=current;
			depth[child[current][i]]=depth[current]+1;
			shortest[child[current][i]][0]=longest[child[current][i]][0]=adjacent_distance[current][i];
			make_tree(child[current][i]);
		}
}

int main(void)
{
	int N, M, **edge=NULL, x, y, min, max;

	scanf("%d", &N);

	parent=(int **)malloc((N+1)*sizeof(int *));
	shortest=(int **)malloc((N+1)*sizeof(int *));
	longest=(int **)malloc((N+1)*sizeof(int *));
	adjacent_distance=(int **)malloc((N+1)*sizeof(int *));
	child=(int **)malloc((N+1)*sizeof(int *));
	child_count=(int *)calloc(N+1,sizeof(int));
	edge=(int **)malloc((N-1)*sizeof(int *));
	depth=(int *)malloc((N+1)*sizeof(int));

	for(int n=0;n<N-1;++n)
	{
		edge[n]=(int *)malloc(3*sizeof(int));

		for(int i=0;i<2;++i)
		{
			scanf("%d", &edge[n][i]);
			++child_count[edge[n][i]];
		}
		scanf("%d", &edge[n][2]);
	}

	for(int n=1;n<=N;++n)
	{
		parent[n]=(int *)calloc(18,sizeof(int));
		shortest[n]=(int *)calloc(18,sizeof(int));
		longest[n]=(int *)calloc(18,sizeof(int));
		child[n]=(int *)malloc(child_count[n]*sizeof(int));
		adjacent_distance[n]=(int *)malloc(child_count[n]*sizeof(int));
		child_count[n]=0;
	}

	for(int n=0;n<N-1;++n)
	{
		for(int i=0;i<2;++i)
		{
			child[edge[n][i]][child_count[edge[n][i]]]=edge[n][i^1];
			adjacent_distance[edge[n][i]][child_count[edge[n][i]]++]=edge[n][2];
		}
		free(edge[n]);
	}
	free(edge);

	depth[1]=0;
	make_tree(1);

	for(int i=0;i<17;++i)
		for(int n=2;n<=N;++n)
			if(parent[n][i])
			{
				parent[n][i+1]=parent[parent[n][i]][i];
				shortest[n][i+1]=shortest[n][i]<shortest[parent[n][i]][i]?shortest[n][i]:shortest[parent[n][i]][i];
				longest[n][i+1]=longest[n][i]>longest[parent[n][i]][i]?longest[n][i]:longest[parent[n][i]][i];
			}

	scanf("%d", &M);

	while(M--)
	{
		min=1000000;
		max=0;
		scanf("%d%d", &x, &y);

		if(depth[x]<depth[y])
		{
			int temp=x;
			x=y;
			y=temp;
		}

		int diff=depth[x]-depth[y];

		for(int i=0;diff;++i, diff>>=1)
			if(diff&1)
			{
				min=shortest[x][i]<min?shortest[x][i]:min;
				max=longest[x][i]>max?longest[x][i]:max;
				x=parent[x][i];
			}

		if(x!=y)
			for(int i=17;i>=0;--i)
				if(parent[x][i]!=parent[y][i] && parent[x][i])
				{
					min=shortest[x][i]<min?shortest[x][i]:min;
					max=longest[x][i]>max?longest[x][i]:max;
					min=shortest[y][i]<min?shortest[y][i]:min;
					max=longest[y][i]>max?longest[y][i]:max;
					x=parent[x][i];
					y=parent[y][i];
				}

		if(x!=y)
		{
			min=shortest[x][0]<min?shortest[x][0]:min;
			max=longest[x][0]>max?longest[x][0]:max;
			min=shortest[y][0]<min?shortest[y][0]:min;
			max=longest[y][0]>max?longest[y][0]:max;
		}

		printf("%d %d\n", min, max);
	}

	while(N)
	{
		free(parent[N]);
		free(child[N]);
		free(shortest[N]);
		free(longest[N]);
		free(adjacent_distance[N--]);
	}
	free(parent);
	free(child);
	free(child_count);
	free(depth);
	free(shortest);
	free(longest);
	free(adjacent_distance);
	return 0;
}