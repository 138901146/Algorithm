#include<stdio.h>
#include<malloc.h>

int **parent=NULL, *child_count=NULL, **child=NULL, **distance=NULL, **adjacent_distance=NULL;

void make_tree(int current)
{
	for(int i=0;i<child_count[current];++i)
		if(child[current][i]!=1 && !parent[child[current][i]][0])
		{
			parent[child[current][i]][0]=current;
			distance[child[current][i]][0]=adjacent_distance[current][i];
			make_tree(child[current][i]);
		}
}

int main(void)
{
	int n, **edge=NULL, *energy=NULL;

	scanf("%d", &n);

	parent=(int **)malloc((n+1)*sizeof(int *));
	distance=(int **)malloc((n+1)*sizeof(int *));
	adjacent_distance=(int **)malloc((n+1)*sizeof(int *));
	child=(int **)malloc((n+1)*sizeof(int *));
	child_count=(int *)calloc(n+1,sizeof(int));
	edge=(int **)malloc((n-1)*sizeof(int *));
	energy=(int *)malloc((n+1)*sizeof(int));

	for(int i=1;i<=n;++i)
		scanf("%d", &energy[i]);

	for(int i=0;i<n-1;++i)
	{
		edge[i]=(int *)malloc(3*sizeof(int));

		for(int j=0;j<2;++j)
		{
			scanf("%d", &edge[i][j]);
			++child_count[edge[i][j]];
		}
		scanf("%d", &edge[i][2]);
	}

	for(int i=1;i<=n;++i)
	{
		parent[i]=(int *)calloc(18,sizeof(int));
		distance[i]=(int *)calloc(18,sizeof(int));
		child[i]=(int *)malloc(child_count[i]*sizeof(int));
		adjacent_distance[i]=(int *)malloc(child_count[i]*sizeof(int));
		child_count[i]=0;
	}

	for(int i=0;i<n-1;++i)
	{
		for(int j=0;j<2;++j)
		{
			child[edge[i][j]][child_count[edge[i][j]]]=edge[i][j^1];
			adjacent_distance[edge[i][j]][child_count[edge[i][j]]++]=edge[i][2];
		}
		free(edge[i]);
	}
	free(edge);

	make_tree(1);

	for(int j=0;j<17;++j)
		for(int i=2;i<=n;++i)
			if(parent[i][j])
			{
				parent[i][j+1]=parent[parent[i][j]][j];
				distance[i][j+1]=distance[i][j]+distance[parent[i][j]][j];
			}

	printf("1");
	for(int i=2;i<=n;++i)
	{
		int current=i;

		for(int j=17;j>=0;--j)
			if(parent[current][j] && distance[current][j]<=energy[i])
			{
				energy[i]-=distance[current][j];
				current=parent[current][j];
			}

		printf("\n%d", current);
	}

	while(n)
	{
		free(parent[n]);
		free(child[n]);
		free(distance[n]);
		free(adjacent_distance[n--]);
	}
	free(parent);
	free(child);
	free(child_count);
	free(distance);
	free(adjacent_distance);
	free(energy);
	return 0;
}