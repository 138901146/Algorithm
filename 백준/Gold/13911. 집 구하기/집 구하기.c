#include<stdio.h>
#include<malloc.h>

#define INF 999999999

typedef struct
{
	int id, distance;
}
node;

typedef struct
{
	int u, v, w;
}
edge;

int size=1;
node *pq=NULL;

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

	pq[size++]=value;

	while(1<size)
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
	int V, E, M, x, S, y, *type=NULL, *count=NULL, point, min=INF;
	edge *road=NULL;
	node **adjacent_list=NULL, *mcdonald=NULL, *starbucks=NULL;

	scanf("%d%d", &V, &E);
	road=(edge *)malloc(E*sizeof(edge));
	count=(int *)calloc(V+1,sizeof(int));
	adjacent_list=(node **)malloc((V+1)*sizeof(node *));

	for(int e=0;e<E;++e)
	{
		scanf("%d%d%d", &road[e].u, &road[e].v, &road[e].w);
		++count[road[e].u];
		++count[road[e].v];
	}

	for(int v=1;v<=V;++v)
	{
		adjacent_list[v]=(node *)malloc(count[v]*sizeof(node));
		count[v]=0;
	}

	for(int e=0;e<E;++e)
	{
		adjacent_list[road[e].u][count[road[e].u]].id=road[e].v;
		adjacent_list[road[e].v][count[road[e].v]].id=road[e].u;
		adjacent_list[road[e].u][count[road[e].u]++].distance=adjacent_list[road[e].v][count[road[e].v]++].distance=road[e].w;
	}
	free(road);

	type=(int *)calloc(V+1,sizeof(int));
	mcdonald=(node *)malloc((V+1)*sizeof(node));
	starbucks=(node *)malloc((V+1)*sizeof(node));
	pq=(node *)malloc(25*V*sizeof(node));

	scanf("%d%d", &M, &x);
	while(M--)
	{
		scanf("%d", &point);
		type[point]=1;
	}

	scanf("%d%d", &S, &y);
	while(S--)
	{
		scanf("%d", &point);
		type[point]|=2;
	}

	for(int v=1;v<=V;++v)
	{
		mcdonald[v].id=starbucks[v].id=v;
		mcdonald[v].distance=starbucks[v].distance=INF;

		if(type[v]&1)
		{
			mcdonald[v].distance=0;
			pq[size++]=mcdonald[v];
		}
	}

	while(1<size)
	{
		node current=get();

		if(mcdonald[current.id].distance<current.distance)
			continue;

		for(int i=0;i<count[current.id];++i)
		{
			node next=adjacent_list[current.id][i];

			if(current.distance+next.distance<mcdonald[next.id].distance)
			{
				mcdonald[next.id].distance=current.distance+next.distance;
				add(mcdonald[next.id]);
			}
		}
	}

	size=1;
	for(int v=1;v<=V;++v)
		if(type[v]&2)
		{
			starbucks[v].distance=0;
			pq[size++]=starbucks[v];
		}

	while(1<size)
	{
		node current=get();

		if(starbucks[current.id].distance<current.distance)
			continue;

		for(int i=0;i<count[current.id];++i)
		{
			node next=adjacent_list[current.id][i];

			if(current.distance+next.distance<starbucks[next.id].distance)
			{
				starbucks[next.id].distance=current.distance+next.distance;
				add(starbucks[next.id]);
			}
		}
	}

	for(int v=1;v<=V;++v)
	{
		if(!type[v] && mcdonald[v].distance<=x && starbucks[v].distance<=y)
			min=mcdonald[v].distance+starbucks[v].distance<min?mcdonald[v].distance+starbucks[v].distance:min;
		free(adjacent_list[v]);
	}

	printf("%d", min==INF?-1:min);
	free(adjacent_list);
	free(mcdonald);
	free(starbucks);
	free(pq);
	free(count);
	free(type);
	return 0;
}