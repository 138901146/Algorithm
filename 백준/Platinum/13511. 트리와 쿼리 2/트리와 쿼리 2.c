#include<stdio.h>
#include<malloc.h>

int **parent=NULL, *child_count=NULL, **child=NULL, *depth=NULL;
long long **cost=NULL, **adjacent_cost=NULL;

void make_tree(int current)
{
	for(int i=0;i<child_count[current];++i)
		if(child[current][i]!=1 && !parent[child[current][i]][0])
		{
			parent[child[current][i]][0]=current;
			depth[child[current][i]]=depth[current]+1;
			cost[child[current][i]][0]=adjacent_cost[current][i];
			make_tree(child[current][i]);
		}
}

int main(void)
{
	int N, M, **edge=NULL, operation, k, x, y, u, v, LCA;
	long long total_cost;

	scanf("%d", &N);

	parent=(int **)malloc((N+1)*sizeof(int *));
	cost=(long long **)malloc((N+1)*sizeof(long long *));
	adjacent_cost=(long long **)malloc((N+1)*sizeof(long long *));
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
		cost[n]=(long long *)calloc(18,sizeof(long long));
		child[n]=(int *)malloc(child_count[n]*sizeof(int));
		adjacent_cost[n]=(long long *)malloc(child_count[n]*sizeof(long long));
		child_count[n]=0;
	}

	for(int n=0;n<N-1;++n)
	{
		for(int i=0;i<2;++i)
		{
			child[edge[n][i]][child_count[edge[n][i]]]=edge[n][i^1];
			adjacent_cost[edge[n][i]][child_count[edge[n][i]]++]=edge[n][2];
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
				cost[n][i+1]=cost[n][i]+cost[parent[n][i]][i];
			}

	scanf("%d", &M);

	while(M--)
	{
		total_cost=0;
		scanf("%d%d%d", &operation, &u, &v);
		x=u;
		y=v;

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
				total_cost+=cost[x][i];
				x=parent[x][i];
			}

		if(x!=y)
			for(int i=17;i>=0;--i)
				if(parent[x][i]!=parent[y][i] && parent[x][i])
				{
					total_cost+=cost[x][i]+cost[y][i];
					x=parent[x][i];
					y=parent[y][i];
				}

		if(x==y)
			LCA=x;
		else
		{
			LCA=parent[x][0];
			total_cost+=cost[x][0]+cost[y][0];
		}

		if(operation==1)
			printf("%lld\n", total_cost);
		else
		{
			scanf("%d", &k);
			--k;

			if(depth[u]-depth[LCA]>=k)
			{
				for(int i=0;k;++i, k>>=1)
					if(k&1)
						u=parent[u][i];
				printf("%d\n", u);
			}
			else
			{
				k=depth[u]+depth[v]-(depth[LCA]<<1)-k;
				for(int i=0;k;++i, k>>=1)
					if(k&1)
						v=parent[v][i];
				printf("%d\n", v);
			}
		}
	}

	while(N)
	{
		free(parent[N]);
		free(child[N]);
		free(cost[N]);
		free(adjacent_cost[N--]);
	}
	free(parent);
	free(child);
	free(child_count);
	free(depth);
	free(cost);
	free(adjacent_cost);
	return 0;
}