#include<stdio.h>
#include<malloc.h>

#define INF 1050000000

typedef struct
{
	int id, distance;
}
node;

typedef struct
{
	int D, E, L;
}
edge;

node *pq=NULL;
int size;

node get(void)
{
	int index=1;

	pq[0]=pq[1];
	pq[1]=pq[--size];

	while(index<size)
	{
		int left=index<<1, right=left|1, next=right<size?pq[left].distance<pq[right].distance?left:right:left<size?left:index;

		if(pq[index].distance<=pq[next].distance)
			break;

		pq[size]=pq[index];
		pq[index]=pq[next];
		pq[next]=pq[size];
		index=next;
	}

	return pq[0];
}

void add(node data)
{
	int index=size;

	pq[size++]=data;

	while(1<index)
	{
		int next=index>>1;

		if(pq[next].distance<=pq[index].distance)
			break;

		pq[0]=pq[index];
		pq[index]=pq[next];
		pq[next]=pq[0];
		index=next;
	}
}

int main(void)
{
	int N, M, *adjacent_list_count=NULL, friend[3];
	node **min=NULL, **adjacent_list=NULL, far={0};
	edge *road=NULL;

	scanf("%d", &N);
	for(int i=0;i<3;++i)
		scanf("%d", &friend[i]);
	scanf("%d", &M);

	adjacent_list_count=(int *)calloc(N+1,sizeof(int));
	road=(edge *)malloc(M*sizeof(edge));

	for(int i=0;i<M;++i)
	{
		scanf("%d%d%d", &road[i].D, &road[i].E, &road[i].L);
		++adjacent_list_count[road[i].D];
		++adjacent_list_count[road[i].E];
	}

	adjacent_list=(node **)malloc((N+1)*sizeof(node *));

	for(int i=1;i<=N;++i)
	{
		adjacent_list[i]=(node *)malloc(adjacent_list_count[i]*sizeof(node));
		adjacent_list_count[i]=0;
	}

	for(int i=0;i<M;++i)
	{
		adjacent_list[road[i].D][adjacent_list_count[road[i].D]].id=road[i].E;
		adjacent_list[road[i].E][adjacent_list_count[road[i].E]].id=road[i].D;
		adjacent_list[road[i].D][adjacent_list_count[road[i].D]++].distance=adjacent_list[road[i].E][adjacent_list_count[road[i].E]++].distance=road[i].L;
	}

	free(road);
	min=(node **)malloc(3*sizeof(node *));
	pq=(node *)malloc(100*M*sizeof(node));

	for(int i=0;i<3;++i)
	{
		min[i]=(node *)calloc(N+1,sizeof(node));

		for(int j=1;j<=N;++j)
		{
			min[i][j].id=j;
			min[i][j].distance=INF;
		}

		size=1;
		min[i][friend[i]].distance=0;
		add(min[i][friend[i]]);

		while(1<size)
		{
			node current=get();

			if(current.distance!=min[i][current.id].distance)
				continue;

			for(int j=0;j<adjacent_list_count[current.id];++j)
			{
				node next=adjacent_list[current.id][j];

				if(current.distance+next.distance<min[i][next.id].distance)
				{
					min[i][next.id].distance=current.distance+next.distance;
					add(min[i][next.id]);
				}
			}
		}
	}

	for(int i=1;i<=N;++i)
	{
		node compare=min[0][i];

		for(int j=1;j<3;++j)
			compare=compare.distance<min[j][i].distance?compare:min[j][i];

		far=far.distance<compare.distance?compare:far;
	}

	printf("%d", far.id);
	for(int i=1;i<=N;++i)
	{
		free(adjacent_list[i]);
	}
	free(adjacent_list);
	free(adjacent_list_count);
	for(int i=0;i<3;++i)
		free(min[i]);
	free(min);
	free(pq);
	return 0;
}