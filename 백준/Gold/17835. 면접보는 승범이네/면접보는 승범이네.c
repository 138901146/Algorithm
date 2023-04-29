#include<stdio.h>
#include<malloc.h>

typedef struct
{
	int vertex;
	long long cost;
}
edge;

int size=1;
edge *pq=NULL;

edge get(void)
{
	int index=1, next, left, right;
	edge value=pq[1], temp;
	pq[1]=pq[--size];

	while(index<size)
	{
		left=index<<1;
		right=index<<1|1;
		next=size>right?pq[right].cost<pq[left].cost?right:left:size==right?left:index;
		if(index==next)
			break;
		else
		{
			if(pq[index].cost>pq[next].cost)
			{
				temp=pq[index];
				pq[index]=pq[next];
				pq[next]=temp;
				index=next;
			}
			else
				break;
		}
	}

	return value;
}

void add(edge value)
{
	int index=size, next;
	edge temp;
	pq[size++]=value;

	while(index>1)
	{
		next=index>>1;
		if(pq[index].cost<pq[next].cost)
		{
			temp=pq[index];
			pq[index]=pq[next];
			pq[next]=temp;
			index=next;
		}
		else
			break;
	}
}

int main(void)
{
	int N, K, M, interview, *road_count=NULL, max=0, **road=NULL;
	long long *distance=NULL;
	edge **city=NULL, temp;

	scanf("%d%d%d", &N, &M, &K);
	city=(edge **)malloc((N+1)*sizeof(edge *));
	distance=(long long *)malloc((N+1)*sizeof(long long));
	road=(int **)malloc(M*sizeof(int *));
	road_count=(int *)calloc(N+1,sizeof(int));

	for(int m=0;m<M;m++)
	{
		road[m]=(int *)malloc(3*sizeof(int));
		for(int i=0;i<3;i++)
			scanf("%d", &road[m][i]);
		road_count[road[m][1]]++;
	}

	for(int n=1;n<=N;n++)
	{
		city[n]=(edge *)malloc(road_count[n]*sizeof(edge));
		distance[n]=1000000000000000000;
		road_count[n]=0;
	}

	for(int m=0;m<M;m++)
	{
		city[road[m][1]][road_count[road[m][1]]].vertex=road[m][0];
		city[road[m][1]][road_count[road[m][1]]++].cost=road[m][2];
	}

	pq=(edge *)malloc(100*N*sizeof(edge));
	temp.cost=0;
	for(int k=0;k<K;k++)
	{
		scanf("%d", &interview);
		distance[interview]=0;
		temp.vertex=interview;
		pq[size++]=temp;
	}

	while(size>1)
	{
		edge next=get();

		if(next.cost==distance[next.vertex])
			for(int i=0;i<road_count[next.vertex];i++)
				if(distance[city[next.vertex][i].vertex]>distance[next.vertex]+city[next.vertex][i].cost)
				{
					temp.vertex=city[next.vertex][i].vertex;
					temp.cost=distance[next.vertex]+city[next.vertex][i].cost;
					distance[temp.vertex]=temp.cost;
					add(temp);
				}
	}

	distance[0]=0;
	for(int n=1;n<=N;n++)
		max=distance[n]>distance[max]?n:max;
	printf("%d\n%lld\n", max, distance[max]);
	return 0;
}