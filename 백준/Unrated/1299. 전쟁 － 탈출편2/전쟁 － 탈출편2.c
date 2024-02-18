#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

#define INF 1000000000

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

int size=1;
node pq[1000001];

node get(void)
{
	int index=1;

	pq[0]=pq[1];
	pq[1]=pq[--size];

	while(index<size)
	{
		int left=index<<1, right=left|1, next=right<size?pq[left].time<pq[right].time?left:right:right==size?left:index;

		if(pq[index].time<=pq[next].time)
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

	while(1<index)
	{
		int next=index>>1;

		if(pq[next].time<=pq[index].time)
			break;

		node temp=pq[index];
		pq[index]=pq[next];
		pq[next]=temp;
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
		min[n].country=n;
		min[n].time=INF;
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
	return 0;
}