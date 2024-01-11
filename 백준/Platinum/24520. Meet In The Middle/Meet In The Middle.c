#include<stdio.h>
#include<malloc.h>

typedef struct
{
	int u, v, w;
}
edge;

int **parent=NULL, *child_count=NULL, **child=NULL, *depth=NULL;
long long *distance=NULL, **adjacent_distance=NULL;

void make_tree(int current)
{
	for(int i=0;i<child_count[current];++i)
		if(child[current][i]!=1 && !parent[child[current][i]][0])
		{
			parent[child[current][i]][0]=current;
			depth[child[current][i]]=depth[current]+1;
			distance[child[current][i]]=distance[current]+adjacent_distance[current][i];
			make_tree(child[current][i]);
		}
}

int main(void)
{
	int N, K;
	edge *road=NULL;

	scanf("%d%d", &N, &K);

	parent=(int **)malloc((N+1)*sizeof(int *));
	distance=(long long *)malloc((N+1)*sizeof(long long));
	adjacent_distance=(long long **)malloc((N+1)*sizeof(long long *));
	child=(int **)malloc((N+1)*sizeof(int *));
	child_count=(int *)calloc(N+1,sizeof(int));
	road=(edge *)malloc((N-1)*sizeof(edge));
	depth=(int *)malloc((N+1)*sizeof(int));

	for(int n=0;n<N-1;++n)
	{
		scanf("%d%d%d", &road[n].u, &road[n].v, &road[n].w);
		++child_count[road[n].u];
		++child_count[road[n].v];
	}

	for(int n=1;n<=N;++n)
	{
		parent[n]=(int *)calloc(18,sizeof(int));
		child[n]=(int *)malloc(child_count[n]*sizeof(int));
		adjacent_distance[n]=(long long *)malloc(child_count[n]*sizeof(long long));
		child_count[n]=0;
	}

	for(int n=0;n<N-1;++n)
	{
		child[road[n].u][child_count[road[n].u]]=road[n].v;
		adjacent_distance[road[n].u][child_count[road[n].u]++]=road[n].w;
		child[road[n].v][child_count[road[n].v]]=road[n].u;
		adjacent_distance[road[n].v][child_count[road[n].v]++]=road[n].w;
	}
	free(road);

	depth[1]=distance[1]=0;
	make_tree(1);

	for(int i=0;i<17;++i)
		for(int n=2;n<=N;++n)
			if(parent[n][i])
				parent[n][i+1]=parent[parent[n][i]][i];

	while(K--)
	{
		int u, v, LCA, x, y, left=0, right=17, found=0;

		scanf("%d%d", &u, &v);

		if(distance[u]+distance[v]&1)
		{
			printf("-1\n");
			continue;
		}

		if(depth[u]<depth[v])
		{
			x=v;
			y=u;
		}
		else
		{
			x=u;
			y=v;
		}

		for(int i=0, diff=depth[x]-depth[y];diff;++i, diff>>=1)
			if(diff&1)
				x=parent[x][i];

		if(x!=y)
			for(int i=17;i>=0;--i)
				if(parent[x][i]!=parent[y][i] && parent[x][i])
				{
					x=parent[x][i];
					y=parent[y][i];
				}

		LCA=x==y?x:parent[x][0];

		if(distance[u]==distance[v])
		{
			printf("%d\n", LCA);
			continue;
		}

		x=distance[u]<distance[v]?v:u;
		long long cost=(distance[u]+distance[v]>>1)-distance[LCA];

		while(left<=right)
		{
			int mid=left+right>>1;

			if(!parent[x][mid])
			{
				right=mid-1;
				continue;
			}

			long long temp=distance[x]-distance[parent[x][mid]];

			if(cost==temp)
			{
				x=parent[x][mid];
				found=1;
				break;
			}
			else if(cost>temp)
			{
				x=parent[x][mid];
				cost-=temp;
			}
			else
				right=mid-1;
		}

		printf("%d\n", found?x:-1);
	}

	for(int n=N;n;--n)
	{
		free(parent[n]);
		free(child[n]);
		free(adjacent_distance[n]);
	}
	free(parent);
	free(child);
	free(child_count);
	free(depth);
	free(distance);
	free(adjacent_distance);
	return 0;
}