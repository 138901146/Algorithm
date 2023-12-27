#include<stdio.h>
#include<malloc.h>

typedef struct
{
	int vertex, weight;
}
node;

typedef struct
{
	int from, to, cost;
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
	int N, M, A, B, *adjacent_list_count=NULL, *shortest_path=NULL;
	node **adjacent_list=NULL;
	edge *edges=NULL;

	scanf("%d", &N);
	scanf("%d", &M);
	adjacent_list=(node **)malloc((N+1)*sizeof(node *));
	adjacent_list_count=(int *)calloc(N+1,sizeof(int));
	edges=(edge *)malloc(M*sizeof(edge));

	for(int m=0;m<M;++m)
	{
		scanf("%d%d%d", &edges[m].from, &edges[m].to, &edges[m].cost);
		++adjacent_list_count[edges[m].from];
	}

	for(int n=1;n<=N;++n)
	{
		adjacent_list[n]=(node *)malloc(adjacent_list_count[n]*sizeof(node));
		adjacent_list_count[n]=0;
	}

	for(int m=0;m<M;++m)
	{
		adjacent_list[edges[m].from][adjacent_list_count[edges[m].from]].vertex=edges[m].to;
		adjacent_list[edges[m].from][adjacent_list_count[edges[m].from]++].weight=edges[m].cost;
	}
	free(edges);

	scanf("%d%d", &A, &B);
	shortest_path=(int *)malloc((N+1)*sizeof(int));
	pq_index=(int *)malloc((N+1)*sizeof(int));
	pq=(node *)malloc((N+1)*sizeof(node));
	for(int n=1;n<=N;++n)
	{
		pq[n].vertex=pq_index[n]=n;
		pq[n].weight=shortest_path[n]=INF;
	}
	pq[A].weight=shortest_path[A]=0;

	add(pq[A]);
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

	printf("%d", shortest_path[B]);
	while(N)
		free(adjacent_list[N--]);
	free(adjacent_list_count);
	free(adjacent_list);
	free(shortest_path);
	free(pq);
	free(pq_index);
	return 0;
}