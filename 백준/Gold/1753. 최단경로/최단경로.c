#include<stdio.h>
#include<malloc.h>

typedef struct
{
	int vertex, weight;
}
node;

typedef struct
{
	int u, v, w;
}
edge;

node *pq=NULL;
int size=1, *pq_index=NULL, INF=1000000000;

node get(void)
{
	int index=1;

	pq[0]=pq[1];
	pq_index[pq[1].vertex]=size-1;

	pq[1]=pq[--size];
	pq[size]=pq[0];
	pq_index[pq[1].vertex]=1;

	while(index<size)
	{
		int left=index<<1, right=left|1, next=right<size?pq[left].weight<pq[right].weight?left:right:right==size?left:index;

		if(pq[index].weight<=pq[next].weight)
			break;

		int swap_index=pq_index[pq[index].vertex];
		pq_index[pq[index].vertex]=pq_index[pq[next].vertex];
		pq_index[pq[next].vertex]=swap_index;
		node swap_node=pq[index];
		pq[index]=pq[next];
		pq[next]=swap_node;
		index=next;
	}

	return pq[0];
}

void add(node value)
{
	int index=pq_index[value.vertex];

	pq[index]=value;

	if(index>=size)
	{
		int swap_index=pq[size].vertex;
		pq_index[pq[size].vertex]=index;
		pq_index[value.vertex]=size;
		node swap_node=pq[index];
		pq[index]=pq[size];
		pq[size]=swap_node;
		index=size++;
	}

	while(index>1)
	{
		int next=index>>1;

		if(pq[next].weight<=pq[index].weight)
			break;

		int swap_index=pq_index[pq[index].vertex];
		pq_index[pq[index].vertex]=pq_index[pq[next].vertex];
		pq_index[pq[next].vertex]=swap_index;
		node swap_node=pq[index];
		pq[index]=pq[next];
		pq[next]=swap_node;
		index=next;
	}
}

int main(void)
{
	int V, E, K, *adjacent_list_count=NULL, *shortest_path=NULL;
	node **adjacent_list=NULL;
	edge *edges=NULL;

	scanf("%d%d", &V, &E);
	scanf("%d", &K);
	adjacent_list=(node **)malloc((V+1)*sizeof(node *));
	adjacent_list_count=(int *)calloc(V+1,sizeof(int));
	edges=(edge *)malloc(E*sizeof(edge));

	for(int e=0;e<E;++e)
	{
		scanf("%d%d%d", &edges[e].u, &edges[e].v, &edges[e].w);
		++adjacent_list_count[edges[e].u];
	}

	for(int v=1;v<=V;++v)
	{
		adjacent_list[v]=(node *)malloc(adjacent_list_count[v]*sizeof(node));
		adjacent_list_count[v]=0;
	}

	for(int e=0;e<E;++e)
	{
		adjacent_list[edges[e].u][adjacent_list_count[edges[e].u]].vertex=edges[e].v;
		adjacent_list[edges[e].u][adjacent_list_count[edges[e].u]++].weight=edges[e].w;
	}
	free(edges);

	shortest_path=(int *)malloc((V+1)*sizeof(int));
	pq_index=(int *)malloc((V+1)*sizeof(int));
	pq=(node *)malloc((V+1)*sizeof(node));
	for(int v=1;v<=V;++v)
	{
		pq[v].vertex=pq_index[v]=v;
		pq[v].weight=shortest_path[v]=INF;
	}
	pq[K].weight=shortest_path[K]=0;

	add(pq[K]);
	while(size>1)
	{
		node current=get();

		for(int i=0;i<adjacent_list_count[current.vertex];++i)
		{
			node next=adjacent_list[current.vertex][i];

			if(current.weight+next.weight<shortest_path[next.vertex])
			{
				next.weight=shortest_path[next.vertex]=current.weight+next.weight;
				add(next);
			}
		}
	}

	for(int v=1;v<=V;++v)
	{
		if(shortest_path[v]==INF)
			printf("INF\n");
		else
			printf("%d\n", shortest_path[v]);
		free(adjacent_list[v]);
	}
	free(adjacent_list_count);
	free(adjacent_list);
	free(shortest_path);
	free(pq);
	free(pq_index);
	return 0;
}