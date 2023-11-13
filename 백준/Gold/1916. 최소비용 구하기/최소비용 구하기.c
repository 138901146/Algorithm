#include<stdio.h>
#include<malloc.h>

typedef struct
{
	int source, destination;
	long long fee;
}
bus;

bus *pq=NULL;
int size=2;

bus get(void)
{
	int index=1;
	pq[0]=pq[1];
	pq[1]=pq[--size];

	while(index<size)
	{
		int left=index<<1, right=left|1, next=right<size?pq[left].fee<pq[right].fee?left:right:right==size?left:index;

		if(pq[index].fee<=pq[next].fee)
			break;

		bus temp=pq[index];
		pq[index]=pq[next];
		pq[next]=temp;
		index=next;
	}

	return pq[0];
}

void add(bus value)
{
	int index=size;
	pq[size++]=value;

	while(index>1)
	{
		int next=index>>1;

		if(pq[index].fee>=pq[next].fee)
			break;

		pq[0]=pq[index];
		pq[index]=pq[next];
		pq[next]=pq[0];
		index=next;
	}
}

int main(void)
{
	int N, M, *vertex_count=NULL, departure, arrival;
	bus *edge=NULL, **vertex=NULL, *min=NULL;

	scanf("%d", &N);
	scanf("%d", &M);
	vertex=(bus **)malloc((N+1)*sizeof(bus *));
	vertex_count=(int *)calloc(N+1,sizeof(int));
	edge=(bus *)malloc(M*sizeof(bus));
	min=(bus *)malloc((N+1)*sizeof(bus));

	for(int m=0;m<M;++m)
	{
		scanf("%d%d%lld", &edge[m].source, &edge[m].destination, &edge[m].fee);
		++vertex_count[edge[m].source];
	}

	for(int n=1;n<=N;++n)
	{
		vertex[n]=(bus *)malloc(vertex_count[n]*sizeof(bus));
		vertex_count[n]=0;
		min[n].source=n;
		min[n].fee=100000000000;
	}

	for(int m=0;m<M;++m)
		vertex[edge[m].source][vertex_count[edge[m].source]++]=edge[m];
	free(edge);

	pq=(bus *)malloc(N*1001*sizeof(bus));
	scanf("%d%d", &departure, &arrival);
	min[departure].fee=0;
	pq[1]=min[departure];

	while(size>1)
	{
		bus current=get();

		if(current.fee!=min[current.source].fee)
			continue;

		for(int i=0;i<vertex_count[current.source];++i)
		{
			bus next=vertex[current.source][i];

			if(min[next.destination].fee>min[current.source].fee+next.fee)
			{
				min[next.destination].fee=min[next.source].fee+next.fee;
				add(min[next.destination]);
			}
		}
	}

	printf("%lld", min[arrival].fee);
	while(N)
		free(vertex[N--]);
	free(vertex);
	free(min);
	free(pq);
	free(vertex_count);
	return 0;
}