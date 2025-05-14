#include<stdio.h>
#include<malloc.h>

#define INF 123456789

typedef struct
{
	int A, B, C;
}
edge;

typedef struct
{
	int id, cow;
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
		int left=index<<1, right=left|1, next=right<size?pq[left].cow<pq[right].cow?left:right:left<size?left:index;

		if(pq[index].cow<=pq[next].cow)
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

		if(pq[next].cow<=pq[index].cow)
			break;

		pq[0]=pq[index];
		pq[index]=pq[next];
		pq[next]=pq[0];
		index=next;
	}
}

int main(void)
{
	int N, M;
	node *min=NULL;
	edge *road=NULL;

	scanf("%d%d", &N, &M);
	min=(node *)malloc((N+1)*sizeof(node));
	adjacent_list=(node **)malloc((N+1)*sizeof(node *));
	adjacent_list_count=(int *)calloc(N+1,sizeof(int));
	road=(edge *)malloc(M*sizeof(edge));

	for(int m=0;m<M;++m)
	{
		scanf("%d%d%d", &road[m].A, &road[m].B, &road[m].C);
		++adjacent_list_count[road[m].A];
		++adjacent_list_count[road[m].B];
	}

	for(int n=1;n<=N;++n)
	{
		min[n].id=n;
		min[n].cow=INF;
		adjacent_list[n]=(node *)malloc(adjacent_list_count[n]*sizeof(node));
		adjacent_list_count[n]=0;
	}

	while(M--)
	{
		adjacent_list[road[M].A][adjacent_list_count[road[M].A]].id=road[M].B;
		adjacent_list[road[M].A][adjacent_list_count[road[M].A]++].cow=road[M].C;
		adjacent_list[road[M].B][adjacent_list_count[road[M].B]].id=road[M].A;
		adjacent_list[road[M].B][adjacent_list_count[road[M].B]++].cow=road[M].C;
	}

	free(road);
	pq=(node *)malloc(N*100*sizeof(node));

	min[1].cow=0;
	push(min[1]);

	while(1<size)
	{
		int current=pq[1].id, cow=pq[1].cow;

		pop();

		if(cow!=min[current].cow)
			continue;

		for(int i=0;i<adjacent_list_count[current];++i)
		{
			int next=adjacent_list[current][i].id;

			if(cow+adjacent_list[current][i].cow<min[next].cow)
			{
				min[next].cow=cow+adjacent_list[current][i].cow;
				push(min[next]);
			}
		}
	}

	printf("%d", min[N].cow);
	while(N)
		free(adjacent_list[N--]);
	free(adjacent_list);
	free(adjacent_list_count);
	free(pq);
	free(min);
	return 0;
}