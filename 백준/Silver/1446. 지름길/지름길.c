#include<stdio.h>
#include<malloc.h>

typedef struct
{
	int source, destination, length;
}
edge;

typedef struct
{
	int id, length;
}
node;

node **adjacent_list=NULL, *pq=NULL;
int *adjacent_list_count=NULL, size=1;

void pop(void)
{
	int index=1;

	pq[1]=pq[--size];

	while(index<size)
	{
		int left=index<<1, right=left|1, next=right<size?pq[left].length<pq[right].length?left:right:left<size?left:index;

		if(pq[index].length<=pq[next].length)
			break;

		pq[0]=pq[index];
		pq[index]=pq[next];
		pq[next]=pq[0];
		index=next;
	}
}

void push(node target)
{
	int index=size;

	pq[size++]=target;

	while(1<index)
	{
		int next=index>>1;

		if(pq[next].length<=pq[index].length)
			break;

		pq[0]=pq[index];
		pq[index]=pq[next];
		pq[next]=pq[0];
		index=next;
	}
}

int main(void)
{
	int N, D;
	node *min=NULL;
	edge *road=NULL;

	scanf("%d%d", &N, &D);
	min=(node *)malloc(10001*sizeof(node));
	adjacent_list=(node **)malloc(10001*sizeof(node *));
	adjacent_list_count=(int *)calloc(10001,sizeof(int));
	road=(edge *)malloc(N*sizeof(edge));
	pq=(node *)malloc(120000*sizeof(node));

	for(int n=0;n<N;++n)
	{
		scanf("%d%d%d", &road[n].source, &road[n].destination, &road[n].length);
		++adjacent_list_count[road[n].source];
	}

	for(int d=0;d<10001;++d)
	{
		min[d].id=min[d].length=d;
		adjacent_list[d]=(node *)malloc((adjacent_list_count[d]+1)*sizeof(node));
		adjacent_list[d][0].id=d+1;
		adjacent_list[d][0].length=1;
		adjacent_list_count[d]=1;
	}
	min[D].id=min[D].length=D;

	min[0].length=0;
	push(min[0]);

	for(int n=0;n<N;++n)
	{
		adjacent_list[road[n].source][adjacent_list_count[road[n].source]].id=road[n].destination;
		adjacent_list[road[n].source][adjacent_list_count[road[n].source]++].length=road[n].length;
		push(min[road[n].source]);
	}

	free(road);

	while(1<size)
	{
		int current=pq[1].id, length=pq[1].length;

		pop();

		if(length!=min[current].length)
			continue;

		for(int i=0;i<adjacent_list_count[current];++i)
		{
			int next=adjacent_list[current][i].id;

			if(length+adjacent_list[current][i].length<min[next].length)
			{
				min[next].length=length+adjacent_list[current][i].length;
				push(min[next]);
			}
		}
	}

	printf("%d", min[D].length);
	for(int d=0;d<10001;++d)
		free(adjacent_list[d]);
	free(adjacent_list);
	free(adjacent_list_count);
	free(pq);
	free(min);
	return 0;
}