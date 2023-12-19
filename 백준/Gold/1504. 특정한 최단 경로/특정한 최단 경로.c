#include<stdio.h>
#include<malloc.h>

typedef struct
{
	int index, distance;
}
node;

typedef struct
{
	int a, b, c;
}
edge;

int N, size, *adjacent_list_count=NULL, pq_size;
node **adjacent_list=NULL, *min_distance=NULL, *pq=NULL;

node get(void)
{
	int index=1;

	pq[0]=pq[1];
	pq[1]=pq[--size];

	while(index<size)
	{
		int left=index<<1, right=left|1, next=right<size?pq[left].distance<pq[right].distance?left:right:right==size?left:index;

		if(pq[index].distance<=pq[next].distance)
			break;

		node temp=pq[index];
		pq[index]=pq[next];
		pq[next]=temp;
		index=next;
	}

	return pq[0];
}

void add(node value)
{
	int index=size;

	if(size==pq_size)
	{
		pq_size<<=1;
		realloc(pq,pq_size*sizeof(node));
	}

	pq[size++]=value;

	while(index>1)
	{
		int next=index>>1;

		if(pq[index].distance>=pq[next].distance)
			break;

		pq[0]=pq[index];
		pq[index]=pq[next];
		pq[next]=pq[0];
		index=next;
	}
}

void dijkstra(int root)
{
	for(int n=1;n<=N;++n)
		min_distance[n].distance=100000000;

	min_distance[root].distance=0;
	pq[1]=min_distance[root];
	size=2;

	while(size>1)
	{
		node temp=get();

		for(int i=0;i<adjacent_list_count[temp.index];++i)
		{
			int next=adjacent_list[temp.index][i].index;

			if(temp.distance+adjacent_list[temp.index][i].distance<min_distance[next].distance)
			{
				min_distance[next].distance=temp.distance+adjacent_list[temp.index][i].distance;
				add(min_distance[next]);
			}
		}
	}
}

int main(void)
{
	int E, v[2], res[2]={0};
	edge *edge_list=NULL;

	scanf("%d%d", &N, &E);
	adjacent_list_count=(int *)calloc(N+1,sizeof(int));
	adjacent_list=(node **)malloc((N+1)*sizeof(node *));
	edge_list=(edge *)malloc(E*sizeof(edge));
	min_distance=(node *)malloc((N+1)*sizeof(node));

	for(int e=0;e<E;++e)
	{
		scanf("%d%d%d", &edge_list[e].a, &edge_list[e].b, &edge_list[e].c);
		++adjacent_list_count[edge_list[e].a];
		++adjacent_list_count[edge_list[e].b];
	}

	for(int n=1;n<=N;++n)
	{
		adjacent_list[n]=(node *)malloc(adjacent_list_count[n]*sizeof(node));
		adjacent_list_count[n]=0;
		min_distance[n].index=n;
	}

	for(int e=0;e<E;++e)
	{
		adjacent_list[edge_list[e].a][adjacent_list_count[edge_list[e].a]].index=edge_list[e].b;
		adjacent_list[edge_list[e].b][adjacent_list_count[edge_list[e].b]].index=edge_list[e].a;
		adjacent_list[edge_list[e].a][adjacent_list_count[edge_list[e].a]++].distance=adjacent_list[edge_list[e].b][adjacent_list_count[edge_list[e].b]++].distance=edge_list[e].c;
	}
	free(edge_list);

	pq_size=N;
	pq=(node *)malloc(pq_size*sizeof(node));
	scanf("%d%d", &v[0], &v[1]);

	dijkstra(1);
	res[0]+=min_distance[v[0]].distance;
	res[1]+=min_distance[v[1]].distance;

	dijkstra(v[0]);
	res[0]+=min_distance[v[1]].distance;
	res[1]+=min_distance[N].distance;

	dijkstra(v[1]);
	res[1]+=min_distance[v[0]].distance;
	res[0]+=min_distance[N].distance;

	res[0]=res[0]<res[1]?res[0]:res[1];
	printf("%d", res[0]>=100000000?-1:res[0]);
	for(int n=1;n<=N;++n)
		free(adjacent_list[n]);
	free(adjacent_list);
	free(adjacent_list_count);
	free(min_distance);
	free(pq);
	return 0;
}