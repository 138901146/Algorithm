#include<stdio.h>
#include<malloc.h>

#define INF 1234567

typedef struct
{
	int vertex, weight;
}
node;

typedef struct
{
	int a, b, c;
}
edge;

node *pq=NULL;
int size=1, *pq_index=NULL;

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

	if(size<=index)
	{
		int swap_index=pq[size].vertex;
		pq_index[pq[size].vertex]=index;
		pq_index[value.vertex]=size;
		node swap_node=pq[index];
		pq[index]=pq[size];
		pq[size]=swap_node;
		index=size++;
	}

	while(1<index)
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
	int n, m, s, t, *adjacent_list_count=NULL, *shortest_path=NULL;
	node **adjacent_list=NULL;
	edge *edges=NULL;

	scanf("%d%d", &n, &m);
	adjacent_list=(node **)malloc((n+1)*sizeof(node *));
	adjacent_list_count=(int *)calloc(n+1,sizeof(int));
	edges=(edge *)malloc(m*sizeof(edge));

	for(int i=0;i<m;++i)
	{
		scanf("%d%d%d", &edges[i].a, &edges[i].b, &edges[i].c);
		++adjacent_list_count[edges[i].a];
		++adjacent_list_count[edges[i].b];
	}

	scanf("%d%d", &s, &t);

	for(int i=1;i<=n;++i)
	{
		adjacent_list[i]=(node *)malloc(adjacent_list_count[i]*sizeof(node));
		adjacent_list_count[i]=0;
	}

	for(int i=0;i<m;++i)
	{
		adjacent_list[edges[i].a][adjacent_list_count[edges[i].a]].vertex=edges[i].b;
		adjacent_list[edges[i].b][adjacent_list_count[edges[i].b]].vertex=edges[i].a;
		adjacent_list[edges[i].a][adjacent_list_count[edges[i].a]++].weight=adjacent_list[edges[i].b][adjacent_list_count[edges[i].b]++].weight=edges[i].c;
	}
	free(edges);

	shortest_path=(int *)malloc((n+1)*sizeof(int));
	pq_index=(int *)malloc((n+1)*sizeof(int));
	pq=(node *)malloc((n+1)*sizeof(node));
	for(int i=1;i<=n;++i)
	{
		pq[i].vertex=pq_index[i]=i;
		pq[i].weight=shortest_path[i]=INF;
	}
	pq[s].weight=shortest_path[s]=0;

	add(pq[s]);
	while(1<size)
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

	printf("%d", shortest_path[t]);
	while(n)
		free(adjacent_list[n--]);
	free(adjacent_list_count);
	free(adjacent_list);
	free(shortest_path);
	free(pq);
	free(pq_index);
	return 0;
}