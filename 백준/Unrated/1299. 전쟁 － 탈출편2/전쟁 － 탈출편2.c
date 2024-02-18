#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

#define INF 2147483647

typedef struct
{
	int a, b, c;
	bool blocked;
}
edge;

typedef struct
{
	int country, time;
}
node;

int size=1, *pq_index=NULL;
node *pq=NULL;

node get(void)
{
	int index=1;

	pq[0]=pq[1];
	pq_index[pq[1].country]=size-1;

	pq[1]=pq[--size];
	pq[size]=pq[0];
	pq_index[pq[1].country]=1;

	while(index<size)
	{
		int left=index<<1, right=left|1, next=right<size?pq[left].time<pq[right].time?left:right:right==size?left:index;

		if(pq[index].time<=pq[next].time)
			break;

		int swap_index=pq_index[pq[index].country];
		pq_index[pq[index].country]=pq_index[pq[next].country];
		pq_index[pq[next].country]=swap_index;
		node swap_node=pq[index];
		pq[index]=pq[next];
		pq[next]=swap_node;
		index=next;
	}

	return pq[0];
}

void add(node value)
{
	int index=pq_index[value.country];

	pq[index]=value;

	if(index>=size)
	{
		int swap_index=pq[size].country;
		pq_index[pq[size].country]=index;
		pq_index[value.country]=size;
		node swap_node=pq[index];
		pq[index]=pq[size];
		pq[size]=swap_node;
		index=size++;
	}

	while(index>1)
	{
		int next=index>>1;

		if(pq[next].time<=pq[index].time)
			break;

		int swap_index=pq_index[pq[index].country];
		pq_index[pq[index].country]=pq_index[pq[next].country];
		pq_index[pq[next].country]=swap_index;
		node swap_node=pq[index];
		pq[index]=pq[next];
		pq[next]=swap_node;
		index=next;
	}
}

int main(void)
{
	int N, M, **adjacent_list=NULL, *count=NULL, *previous=NULL, target;
	node *min=NULL;
	edge *route=NULL;

	scanf("%d%d", &N, &M);
	route=(edge *)malloc(M*sizeof(edge));
	adjacent_list=(int **)malloc((N+1)*sizeof(int *));
	count=(int *)calloc(N+1,sizeof(int));
	min=(node *)malloc((N+1)*sizeof(node));
	previous=(int *)malloc((N+1)*sizeof(int));
	pq=(node *)malloc((N+1)*sizeof(node));
	pq_index=(int *)malloc((N+1)*sizeof(int));

	for(int m=0;m<M;++m)
	{
		scanf("%d%d%d", &route[m].a, &route[m].b, &route[m].c);
		++count[route[m].a];
		++count[route[m].b];
		route[m].blocked=false;
	}

	for(int n=1;n<=N;++n)
	{
		adjacent_list[n]=(int *)malloc(count[n]*sizeof(int));
		count[n]=0;
		pq[n].country=pq_index[n]=min[n].country=n;
		pq[n].time=min[n].time=INF;
	}

	for(int m=0;m<M;++m)
	{
		adjacent_list[route[m].a][count[route[m].a]++]=m;
		adjacent_list[route[m].b][count[route[m].b]++]=m;
	}

	min[1].time=0;
	add(min[1]);

	while(1<size)
	{
		node current=get();

		for(int i=0;i<count[current.country];++i)
		{
			int index=adjacent_list[current.country][i];
			target=route[index].a==current.country?route[index].b:route[index].a;

			if(current.time+route[index].c<min[target].time)
			{
				min[target].time=current.time+route[index].c;
				previous[target]=index;
				add(min[target]);
			}
		}
	}

	target=N;
	while(target!=1)
	{
		int index=previous[target];
		route[index].blocked=true;
		target=route[index].a==target?route[index].b:route[index].a;
	}

	for(int n=2;n<=N;++n)
		min[n].time=INF;
	add(min[1]);

	while(1<size)
	{
		node current=get();

		for(int i=0;i<count[current.country];++i)
		{
			int index=adjacent_list[current.country][i];

			if(route[index].blocked)
				continue;

			target=route[index].a==current.country?route[index].b:route[index].a;

			if(current.time+route[index].c<min[target].time)
			{
				min[target].time=current.time+route[index].c;
				previous[target]=index;
				add(min[target]);
			}
		}
	}

	printf("%d", min[N].time);
	for(int n=1;n<=N;++n)
		free(adjacent_list[n]);
	free(route);
	free(adjacent_list);
	free(count);
	free(min);
	free(previous);
	free(pq);
	free(pq_index);
	return 0;
}