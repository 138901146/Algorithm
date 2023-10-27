#include<stdio.h>
#include<malloc.h>

typedef struct
{
	int destination, fee, roads;
}
node;

int size=1, distance[1001][1001];
node pq[2000000];

node get(void)
{
	int index=1;
	pq[0]=pq[1];
	pq[1]=pq[--size];

	while(index<size)
	{
		int left=index<<1, right=left|1, next=right<size?pq[left].fee<pq[right].fee?left:right:right==size?left:index;

		if(pq[index].fee<=pq[next].fee)
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

	while(index>1)
	{
		int next=index>>1;

		if(pq[index].fee>=pq[next].fee)
			break;

		node temp=pq[index];
		pq[index]=pq[next];
		pq[next]=temp;
		index=next;
	}
}

int main(void)
{
	int N, M, K, S, D, A, sum=0, *city_count=NULL, **road=NULL;
	long long min=1000000000;
	node **city=NULL;

	scanf("%d%d%d", &N, &M, &K);
	city=(node **)malloc((N+1)*sizeof(node *));
	city_count=(int *)calloc(N+1,sizeof(int));
	road=(int **)malloc(M*sizeof(int *));

	scanf("%d%d", &S, &D);

	for(int m=0;m<M;++m)
	{
		road[m]=(int *)malloc(3*sizeof(int));
		for(int i=0;i<2;++i)
		{
			scanf("%d", &road[m][i]);
			++city_count[road[m][i]];
		}
		scanf("%d", &road[m][2]);
	}

	for(int n=1;n<=N;++n)
	{
		city[n]=(node *)malloc(city_count[n]*sizeof(node));
		city_count[n]=0;
	}

	for(int m=0;m<M;++m)
	{
		for(int i=0;i<2;++i)
		{
			city[road[m][i]][city_count[road[m][i]]].destination=road[m][i^1];
			city[road[m][i]][city_count[road[m][i]]++].fee=road[m][2];
		}
		free(road[m]);
	}
	free(road);

	for(int n=1;n<=N;++n)
	{
		for(int i=0;i<1001;++i)
			distance[n][i]=1000000000;
		distance[S][n]=0;
	}
	distance[S][0]=0;

	node temp={S,0,0};
	pq[size++]=temp;

	while(size>1)
	{
		node next=get();

		for(int i=0;i<city_count[next.destination];++i)
			if(next.roads<1000 && distance[next.destination][next.roads]+city[next.destination][i].fee<distance[city[next.destination][i].destination][next.roads+1])
			{
				temp.destination=city[next.destination][i].destination;
				temp.fee=distance[next.destination][next.roads]+city[next.destination][i].fee;
				temp.roads=next.roads+1;
				distance[temp.destination][temp.roads]=temp.fee;
				add(temp);
			}
	}

	for(int i=0;i<1001;++i)
		if(distance[D][i]<1000000000)
			min=i*sum+distance[D][i]<min?i*sum+distance[D][i]:min;
	printf("%lld", min);
	while(K--)
	{
		scanf("%d", &A);
		sum+=A;
		min=1000000000;

		for(int i=0;i<1001;++i)
			if(distance[D][i]<1000000000)
				min=i*sum+distance[D][i]<min?i*sum+distance[D][i]:min;

		printf("\n%lld", min);
	}

	for(int n=1;n<=N;++n)
		free(city[n]);
	free(city);
	free(city_count);
	return 0;
}