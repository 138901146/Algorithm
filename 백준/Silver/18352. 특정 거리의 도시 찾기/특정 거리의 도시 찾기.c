#include<stdio.h>
#include<malloc.h>

#define INF 123456789

typedef struct
{
	int A, B;
}
edge;

typedef struct
{
	int id, value;
}
vertex;

int size=1;
vertex *pq=NULL;

vertex get(void)
{
	int index=1;

	pq[0]=pq[1];
	pq[1]=pq[--size];

	while(index<size)
	{
		int left=index<<1, right=left|1, next=right<size?pq[left].value<pq[right].value?left:right:right==size?left:index;

		if(pq[index].value<=pq[next].value)
			break;

		vertex temp=pq[index];
		pq[index]=pq[next];
		pq[next]=temp;
		index=next;
	}

	return pq[0];
}

void add(vertex node)
{
	int index=size;

	pq[size++]=node;

	while(1<index)
	{
		int next=index>>1;

		if(pq[next].value<=pq[index].value)
			break;

		pq[0]=pq[index];
		pq[index]=pq[next];
		pq[next]=pq[0];
		index=next;
	}
}

int main(void)
{
	int N, M, K, X, **adjacent_list=NULL, *adjacent_list_count=NULL, count=0;
	edge *road=NULL;
	vertex *distance=NULL;

	scanf("%d%d%d%d", &N, &M, &K, &X);
	distance=(vertex *)malloc((N+1)*sizeof(vertex));
	road=(edge *)malloc(M*sizeof(edge));
	adjacent_list=(int **)malloc((N+1)*sizeof(int *));
	adjacent_list_count=(int *)calloc(N+1,sizeof(int));

	for(int m=0;m<M;++m)
	{
		scanf("%d%d", &road[m].A, &road[m].B);
		++adjacent_list_count[road[m].A];
	}

	for(int n=1;n<=N;++n)
	{
		adjacent_list[n]=(int *)malloc(adjacent_list_count[n]*sizeof(int));
		adjacent_list_count[n]=0;
		distance[n].id=n;
		distance[n].value=INF;
	}
	distance[X].value=0;

	for(int m=0;m<M;++m)
		adjacent_list[road[m].A][adjacent_list_count[road[m].A]++]=road[m].B;
	free(road);
	pq=(vertex *)malloc(N*20*sizeof(vertex));

	add(distance[X]);

	while(1<size)
	{
		vertex current=get();

		if(current.value!=distance[current.id].value)
			continue;

		for(int i=0;i<adjacent_list_count[current.id];++i)
		{
			int next=adjacent_list[current.id][i];

			if(current.value+1<distance[next].value)
			{
				distance[next].value=current.value+1;
				add(distance[next]);
			}
		}
	}

	for(int n=1;n<=N;++n)
		if(distance[n].value==K)
		{
			printf("%d\n", n);
			++count;
		}
	if(!count)
		printf("-1");
	while(N)
		free(adjacent_list[N--]);
	free(adjacent_list);
	free(adjacent_list_count);
	free(distance);
	free(pq);
	return 0;
}